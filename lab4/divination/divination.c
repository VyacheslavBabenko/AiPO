#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N	1 << 11

int found(char* haystack[], char* needle, int n) {
       int i;
       for (i = 0; i < n; ++i)
	       if (!strcmp(haystack[i], needle))
		       return 1;
       return 0;
}      

int getstrings(char* s[]) {
	int n = 0;
	char tmp[N];
	while (fgets(tmp, N - 1, stdin) != NULL) {
		if (tmp[0] == '\n')
			continue;
		if (!found(s, tmp, n)) {
			s[n] = malloc(sizeof(char) * (strlen(tmp) + 1));
			strcpy(s[n], tmp);
			++n;
		}
	}
	free (tmp);
	return n;
}

void print(int n, char* s[]) {
	int i;
	for (i = 0; i < n / 2; ++i)
		printf("%s", s[i]);
	putchar('\n');
	for (; i < n; i++)
		printf("%s", s[i]);
}

void release(int n, char** s) {
	int i;
	for (i = 0; i < n; ++i)
		free(s[i]);
	free(s);
}

int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char** str = malloc(sizeof(char*) * N);
	int n = getstrings(str);
	print(n, str);
	release(n, str);
	return 0;
}
