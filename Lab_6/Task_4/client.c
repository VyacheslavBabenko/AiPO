#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 1024
#define clear(a) memset(a, 0, BUF_SIZE * sizeof(char))

void makeData(char* buf, char* dns, char* ip) {
	int i, j, len = 0;
	for (i = 0; i < strlen(dns); ++i) {
		buf[i] = dns[i];
		len++;
	}
	buf[len] = ' ';
	len++;
	for (i = len; i < len + strlen(ip); ++i) {
		buf[i] = ip[i - len];
	}
}

void sendData(char* data) {
	struct sockaddr_in local;

	inet_aton("127.0.0.1", &local.sin_addr);
	local.sin_port = htons(3000);
	local.sin_family = AF_INET;

	int s = socket(AF_INET, SOCK_STREAM, 0);
	connect(s, (struct sockaddr*) &local, sizeof(local));

	write(s, data, strlen(data) + 1);
	close(s);
}

int main(int argc, char* argv[]) {
	if (argc != 2) {
		return -1;
	}

	struct hostent *h;
	h = gethostbyname(argv[1]);

	if (NULL == h) {
		printf("ERROR\n");
		return -1;
	}

	if (h->h_addrtype != AF_INET) {
		return 0;
	}
	
	char data[BUF_SIZE];
	int i = 0;
	while (NULL != h->h_addr_list[i]) {
		struct in_addr* tmp = (struct in_addr*) h->h_addr_list[i];
		
		clear(data);
		makeData(data, argv[1], inet_ntoa(*tmp));
		sendData(data);

		i++;		
	}

	return 0;
}
