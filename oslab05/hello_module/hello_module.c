#include<linux/module.h>

int init_module(void){
	printk(KERN_INFO "Hello module insert successfully!\n");
	return 0;
}

void cleanup_module(void){
	printk(KERN_INFO "Hello module remove successfully!\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PurpleRed");
MODULE_DESCRIPTION("oslab5: hello_module");
