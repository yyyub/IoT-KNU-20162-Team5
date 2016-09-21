#include <stdio.h>
#include <stdlib.h>
#include <String.h>

int indexcnt = 0; //�ε��� ī��Ʈ�� ���� ����

typedef struct ListNode { //��� ����
 char word[20]; //�ܾ� ����
 int index; //�ε��� ����
 struct ListNode *link;
} ListNode;


void insert_node(ListNode **phead, ListNode *p, ListNode *new_node) //��� ������ ���� �Լ�
{    // phead:  ����Ʈ�� ��� �������� ������ p : ������, new_node : ���Ե� ���
 if ( phead == NULL) { // ��� �������� �����Ͱ� NULL�ΰ�� �������
  new_node->link = NULL;
  *phead = new_node;
 }
 else if(p == NULL){// �����밡 ����� ù ���� ���� ����
  new_node->link = *phead;
  *phead = new_node;
 }
 else {  // �� �� �ƴϸ� ������ ������ ����
  new_node->link = p->link;
  p->link = new_node;
 }
}

void display_recur(ListNode *head, char *voca) // ��¹��� ���� �Լ�
{
  ListNode *p=head;
  int cnt = 0; // �ߺ�Ƚ�� ������
  int i = 0;
  
  printf("�˻��Ͻ� �ܾ�� ");
  while(p != NULL)
  {
   if (strcmp(p->word, voca) == 0)// �˻��Ѱſ� ��尡 ������ �ε��� ���
   {
    printf("%d ",++(p->index)); //�ε�����1���Ͷ� +1
    cnt++;			//������ ���������� �ߺ�Ƚ�� +1
   }
   p = p->link; //���� ����
  }
   printf("��° �ܾ��̸� �� %d�� �Դϴ�.\n",cnt); //�ߺ�Ƚ�� ���
}	

ListNode *create_node(char *word, int index, ListNode *link)//��带 �������� �����ϴ� �Լ�
{
 ListNode *new_node; //��� ����
 int i=0;
 new_node = (ListNode *)malloc(sizeof(ListNode)); // ��� ũ�⸸ŭ �޸��Ҵ�
 if ( new_node == NULL)
   printf("�޸� �Ҵ� ����, ��� ���� �Ұ�"); //�޸� �Ҵ�������� ��¹�
 

 for(i = 0; i<=20 ; i++)
 {
	if( word[i] != '.' && word[i] != ',' && word[i] != '?' && word[i] != '!') // �����ȣ�ձ����� ����
		new_node->word[i] = word[i];
	else					//�����ȣ�̸� �ڿ��κ� ��¸��ϰ� NULL������
		new_node->word[i] = NULL;
 }
 new_node->index = index; //�ε���ī��� �ε����� ����
 new_node->link = link;   //link����
 return (new_node); //����� ������ ��ȯ
}


int main()
{
 char buf[20]; //�ӽ÷� �ؽ�Ʈ�� ���� �迭
 char *input; //�Է¹��� �ܾ�
 int i = 0; // �ݺ������� ���
 ListNode *head = NULL;
 FILE *fp;
 fp  = fopen("input.txt","r"); //�ؽ�Ʈ������ �б���� ����
 
 if (fp == NULL)//���� ������ return 0;���� ���α׷�����
 {
  printf("������ ������ �ʽ��ϴ�. ���α׷��� �����մϴ�.\n");
  system("pause");
   return 0;
 }

 while( !feof(fp)) //������ ���������� �ݺ�
 {
   fscanf(fp,"%s",buf); //buf�� ����

   insert_node(&head,NULL,create_node(buf,indexcnt++,NULL)); //��� ���� �ε���
 }
 
 input = (char *) malloc(sizeof(char)*19);
 printf("� �ܾ �˻��Ͻðڽ��ϱ�? ");
 gets(input); //�ܾ� �Է�
 printf("�Էµ� ���ڿ� : %s\n\n",input);
 display_recur(head, input); //�Էµ� �ܾ �Ѱܼ�, �Լ��� ���

 free(input); //�Է¹����� ����� �޸� ��ȯ
 fclose(fp); //���� �ݱ�
 system("pause");
 return 0;
}  
