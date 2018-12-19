#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#define OUTPUT_PATH "File_2.txt"
#define SIZE 100000000

char* genData(int size){
	char* buffer = (char*)malloc(size*sizeof(char));
	int i;
	for (i = 0;i<size;i++){
		char byte = (char)('a' + (0 + rand() % 26));
		buffer[i]=byte;
	}
	return buffer;
}

int main(void) {
	srand((unsigned) time(NULL));

	int file = open(OUTPUT_PATH, O_CREAT | O_WRONLY | O_APPEND);
	char* data = (char*) malloc(sizeof(char) * SIZE);

	int i;
	for (i = 0; i < SIZE; ++i) {
		data[i] = (char)('a' + (0 + rand() % 26));
	}

	write(file, data, SIZE);
	free(data);

	return 0;
}
