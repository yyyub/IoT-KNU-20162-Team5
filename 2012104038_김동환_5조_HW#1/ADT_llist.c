#include "llist.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
LLIST* create_list(){
	LLIST* list;
	list = (LLIST*)malloc(sizeof(LLIST)); // list �����Ҵ�
	if(list) {
	list->front = NULL; //ó������ �� �� front,rear,pos = null
	list->rear = NULL;
	list->pos = NULL;
	list->count = 0; // �ʱ� ����Ʈ �� ��� 0��
	}
	else
		printf("creating failed");


	return list;
}

bool add_node_at(LLIST* list,unsigned int index, char *data){
		NODE *new_ptr;
		new_ptr=(NODE*)malloc(sizeof(NODE)); //list �� ���� �� node ���� �Ҵ�
		if(list->count < index ) // �ְ��� �ϴ� ��ġ��  list��  ��尳�� ���� ������ fail ó��
		{return false;}
		int i = 0;
		for(i = 0; i<50 ; i++)
		 { new_ptr->data_ptr[i] = data[i]; //���� ������ ���  data_ptr �� �Ű������� ���� data �� ����

		 }
		new_ptr->next = NULL; // ���� ������ ��� next �ʱ���´� NULL;

		if(list->count ==0) // list�� ��尡 ������, list�� ��,�ڰ� ���Ե� ��带 ����Ŵ.
		{ list->front = new_ptr;
		  list ->rear = new_ptr;
		  (list->count)++; //list�� ��� 1�� ����
		return true;}

		int iter_i = 0;
		if(index ==0) //0��° index ������,
		{ new_ptr->next = list-> front; //����� next�� ������ front�� ����Ű�� ��� ����Ű�� ��
		 list->front = new_ptr; //list�� front�� ���� �� ��带 ����Ŵ
		 (list->count)++; //list�� ��� 1�� ����
		return true;}

		iter_i++;
		list->pos = list ->front ; //pos�� front�� ����Ų��

		while(iter_i != index)
		{ list->pos = list->pos->next; //index�� ��ŭ pos�� ����Ű�� ��带 �̵���Ų��
		iter_i++;}

		if(iter_i == list->count) //iter_i�� count���� ������,
		{  list->pos->next = new_ptr; //list->pos�� ����Ű�� ���� ����Ʈ �� �ǳ��� ���. ���� ���� ������ ��带 ����Ű����
		   list->rear =new_ptr; // ����Ʈ �� �ǳ� ��带 ����Ű�� rear�� ���� ���ο� ��带 ����Ŵ.
		   (list->count)++; // list�� ��� �߰�

		   return true;}

		else
		{ new_ptr->next = list->pos->next; //iter_i�� count���� �Ȱ�����,
		  list->pos-> next = new_ptr; // list�� index��° �����  next�� ���� ������ ��� ����Ŵ
		  (list->count)++; //list�� ��� �߰�
			  return true;}

}

int search_in_list(LLIST* list){
	int n=0;
	int i=0;
	char searching_word[50];

	scanf("%s",searching_word);//�˻��� �ܾ �Է¹���

	list->pos = list->front; // pos �� ����Ű�� ��带 list �Ǿ� ���� �Ѵ�
	for(i=0; i < list->count ; i++){
		if (strcmp(searching_word , list->pos->data_ptr) ==0 ) //���ڿ� ���Լ��� �Ἥ
			{(n++); //���� �� n�� ���� �ø�
			 printf("%d��° index���� ã��\n",i);
			}

		list->pos = list->pos->next; //pos�� ����Ű�� ��带  ����  pos �����  next ���� �Ѵ�.
	}
	printf("%d���� �˻�����ϴ�",n);
	return n;

}



