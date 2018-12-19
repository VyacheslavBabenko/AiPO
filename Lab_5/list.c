#include "list.h"

//Создание списка
struct list* make_list() {
	struct list* sent;
	sent = (struct list*) malloc(sizeof(struct list));
	sent->next = NULL;

	return sent;
}

//Добавление элемента в начало списка
void add_to_top(struct list* my_list, void* info, copyType CP) {
	struct list* tmp = (struct list*) malloc(sizeof(struct list));

	tmp->data = CP(info);
	tmp->next = my_list->next;
	my_list->next = tmp;
	return ;
}

//Добавление элемента в конец списка
void add_to_tail(struct list* my_list, void* info, copyType CP) {
	struct list* tmp = (struct list*) malloc(sizeof(struct list));

	while(my_list->next != NULL) {
		my_list = my_list->next;
	}

	tmp->data = CP(info);
	my_list->next = tmp;
	tmp->next = NULL;

    return ;
}

//Удаление текущего элемента
void delete_current(struct list* my_list, int point, deleteType DLT) {
	struct list* tmp = my_list;
	struct list* last;

	while(1 < point) {
		tmp = tmp->next;
		last = tmp;
		--point;
	}
	tmp = tmp->next;

	last->next = tmp->next;
	DLT(tmp->data);
	free(tmp);

    return ;
}

//Получение следующего элемента
struct list* return_next(struct list* my_list, int point) {
	struct list* tmp = my_list;

    while(0 <= point + 1 && tmp->next != NULL) {
		tmp = tmp->next;
		--point;
	}

	return tmp;
}

//Получение предыдущего элемента
struct list* return_last(struct list* my_list, int point) {
	struct list* tmp = my_list;

	if(point == 1) {
		return tmp;
	}

	while(0 <= point - 1) {
		tmp = tmp->next;
		point--;
	}

	return tmp;
}

//Вывод списка
void print_list(struct list *my_list) {
	struct list* tmp;
	if(my_list->next != NULL) {
		tmp = my_list->next;
        while(tmp != NULL) {
			printf("%d ", *(int*) (tmp->data));
			tmp = tmp->next;
		}
	}

	return ;
}

//Сортировка списка пузырьком
void bubble_sort(struct list* my_list) {
	struct list* p1;
	struct list* p2;
	struct list* tmp;
	int t1, t2;
	for(p1 = my_list->next; p1 != NULL; p1 = p1->next) {
        for(p2 = p1->next; p2 != NULL; p2 = p2->next) {
			t1 = *(int*) (p1->data);
			t2 = *(int*) (p2->data);
			if(t2 < t1) {
				tmp = p1->data;
				p1->data = p2->data;
				p2->data = tmp;
			}
		}
	}

	return ;
}

//Непосредствено быстрая сортировка
void merge_elements(int* X, int* Y, int a, int b) {
    if(b <= a)
        return;
    int mid = (a + b) / 2;
    merge_elements(X, Y, a, mid);
    merge_elements(X, Y, mid + 1, b);

    int k;
    for(k = a; k <= b; ++k) {
        Y[k] = X[k];
    }

    int i = a, j = mid + 1;
    for(k = a; k <= b; ++k) {
        if(i > mid) {
            X[k] = Y[j++];
        }
		else if(j > b) {
            X[k] = Y[i++];
        }
		else if(Y[j] < Y[i]) {
            X[k] = Y[j++];
        }
		else {
            X[k] = Y[i++];
        }
    }

    return ;
}

//Быстрая сортировка списка
void quick_sort(struct list* my_list, deleteType DLT, copyType CP) {
	struct list* tmp;
	int t1, t2, cnt = 0, i = 1;
	for(tmp = my_list->next; tmp != NULL; tmp = tmp->next) {
	        ++cnt;
	}

	int *X = (int*) malloc((cnt + 1) * sizeof(int));
	int *Y = (int*) malloc((cnt + 1) * sizeof(int));

	for(tmp = my_list->next; tmp != NULL; tmp = tmp->next) {
		X[++i] = *(int*) tmp->data;
		DLT(tmp->data);
	}

	merge_elements(X, Y, 1, cnt + 1);

	i = 1;
	for(tmp = my_list->next ; tmp != NULL ; tmp = tmp->next) {
        tmp->data = CP(&X[++i]);
	}
	free(Y);
	free(X);

	return ;
}

//Очистка списка
void destruct_list(struct list* q , deleteType DLT) {
	struct list* cur = q->next;
	while(cur != NULL) {
		struct list* del = cur;
		cur = cur->next;
		DLT(del->data);
		free(del);
	}
	free(q);

	return ;
}

//Функция копирования эелмента
void* copy_int(void* element) {
    int* res = (int*) malloc(sizeof(int));
    *res = *(int*) element;
    return res;
}

//Функция удаления элемента
void clean_int(void* element) {
    free(element);
    return ;
}
