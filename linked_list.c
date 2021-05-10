#include <stdio.h>
#include <stdlib.h>

int num_of_nodes = 23;

struct ListNode {
	int value;
	struct ListNode* next;
}*list;

struct ListNode* create_node(int val)
{
	struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
	new_node->value = val;
	new_node->next = NULL;
	return new_node;
}



void init_linked_list(struct ListNode** list)
{
	struct ListNode* cur;
	*list = create_node(37);
	cur = *list;

	for (int i = 1; i < num_of_nodes; i++) {
		//cur->next = create_node(rand());
		cur->next = create_node(i);
		cur = cur->next;
	}
}


void print_linked_list(struct ListNode *list)
{
	struct ListNode *cur = list;
	while (cur) {
		printf("%d\t", cur->value);
		cur = cur->next;
	}
	printf("\n");
}


void free_linked_list(struct ListNode** list)
{
	struct ListNode* cur = *list;
	struct ListNode* tmp = *list;

	while (cur) {
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
}


int is_prime(int value)
{
	if (value == 1 || value == 0) return 0;

	for (int i = 2; i*i <= value; i++) {
		if ((value % i) == 0) {
			return 0;
		}
	}
	return 1;
}

void swap(struct ListNode **first, struct ListNode **second)
{
	struct ListNode *tmp = *first;
	*first = *second;
	*second = tmp;
}


int swap_nodes(struct ListNode *cur, struct ListNode *primes_cur)
{
	
	printf("cur is %d, primes_cur is %d \n", cur->value, primes_cur->value);
	swap(&(cur->next), &(primes_cur->next));
	swap(&(cur->next->next), &(primes_cur->next->next));

	return 0;
}


void process(struct ListNode** list)
{
	struct ListNode* cur = *list;
	struct ListNode* primes_cur = *list;

	while (cur->next) {
		if (is_prime(cur->next->value)) {
			printf("processing %d \n ", cur->next->value);
			swap_nodes(cur, primes_cur);
			primes_cur = primes_cur->next;
			print_linked_list(*list);
		}
		cur = cur->next;
	}
}

int main()
{
	srand(7);
	printf("Linked list initialisation\n");
	init_linked_list(&list);
	print_linked_list(list);
	process(&list);

	printf("Result is: \n");
	print_linked_list(list);
	free_linked_list(&list);
	return 0;
}
