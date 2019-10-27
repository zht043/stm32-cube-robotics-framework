import os
import sys

def traverse(curr_dir):
    inc, src = [], []
    for curr_root, dirs, files in os.walk(curr_dir):
        for file in files:
            if file.endswith(".c"):
                src.append(os.path.relpath(curr_root, curr_dir) + '/' + file)
            elif file.endswith(".h"):
                inc.append(os.path.relpath(curr_root, curr_dir) + '/' + file)
    return inc, src

if __name__ == "__main__":
    dir = sys.argv[1]
    inc, src = traverse(dir)
    print("Headers:")
    for f in inc:
        print(f)

    print("\nSources:")
    for f in src:
        print(f)

