#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <string.h>

#define MAX_LEN 1024

void MyExit()
{
    exit(0);
}
:
int main()
{
    char buf[MAX_LEN];

    printf("PID: %d\n", getpid());

    struct sockaddr_in local;

    inet_aton("127.0.0.1", &local.sin_addr);
    local.sin_port = htons(1488);
    local.sin_family = AF_INET;

    int s = socket(AF_INET, SOCK_STREAM, 0);
    bind(s, (struct sockaddr*) &local, sizeof(local));
    listen(s, 10);

    signal(SIGUSR1, MyExit);

    while(1)
    {
        int inDes = accept(s, NULL, NULL);
        read(inDes, buf, MAX_LEN);

        FILE* pFile;
        pFile = fopen("file.txt", "a");
        fprintf(pFile, "%s\n", buf);

        fclose(pFile);

        printf("%s\n", buf);

        close(inDes);
    }

    return 0;
}
