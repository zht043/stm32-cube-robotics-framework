import sys
import re
import os

from traverse import traverse

def parse_makefile(filename='Makefile'):
    buf = ''
    content = []
    with open(filename) as makefile:
        for line in makefile:
            line = line.rstrip()
            if line == '' or line.startswith('#'):
                continue
            if line.endswith('\\'):
                buf += line[:-1]
            else:
                buf += line
                content.append(buf)
                buf = ''

    env = {}
    content2 = []
    for line in content:
        line = line.rstrip()
        if ' =' in line:
            line = line.split(' =')
            env[line[0]] = line[1]
        elif ' +=' in line:
            line = line.split(' +=')
            env[line[0]] += line[1]
        else:
            content2.append(line)

    for k, v in env.items():
        env[k] = parenthesis_to_brace(v)

    return content


def generate_cmake(env):
    content = []
    target = env['TARGET'].strip()
    content.extend(['# CMAKE min version',
                    'cmake_minimum_required (VERSION 2.6)',
                    '# set project name',
                    'project (%s)' % target,
                    '# executable name',
                    'set(MY_TARGET %s)' % target])

    content.extend([''] * 2)

    # Building args
    content.extend(['######################################',
                    '# building args', 
                    '######################################',
                    '# debug build',
                    'set(DEBUG  "%s")' % env['DEBUG'].strip(),
                    '# optimization',
                    'set(OPT  "%s")' % env['OPT'].strip(),
                    'set(CMAKE_VERBOSE_MAKEFILE ON)'])

    content.extend([''] * 3)

    content.extend(['######################################',
                    '# enable assembly', 
                    '######################################',
                    'ENABLE_LANGUAGE(ASM)'])
    
    content.extend([''])

    content.extend(['# setup target platform',
                    'set(CMAKE_SYSTEM_NAME Generic)',
                    'set(CMAKE_SYSTEM_PROCESSOR arm)'])

    content.extend([''] * 2)

    cc_prefix = env['PREFIX'].strip()
    content.extend(['# setup cross compiler (assume binaries are in $PATH)',
                    'set(CMAKE_C_COMPILER "%sgcc")' % cc_prefix,
                    'set(CMAKE_ASM_COMPILER "%sgcc")' % cc_prefix,
                    'set(CMAKE_CXX_COMPILER "%sg++")' % cc_prefix,
                    'set(CMAKE_OBJCOPY "%sobjcopy")' % cc_prefix,
                    'set(CMAKE_OBJDUMP "%sobjdump")' % cc_prefix,
                    'set(CMAKE_DEBUGER "%sgdb")' % cc_prefix,
                    'set(CMAKE_CPPFILT "%sc++filt")' % cc_prefix,
                    'set(CMAKE_SIZE "%ssize")' % cc_prefix])

    content.extend([''] * 4)

    content.extend(['######################################',
                    '# set file directory', 
                    '######################################'])

    content.extend([''] * 2)

    content.append('message("++++++++++++++Start Build+++++++++++++++++")')

    content.extend([''])

    inc_dir = list(map(lambda s: 'include_directories(${PROJECT_SOURCE_DIR}/%s)' % s[2:],
                  env['C_INCLUDES'].strip().split()))
    content.extend(['# add header file directory'] + inc_dir)
    
    content.extend([''] * 3)

    src_dir = enumerate(sorted(set(map(lambda s: s[:s.rfind('/')] if '/' in s else '', 
                     (env['C_SOURCES'] + ' ' + env['ASM_SOURCES']).strip().split()))))
    src_dir = list(map(lambda x: 'aux_source_directory(${PROJECT_SOURCE_DIR}%s, SRC%d)' %
                                 (('/' + x[1] if x[1] != '' else ''), x[0]),
                       src_dir))
    content.extend(['# add source file directory'] + src_dir)

    content.extend([''] * 5)

    content.extend(['######################################',
                    '# set cflags', 
                    '######################################',
                    '# cpu',
                    'set(CPU  "%s")' % env['CPU'].strip(),
                    '# fpu',
                    'set(FPU  "%s")' % env['FPU'].strip(),
                    '# float-abi',
                    'set(FLOAT-ABI, "%s")' % env['FLOAT-ABI'].strip(),
                    '# mcu',
                    'set(MCU  "%s")' % env['MCU'].strip()])

    content.extend([''])
    
    content.extend(['ADD_DEFINITIONS(%s)' % env['C_DEFS'].strip(),
                    'set(CMAKE_C_FLAGS "${MCU} -fno-builtin ${OPT}  -Wall -std=gnu99 -fdata-sections -ffunction-sections")',
                    'set(CMAKE_CXX_FLAGS "${MCU} -fno-builtin ${OPT} -Wall -std=c++11 -fdata-sections -ffunction-sections")',
                    'set(CMAKE_ASM_FLAGS "${MCU} -x assembler-with-cpp")'])

    content.extend([''] * 4)

    content.extend(['######################################',
                    '# link', 
                    '######################################'])
    
    content.extend([''] * 2)

    content.extend(['set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")',
                    'set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")'])

    content.extend([''] * 2)

    content.extend(['# libraries',
                    'set(LIBS "-lc -lm -lnosys")',
                    '# link script',
                    'set(LDSCRIPT "${PROJECT_SOURCE_DIR}/%s")' % env['LDSCRIPT'].strip(),
                    'set(CMAKE_EXE_LINKER_FLAGS "%s")' % env['LDFLAGS'].strip().replace('')])
    
    return '\n'.join(content)


