/*
 * llist.c
 *
 *  Created on: 2016. 9. 19.
 *      Author: WIN8
 */
// Linked list 구조체
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

LLIST* create_list(); // Linked List 생성함수 선언
bool add_node_at(LLIST* list,unsigned int index,char* data);//Linked List 노드 삽입 함수 선언
int search_in_list(LLIST* list); //Linked List 내 노드내에서 데이터 찾는 함수 선언














#endif /* LLIST_C_ */
