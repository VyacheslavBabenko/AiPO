#include <stdio.h>
#include <stdlib.h>

struct list {
	void* data;
	struct list* next;
};

typedef void* (*copyType) (void*); //Команда копирования в список
typedef void (*deleteType) (void*); //Команда удаления из списка


struct list* make_list();
void add_to_top(struct list* my_list, void* info, copyType CP);
void add_to_tail(struct list* my_list, void* info, copyType CP);
void delete_current(struct list* my_list, int point, deleteType DLT);
struct list* return_next(struct list* my_list, int point);
struct list* return_last(struct list* my_list, int point);
void print_list(struct list *my_list);
void bubble_sort(struct list* my_list);
void merge_elements(int* X, int* Y, int a, int b);
void quick_sort(struct list* my_list, deleteType DLT, copyType CP);
void destruct_list(struct list* q , deleteType DLT);
void* copy_int(void* element);
void clean_int(void* element);
