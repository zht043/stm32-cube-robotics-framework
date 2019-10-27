## Linux

### c_cpp_properties.json

```json
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "${workspaceFolder}/cubemx_project/Drivers/CMSIS/Device/ST/STM32F4xx/Include",
                "${workspaceFolder}/cubemx_project/Drivers/CMSIS/Core/Include",
                "${workspaceFolder}/cubemx_project/Middlewares/**"
            ],
            "defines": [
                "STM32F446xx",
                "USE_HAL_DRIVER"
            ],
            "compilerPath": "~/STM32_Tools/ARM_GCC/gcc-arm-none-eabi-7-2018-q2-update/bin/arm-none-eabi-gcc",
            "cStandard": "c11",
            "cppStandard": "c++17",
            "intelliSenseMode": "gcc-x64"
        }
    ],
    "version": 4
}
```



### settings.json

```json
{
    "C_Cpp.dimInactiveRegions": true,
    "C_Cpp.enhancedColorization": "Enabled",
    "editor.tokenColorCustomizations": {
        "textMateRules": [
            {
                "scope": "entity.name.type",
                "settings": {
                    "foreground": "#3b99f1",
                    "fontStyle": "bold"
                }
            }
        ]
    },
    "C_Cpp.intelliSenseEngineFallback": "Disabled"
}
```





## Windows

### c_cpp_properties

```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE",
                "STM32F446xx",
                "USE_HAL_DRIVER"
            ],
            "compilerPath": "\"C:/Program Files (x86)/GNU Tools Arm Embedded/7 2018-q2-update/bin/arm-none-eabi-gcc.exe\"",
            "cStandard": "c11",
            "cppStandard": "c++17",
            "intelliSenseMode": "gcc-x64"
        }
    ],
    "version": 4
}
```



### settings.json

```json
{
    "C_Cpp.dimInactiveRegions": true,
    "C_Cpp.enhancedColorization": "Enabled",
    "editor.tokenColorCustomizations": {
        "textMateRules": [
            {
                "scope": "entity.name.type",
                "settings": {
                    "foreground": "#3b99f1",
                    "fontStyle": "bold"
                }
            }
        ]
    }
}
```

