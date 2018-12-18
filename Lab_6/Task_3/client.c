#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main(){
	int file;
	char* fifo = "/gpfs/home/bivanov/Lab_6/Task_3/pipe";

	mkfifo(fifo, 0666);

	file = open(fifo, O_WRONLY);

	printf("Enter message:\n");
	char msg[100];
	memset(msg, 0, sizeof(msg));
	char c;
	int i = 0;
	while(scanf("%c", &c) > 0) {
        msg[i++] = c;
	}

	write(file, msg, strlen(msg));
	close(file);

	printf("MESSAGE WRITTEN\n");

	return 0;
}

