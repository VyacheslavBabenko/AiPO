#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OUTPUT_PATH "File_1.txt"
#define SIZE 100000000


int main(void) {
	srand((unsigned) time(NULL));

	FILE* file = fopen(OUTPUT_PATH, "w");
	char* data;

	int i;

	for(i = 0; i < SIZE; ++i) {
		data = (char*) malloc(sizeof(char));
		data[0] = (char) ('a' + (0 + rand() % 26));
		fwrite(data, sizeof(char), 1, file);
		free(data);
	}

	fclose(file);

	return 0;
}