class makefile:
    def __init__(self, filename="Makefile"):
        buf = ''
        self.content = []
        self.binaries = {'CXX': False, 'GDB': False}
        with open(filename) as makefile:
            for line in makefile:
                line = line.rstrip()

                if 'CXX = $(GCC_PATH)/$(PREFIX)g++' in line:
                    self.binaries['CXX'] = True
                elif 'CXX = $(GCC_PATH)/$(PREFIX)gdb' in line:
                    self.binaries['GDB'] = True

                if line.endswith('\\'):
                    buf += line[:-1]
                else:
                    buf += line
                    self.content.append(buf)
                    buf = ''
        self.env = {}
        for line in self.content:
            line = line.rstrip()
            if ' =' in line:
                line = line.split(' =')
                self.env[line[0]] = line[1]
            elif ' +=' in line:
                line = line.split(' +=')
                self.env[line[0]] += line[1]

    def add_src_inc(self, src_dir):
        inc, src = traverse(src_dir)
        if os.path.abspath(src_dir) == os.path.abspath('.'):
            src_dir = '.'

        inc = map(lambda s: s[:s.rfind('/')] if '/' in s else '', src)
        inc = set(map(lambda s: '-I%s/%s' % (src_dir, s), inc))
        self.env['C_INCLUDES'] = list(map(lambda s: '-I./%s' % s[2:],
                                     self.env['C_INCLUDES'].strip().split()))
        inc = inc.union(set(self.env['C_INCLUDES']))
        inc = '\\\n'.join(sorted(inc))
        self.env['C_INCLUDES'] = inc

        src = list(map(lambda s: '%s/%s' % (src_dir, s), src))
        self.env['C_SOURCES'] = list(map(lambda s: './%s' % s,
                                    self.env['C_SOURCES'].strip().split()))
        src += self.env['C_SOURCES']
        src = set(map(lambda s: '%s/*.c' % s[:s.rfind('/')], src))
        src = '\\\n'.join(sorted(src))
        self.env['C_SOURCES'] = src

    def write(self, filename='Makefile3'):
        with open(filename, 'w') as new_makefile:
            for line in self.content:
                if 'C_SOURCES =' in line:
                    new_makefile.write('C_SOURCES = %s\n' % self.env['C_SOURCES'])
                elif 'C_INCLUDES =' in line:
                    new_makefile.write('C_INCLUDES = %s\n' % self.env['C_INCLUDES'])
                elif 'SZ = $(GCC_PATH)/$(PREFIX)size' in line:
                    new_makefile.write('%s\n' % line)
                    new_makefile.write('CXX = $(GCC_PATH)/$(PREFIX)g++\n')
                    new_makefile.write('GDB = $(GCC_PATH)/$(PREFIX)gdb\n')
                elif 'SZ = $(PREFIX)size' in line:
                    new_makefile.write('%s\n' % line)
                    new_makefile.write('CXX = $(PREFIX)g++\n')
                    new_makefile.write('GDB = $(PREFIX)gdb\n')
                else:
                    new_makefile.write('%s\n' % line)

def parenthesis_to_brace(s):
    if '$(' not in s:
        return s
    else:
        pos = [(m.start(), m.end()) for m in re.finditer('\$\([a-zA-Z0-9\-_]*\)', s)]
        s = list(s)
        for start, end in pos:
            s[start:start + 2] = ['$', '{']
            s[end - 1] = '}'
        return ''.join(s)


if __name__ == "__main__":
    #content = parse_makefile(filename='Makefile')
    #with open('Makefile2', 'w') as makefile:
    #    for line in content:
    #        makefile.write(line + '\n')

    #with open('cmakefile', 'w') as cmake:
    #    cmake.write(generate_cmake(env))
    makefile_dir = sys.argv[1]
    add_dir_list = sys.argv[2:]
    cwd = os.getcwd()

    os.chdir(makefile_dir)

    mkfl = makefile()
    for d in add_dir_list:
        mkfl.add_src_inc(d)
    mkfl.write()

    os.chdir(cwd)