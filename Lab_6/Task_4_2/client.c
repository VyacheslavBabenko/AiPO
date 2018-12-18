#include <stdio.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <signal.h>

int sendToServer(char* ip, int port, char* msg) {
	struct sockaddr_in local, incoming;
	inet_aton(ip, &local.sin_addr);
	local.sin_port = htons(port);
	local.sin_family = AF_INET;
	int s = socket(AF_INET,SOCK_STREAM, 0);
	connect(s,(struct sockaddr*) &local, sizeof(local));

	char buf[1024];
	write(s, msg, strlen(msg)+1);
	memset(buf, 0, 1024);
	read(s, buf, sizeof(int));
	int result = ((int*)buf)[0];
	close(s);
	return result;
}

int main(int argc, char** argv) {
	if(argc != 2 && argc != 3) {
		printf("Use:\n client <site.com> <kill>\n");
		return 0;
	}
	struct hostent *host;
	host = gethostbyname(argv[1]);

	if(host == NULL) {
		printf("Can't find host name: %s\n", argv[1]);
		return 0;
	}

	if(host->h_addrtype != AF_INET) {
		printf("Address of %s is not IPv4\n", argv[1]);
		return 0;
	}

	struct in_addr* tmp = (struct in_addr*) host->h_addr_list[0];
	char msg[100];
	memset(msg, 0, 100);

	strcat(msg, argv[1]);
	strcat(msg, " ");
	strcat(msg, inet_ntoa(*tmp));
	strcat(msg, "\n\0");

	int pid = sendToServer("127.0.0.1", 4000, msg);
	if(argc==3) {
		if(argv[2]) {
			kill(pid,SIGTERM);
		}
	}
	return 0;
}

