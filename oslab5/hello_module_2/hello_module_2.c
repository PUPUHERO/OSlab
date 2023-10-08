#include<linux/module.h>

int date = 1, month = 1, year = 2000;

module_param(date, int, 0);
MODULE_PARM_DESC(date, "date of time");
module_param(month, int, 0);
MODULE_PARM_DESC(month, "month of time");
module_param(year, int, 0);
MODULE_PARM_DESC(year, "year of time");

int init_module(void){
    printk(KERN_INFO "Hello module 2 insert s!\n");
    printk(KERN_INFO "Today is %d/%d/%d. \n", year, month, date);
    return 0;
}

void cleanup_module(void){
    printk(KERN_INFO "Hello module 2 remove s!\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PurpleRed");
MODULE_DESCRIPTION("oslab5: hello_module");