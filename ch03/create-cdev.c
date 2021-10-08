#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

#define MAJOR_NUM 300

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Register a char device with a device number and implement open and close callback functions");

/**
 * @brief Called when the device file is opened
 */
static int driver_open(struct inode *device_file, struct file *instance) {
	printk(KERN_INFO "[test-cdev] open was called!\n");
	return 0;
}

/**
 * @brief Called when the device file is closed
 */
static int driver_close(struct inode *device_file, struct file *instance) {
	printk(KERN_INFO "[test-cdev] close was called!\n");
	return 0;
}

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = driver_open,
	.release = driver_close
};

/**
 * @brief Called when this module is being loaded into the kernel, register device number
 */
static int __init mod_init(void) {
	printk(KERN_INFO "[test-cdev] initializing\n");

	/* register device number */
	int retval = register_chrdev(MAJOR_NUM, "test-cdev", &fops);
	if (retval == 0) {
		printk(KERN_INFO "[test-cdev] registered device number Major: %d, Minor: %d\n", MAJOR_NUM, 0);
	} else if (retval > 0) {
		printk(KERN_INFO "[test-cdev] registered device number Major: %d, Minor: %d\n", retval>>20, retval&0xfffff);
	} else {
		printk(KERN_ALERT "[test-cdev] could not register device number!\n");
		return -1;
	}

	return 0;
}

static void __exit mod_exit(void) {
	unregister_chrdev(MAJOR_NUM, "test-cdev");
	printk(KERN_INFO "[test-cdev] exited\n");
}

module_init(mod_init);
module_exit(mod_exit);

