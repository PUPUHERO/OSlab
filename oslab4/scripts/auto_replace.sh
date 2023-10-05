#!/bin/bash
cp oslab4/syscall_64.tbl linux-5.4.2/arch/x86/entry/syscalls/syscall_64.tbl
cp oslab4/syscall_32.tbl linux-5.4.2/arch/x86/entry/syscalls/syscall_32.tbl
cp oslab4/unistd.h linux-5.4.2/include/uapi/asm-generic/unistd.h
cp oslab4/sys.c linux-5.4.2/kernel/sys.c
cp oslab4/sys_ni.c linux-5.4.2/kernel/sys_ni.c
cp oslab4/syscalls.h linux-5.4.2/include/linux/syscalls.h

echo 'done'
