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
	LLIST* list= create_list(); // list ������ creat_list()�Լ� ȣ���Ͽ� ����
	int iter_i=0;
	FILE *f; //���� f ����
	f=fopen("test.txt","r");//fopen �Լ��� test.txt read���� ����

	if(f == NULL)//���� ���� ���
	{
	printf("file open error!\n");
	return 1;
	}


	while (1){
		if (feof(f) == 0)//feof(f)�� ������ ���� �����ϸ� 1�� ������
		{
		   char word[50];
		   char* ptr;
		   fscanf(f, "%s", word); //txt��  �ܾ �о�� word�� ����
		   ptr = strtok( word, ",");//��ǥ,��ħǥ ���� �������� �ܾ ���� ptr�� ����
		   ptr = strtok(word,".");
		   ptr= strtok(word,"'");
		   while (ptr != NULL) {
		           if(!add_node_at(list,iter_i,ptr))//list���� iter_i��° index�� ptr������ ���� ��� ����
		        	   printf("data insertion failed.");
		           else
		        	   printf("%d��° ���� ������:%s\n",iter_i,ptr);
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
	search_in_list(list); //search_in_list �Լ� ȣ��

}

