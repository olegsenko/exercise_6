// linked_list_process.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <stdio.h>
#include <stdlib.h>

int num_of_nodes = 13;

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
		cur->next = create_node(rand());
		//cur->next = create_node(i);
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



int main()
{
	srand(7);
	printf("Linked list initialisation\n");
	init_linked_list(&list);
	print_linked_list(list);

	free_linked_list(&list);
	return 0;
}

