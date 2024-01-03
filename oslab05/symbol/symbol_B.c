#include<linux/module.h>

extern int symbol_variable;
extern int symbol_function(int);

int init_module(void) {
    printk(KERN_INFO "Sysbol B insert successfully!\n");

    printk(KERN_INFO "symbol_variable = %d\n", symbol_variable);
    printk(KERN_INFO "symbol_function(100) = %d\n", symbol_function(100));
    printk(KERN_INFO "symbol_function(0) = %d\n", symbol_function(0));
    printk(KERN_INFO "symbol_function(-100) = %d\n", symbol_function(-100));

    return 0;
}

void cleanup_module(void) {
    printk(KERN_INFO "Sysbol B remove successfully!\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PUPUHERO");
MODULE_DESCRIPTION("oslab: symbol_B");
