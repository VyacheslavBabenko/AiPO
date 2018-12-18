#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	struct list* sent = make_list();
	copyType CP = copy_int;
	deleteType DLT = clean_int;
	
	int n;
	void* info;
	while(scanf("%d", &n) > 0) {
		info = &n;
		add_to_tail(sent, info, CP);
	}

	printf("List: \n");
	print_list(sent);
	printf("\n");

	printf("QuickSorted: \n");
	bubble_sort(sent);
	print_list(sent);

	destruct_list(sent, DLT);

    return 0;
}
