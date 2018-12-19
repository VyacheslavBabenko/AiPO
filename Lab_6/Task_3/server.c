#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define SIZE_OF_BUFF 1024

int main() {
	int file;
	char* fifo = "/gpfs/home/bivanov/Lab_6/Task_3/pipe";
	char buf[SIZE_OF_BUFF];

	printf("Opening fifo for reading...\n");
	file = open(fifo, O_RDONLY);

	read(file, buf, SIZE_OF_BUFF);
	printf("Reading completed!\n");

	int i;
	for(i = 0; i < 10 ; ++i) {
 		printf("%s\n", buf);
	}

	close(file);

	return 0;
}
