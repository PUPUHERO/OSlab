#include<linux/module.h>
#include<linux/kernel.h>
// #include<linux/time.h>


struct timeval
{
    long long int tv_sec; /* seconds */
    long long int tv_usec; /* microseconds */
};


struct timeval tv_now;

extern long long int ts;
extern ktime_t ktime_get_real(void);


int init_module(void){
    //get the current timestamp
    tv_now.tv_sec = ktime_get_real()/1000000000;
    printk(KERN_INFO "Getting the current timestamp...\n");
    printk(KERN_INFO "The current timestamp is %lld\n", tv_now.tv_sec);

    //calculate the age in years and days
    int age, days;
    age = (tv_now.tv_sec - ts) / 86400 / 365;
    days = (tv_now.tv_sec - ts) / 86400 % 365;

    if (tv_now.tv_sec < ts){
        printk(KERN_INFO "You are TENET, go save the world!!!\n");
        printk(KERN_INFO "invaild arguments\n");
        return -EINVAL;
    }
    else {
        printk(KERN_INFO "Loading myage Module...\n");
        printk(KERN_INFO "Your age is %d years and %d days\n", age, days);
        return 0;
    }
}

void cleanup_module(void){
    printk(KERN_INFO "Removing myage Module...\n");
}


MODULE_LICENSE("GPL");
MODULE_AUTHOR("PUPUHERO");
MODULE_DESCRIPTION("myage Module");
