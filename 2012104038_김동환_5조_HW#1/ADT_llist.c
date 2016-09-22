#include "llist.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
LLIST* create_list(){
	LLIST* list;
	list = (LLIST*)malloc(sizeof(LLIST)); // list 동적할당
	if(list) {
	list->front = NULL; //처음생성 될 때 front,rear,pos = null
	list->rear = NULL;
	list->pos = NULL;
	list->count = 0; // 초기 리스트 내 노드 0개
	}
	else
		printf("creating failed");


	return list;
}

bool add_node_at(LLIST* list,unsigned int index, char *data){
		NODE *new_ptr;
		new_ptr=(NODE*)malloc(sizeof(NODE)); //list 내 삽입 될 node 동적 할당
		if(list->count < index ) // 넣고자 하는 위치가  list내  노드개수 보다 높을때 fail 처리
		{return false;}
		int i = 0;
		for(i = 0; i<50 ; i++)
		 { new_ptr->data_ptr[i] = data[i]; //새로 생성된 노드  data_ptr 에 매개변수로 받은 data 값 삽입

		 }
		new_ptr->next = NULL; // 새로 생성된 노드 next 초기상태는 NULL;

		if(list->count ==0) // list내 노드가 없을때, list의 앞,뒤가 삽입될 노드를 가리킴.
		{ list->front = new_ptr;
		  list ->rear = new_ptr;
		  (list->count)++; //list내 노드 1개 증가
		return true;}

		int iter_i = 0;
		if(index ==0) //0번째 index 넣을때,
		{ new_ptr->next = list-> front; //노드의 next를 기존의 front가 가르키는 노드 가르키게 함
		 list->front = new_ptr; //list의 front는 이제 새 노드를 가르킴
		 (list->count)++; //list내 노드 1개 증가
		return true;}

		iter_i++;
		list->pos = list ->front ; //pos는 front를 가르킨다

		while(iter_i != index)
		{ list->pos = list->pos->next; //index수 만큼 pos가 가르키는 노드를 이동시킨다
		iter_i++;}

		if(iter_i == list->count) //iter_i가 count까지 갔을때,
		{  list->pos->next = new_ptr; //list->pos가 가르키는 노드는 리스트 내 맨끝의 노드. 이제 새로 생성될 노드를 가르키게함
		   list->rear =new_ptr; // 리스트 내 맨끝 노드를 가르키던 rear는 이제 새로운 노드를 가르킴.
		   (list->count)++; // list내 노드 추가

		   return true;}

		else
		{ new_ptr->next = list->pos->next; //iter_i가 count까지 안갔으면,
		  list->pos-> next = new_ptr; // list내 index번째 노드의  next가 새로 생성된 노드 가르킴
		  (list->count)++; //list내 노드 추가
			  return true;}

}

int search_in_list(LLIST* list){
	int n=0;
	int i=0;
	char searching_word[50];

	scanf("%s",searching_word);//검색할 단어를 입력받음

	list->pos = list->front; // pos 가 가르키는 노드를 list 맨앞 노드로 한다
	for(i=0; i < list->count ; i++){
		if (strcmp(searching_word , list->pos->data_ptr) ==0 ) //문자열 비교함수를 써서
			{(n++); //맞을 시 n의 개수 늘림
			 printf("%d번째 index에서 찾음\n",i);
			}

		list->pos = list->pos->next; //pos가 가르키는 노드를  현재  pos 노드의  next 노드로 한다.
	}
	printf("%d개가 검색됬습니다",n);
	return n;

}



