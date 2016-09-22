/*
 * llist.c
 *
 *  Created on: 2016. 9. 19.
 *      Author: WIN8
 */
// Linked list ����ü
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#ifndef LLIST_C_
#define LLIST_C_


typedef struct node {
	char data_ptr[50];
	struct node* next;
}NODE; //node structure

typedef struct {
	int count;
	NODE* front;
	NODE* rear;
	NODE* pos;
} LLIST; //Linked List structure

LLIST* create_list(); // Linked List �����Լ� ����
bool add_node_at(LLIST* list,unsigned int index,char* data);//Linked List ��� ���� �Լ� ����
int search_in_list(LLIST* list); //Linked List �� ��峻���� ������ ã�� �Լ� ����














#endif /* LLIST_C_ */
