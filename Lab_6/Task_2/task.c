#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

#define STRING_LENGTH 101
#define STRINGS_COUNT 1001
#define JOKES_COUNT 10

void freeMemory(char** text, int text_size) {
	int i;
	for(i = 0; i < text_size; ++i) {
		free(text[i]);
	}
	free(text);

	return ;
}

int getInfo(char** text) {
    FILE* file = fopen("input.txt", "r");
	char* data = (char*) malloc(sizeof(char) * STRING_LENGTH);

	int counter = 0;
	while(fgets(data, STRING_LENGTH, file)) {
		text[counter] = (char*) malloc(sizeof(char) * STRING_LENGTH);
		strcpy(text[counter], data);
		++counter;
	}

	free(data);
	fclose(file);

	return counter;
}

void sortInfo(char** text, int size) {
	int i, j;
	char* tmp;
	for(i = 0; i < size - 1; ++i) {
		for(j = i + 1; j < size; ++j) {
			if (strcmp(text[i], text[j]) > 0) {
				tmp = text[i];
				text[i] = text[j];
				text[j] = tmp;
			}
		}
	}

	return ;
}

void printInfo(char** text, int size) {
	FILE* output = fopen("output.txt", "w");

	int i;
	for(i = 0; i < size; ++i) {
		fputs(text[i], output);
	}
	fclose(output);

	return ;
}

int main(int argc, char* argv) {
	pid_t pid = fork();
	int status;

	if(pid) {
		char** joke = (char**) malloc(sizeof(char*) * JOKES_COUNT);
		int i;
        for(i = 0; i < JOKES_COUNT; ++i) {
            joke[i] = (char*) malloc(sizeof(char) * STRING_LENGTH);
            strcpy(joke[i], "AhAhAhAhAhAh\n");
        }

		for(i = 0; i < JOKES_COUNT; ++i) {
			fputs(joke[i], stdout);
			usleep(1000000);
		}

		freeMemory(joke, JOKES_COUNT);

		wait(&status);
	}
	else if(!pid) {
		int i;
		char** text = (char**) malloc(sizeof(char*) * STRINGS_COUNT);
		int size = getInfo(text);
		sortInfo(text, size);
		printInfo(text, size);
		freeMemory(text, size);
	}

	return 0;
}
