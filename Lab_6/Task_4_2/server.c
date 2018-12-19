#include <stdio.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#define FILE_NAME "target.txt"

int writeToFile(char* fileName, char* content) {
	FILE* file = fopen(fileName, "a");
	fputs(content, file);
	fclose(file);
	return file == NULL;
}

int main(void) {
	struct sockaddr_in local, incoming;
	inet_aton("127.0.0.1", &local.sin_addr);
	local.sin_port = htons(4000);
	local.sin_family = AF_INET;
	int s = socket(AF_INET, SOCK_STREAM, 0);
	bind(s, (struct sockaddr*) &local, sizeof(local));
	listen(s, 5);

	socklen_t in_len = sizeof(incoming);

	while(1) {
		int	cs = accept(s, (struct sockaddr*) &incoming, &in_len);
		char buf[1024];
		memset(buf, 0, 1024);
		read(cs, buf, 1024);
		int result = writeToFile(FILE_NAME, buf);
		printf("Written with result code: %d\n", result);

		int pid = getpid();

		write(cs, &pid, sizeof(int));
		close(cs);
	}
	return 0;
}
