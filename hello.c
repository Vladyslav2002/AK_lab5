#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

MODULE_AUTHOR("Bohdanenko Vladyslav IV-81");
MODULE_DESCRIPTION("Hello world printing Linux Kernel Training for Lab5");
MODULE_LICENSE("Dual BSD/GPL");

static uint count = 1;
module_param(count, uint, S_IRUGO);
MODULE_PARM_DESC(count, "How many times hello world will be repeated");

static int __init hello_init(void)
{
	uint i;

	if (count == 0) {
		printk(KERN_WARNING "count=%i is 0\n", count);
	} 
	else if (count >= 5 && count <= 10) {
		printk(KERN_WARNING "count=%i in range of 5,10\n", count);
	} 
	else if (count > 10) {
		printk(KERN_ERR "count=%i is bigger than 10\n", count);
		return -EINVAL;
	}
	for (i = 0; i < count; i++) {
		printk(KERN_INFO "Hello world\n");
	}
	return 0;
}

static void __exit hello_exit(void)
{
	/* Do nothing here right now */
}

module_init(hello_init);
module_exit(hello_exit);
