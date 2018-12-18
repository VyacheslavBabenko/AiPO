#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <signal.h>

#define BUF_SIZE 1024
#define clear(a) memset(a, 0, BUF_SIZE * sizeof(char))

void mySignalHandler(int signalno) {
	printf("Task has been done\n");
	exit(0);
}

int main() {
	struct sockaddr_in local;

	inet_aton("127.0.0.1", &local.sin_addr);
	local.sin_port = htons(3000);
	local.sin_family = AF_INET;

	int s = socket(AF_INET, SOCK_STREAM, 0);
	bind(s, (struct sockaddr*) &local, sizeof(local));
	listen(s, 5);

	signal(SIGUSR1, mySignalHandler);
	
	FILE* file = fopen("output.txt", "w");
	
	printf("Wainting when u'll start client and ur signal to kill me :c\n");
	while(1) {
		int cs = accept(s, NULL, NULL);
		char buf[BUF_SIZE];
		clear(buf);
		read(cs, buf, BUF_SIZE);
		fprintf(file, "%s\n", buf); 
		close(cs);

	}

	fclose(file);

	return 0;
}
