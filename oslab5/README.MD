# lab05

編譯linux kernal module

### Notes

1. `.ko` file
    
    kernel module的副檔名 …
    
2. Makefile
    
    …
    
3. `module_param(parameter_name, data_type, permissions);`
    - **`parameter_name`**：參數的名稱，這是一個字符串，用於識別參數。
    - **`data_type`**：參數的數據類型，可以是整數、字符、布林值等。
    - **`permissions`**：參數的權限，用於指定參數是否可讀寫。
4. `MODULE_PARM_DESC(parameter_name, description);`
    - **`parameter_name`**：要描述的模塊參數的名稱。
    - **`description`**：對該參數的描述性文本。

### Troubleshooting

- make[1]: *** No rule to make target `arch/x86/entry/syscalls/syscall_32.tbl', needed by arch/x86/entry/syscalls/../../include/generated/asm/syscalls_32.h'.`  Stop.
make: *** [archheaders] Error 2
    
    [No rule to make target `arch/x86/entry/syscalls/syscall_32.tbl', needed by `arch/x86/entry/syscalls/../../include/generated/asm/syscalls_32.h'](https://stackoverflow.com/questions/39107811/no-rule-to-make-target-arch-x86-entry-syscalls-syscall-32-tbl-needed-by-arch)
    
    解決方式:
    
    將`$(PWD)`替換為`$(shell pwd)`
    
- insmod invalid module format
    
    [正确解决 Invalid module format_invalidmodule format-CSDN博客](https://blog.csdn.net/shell812/article/details/45010017)
    
    [模块加载时 insmod “Invalid module format ”问题解决-CSDN博客](https://blog.csdn.net/ymangu666/article/details/22872439)
    
- module verification failed: signature and/or required key missing - tainting kernel