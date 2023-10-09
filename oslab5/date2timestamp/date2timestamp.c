#include <linux/module.h>

int d = 1, m = 1, y= 1970;

module_param(d, int, 0);
MODULE_PARM_DESC(d, "Date of your birth");
module_param(m, int, 0);
MODULE_PARM_DESC(m, "Month of your birth");
module_param(y, int, 0);
MODULE_PARM_DESC(y, "Year of your birth");

long long int ts = 0;

int init_module(void){

    int year = y - 1970;
    int month = m - 1;
    int day = d - 1;

    ts += year * 365 * 86400;
    ts += month * 30 * 86400;
    ts += day * 86400;


    printk(KERN_INFO "Loading date2timestamp Module...\n");
    printk(KERN_INFO "Your birthday is %d/%d/%d\n", y, m, d);
    printk(KERN_INFO "The timestamp: ts=%lld\n", ts);
    return 0;
}

void cleanup_module(void){
    printk(KERN_INFO "Removing date2timestamp Module...\n");
}

EXPORT_SYMBOL(ts);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PUPUHERO");
MODULE_DESCRIPTION("date2timestamp Module");


