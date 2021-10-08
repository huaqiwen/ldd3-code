ccflags-y := -std=gnu99 -Wno-declaration-after-statement

# If KERNELRELEASE is defined, we've been invoked from the
# kernel build system and can use its language.
ifneq ($(KERNELRELEASE),)
	obj-m := dev-num.o
# Otherwise we were called directly from the command
# line; invoke the kernel build system.
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

test-read:
	gcc -Wall -Werror test.c -o test
	sudo chmod 666 /dev/dev-num

clean:	
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
	rm -rf test

endif
