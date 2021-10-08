#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int dev = open("/dev/dev-num", O_RDONLY);
	if (dev == -1) {
		printf("Failed to open\n");
		return -1;
	}
	printf("Opened /dev/dev-num\n");
	close(dev);
	return 0;
}
