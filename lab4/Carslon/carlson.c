#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size_of_threat 100
#define size_of_exercise 100

void fill(int *treat, int *exercise) {
	int i;
	for (i = 0; i < size_of_exercise; i++)
		exercise[i] = - (rand() % 5);
	for (i = 0; i < size_of_threat; i++)
		treat[i] = rand() % 5;
}

int main() {
	int carlson = 60;
	int *treat = malloc(sizeof(int)*size_of_threat);
	int *exercise = malloc(sizeof(int)*size_of_exercise);
	srand(time(NULL));
	fill(treat, exercise);
	int i = 0, j = 0;
	while (1) {
		if (i == size_of_threat) {
			printf("Carlson s'el ves' jam'\n");
			break;
		}
		if (j == size_of_exercise) {
			printf("Carlson pobil vseh vorov\n");
			break;
		}
		if (carlson >= 100) {
			printf("Carlson stal slishkom tolstim\n");
			break;
		}
		if (carlson <= 20) {
			printf("Carlson ymer\n");
			break;
		}
		int grandmother = rand() % 2;
		if (grandmother) {
			carlson += treat[i];
			i++;
		} else {
			carlson += exercise[j];
			j++;
		}
	}
	free(treat);
	free(exercise);
	return 0;
}

