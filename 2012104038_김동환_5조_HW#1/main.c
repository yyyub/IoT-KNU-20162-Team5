/*
 * main.c
 *
 *  Created on: 2016. 9. 19.
 *      Author: WIN8
 */
#include <stdio.h>
#include "llist.h"
#include <string.h>
#include <ctype.h>


int main(){
	LLIST* list= create_list(); // list 선언후 creat_list()함수 호출하여 생성
	int iter_i=0;
	FILE *f; //파일 f 선언
	f=fopen("test.txt","r");//fopen 함수로 test.txt read모드로 읽음

	if(f == NULL)//파일 없을 경우
	{
	printf("file open error!\n");
	return 1;
	}


	while (1){
		if (feof(f) == 0)//feof(f)는 문장의 끝에 도달하면 1을 리턴함
		{
		   char word[50];
		   char* ptr;
		   fscanf(f, "%s", word); //txt의  단어를 읽어와 word에 저장
		   ptr = strtok( word, ",");//쉼표,마침표 등을 기준으로 단어를 끊어 ptr에 저장
		   ptr = strtok(word,".");
		   ptr= strtok(word,"'");
		   while (ptr != NULL) {
		           if(!add_node_at(list,iter_i,ptr))//list내에 iter_i번째 index에 ptr데이터 가진 노드 삽입
		        	   printf("data insertion failed.");
		           else
		        	   printf("%d번째 삽입 데이터:%s\n",iter_i,ptr);
		           ptr = strtok (NULL, ",");
		           ptr = strtok (NULL,".");
		           ptr = strtok (NULL,"'");
		           iter_i++;

		   }


		   	  }
	  else
		   break;
	     }
	printf("--------------------------------\n");
	search_in_list(list); //search_in_list 함수 호출

}

