#include <stdio.h>
#include <stdlib.h>
#include <String.h>

int indexcnt = 0; //인덱스 카운트를 위한 변수

typedef struct ListNode { //노드 정의
 char word[20]; //단어 저장
 int index; //인덱스 저장
 struct ListNode *link;
} ListNode;


void insert_node(ListNode **phead, ListNode *p, ListNode *new_node) //노드 삽입을 위한 함수
{    // phead:  리스트의 헤드 포인터의 포인터 p : 선행노드, new_node : 삽입될 노드
 if ( phead == NULL) { // 헤드 포인터의 포인터가 NULL인경우 헤더생성
  new_node->link = NULL;
  *phead = new_node;
 }
 else if(p == NULL){// 선행녿가 헤더면 첫 번재 노드로 삽입
  new_node->link = *phead;
  *phead = new_node;
 }
 else {  // 둘 다 아니면 선행노드 다음에 삽입
  new_node->link = p->link;
  p->link = new_node;
 }
}

void display_recur(ListNode *head, char *voca) // 출력문을 위한 함수
{
  ListNode *p=head;
  int cnt = 0; // 중복횟수 세리기
  int i = 0;
  
  printf("검색하신 단어는 ");
  while(p != NULL)
  {
   if (strcmp(p->word, voca) == 0)// 검색한거와 노드가 같으면 인덱스 출력
   {
    printf("%d ",++(p->index)); //인덱스는1부터라서 +1
    cnt++;			//같은것 세릴때마다 중복횟수 +1
   }
   p = p->link; //다음 노드로
  }
   printf("번째 단어이며 총 %d개 입니다.\n",cnt); //중복횟수 출력
}	

ListNode *create_node(char *word, int index, ListNode *link)//노드를 동적으로 생성하는 함수
{
 ListNode *new_node; //노드 생성
 int i=0;
 new_node = (ListNode *)malloc(sizeof(ListNode)); // 노드 크기만큼 메모리할당
 if ( new_node == NULL)
   printf("메모리 할당 에러, 노드 생성 불가"); //메모리 할당못했을때 출력문
 

 for(i = 0; i<=20 ; i++)
 {
	if( word[i] != '.' && word[i] != ',' && word[i] != '?' && word[i] != '!') // 문장부호앞까지만 저장
		new_node->word[i] = word[i];
	else					//문장부호이면 뒤에부분 출력못하게 NULL값지정
		new_node->word[i] = NULL;
 }
 new_node->index = index; //인덱스카운값을 인덱스에 저장
 new_node->link = link;   //link연결
 return (new_node); //노드의 포인터 반환
}


int main()
{
 char buf[20]; //임시로 텍스트를 읽을 배열
 char *input; //입력받을 단어
 int i = 0; // 반복을위한 상수
 ListNode *head = NULL;
 FILE *fp;
 fp  = fopen("input.txt","r"); //텍스트파일을 읽기모드로 열기
 
 if (fp == NULL)//파일 못열면 return 0;으로 프로그램종료
 {
  printf("파일이 열리지 않습니다. 프로그램을 종료합니다.\n");
  system("pause");
   return 0;
 }

 while( !feof(fp)) //파일의 끝날때까지 반복
 {
   fscanf(fp,"%s",buf); //buf에 저장

   insert_node(&head,NULL,create_node(buf,indexcnt++,NULL)); //노드 연결 인덱스
 }
 
 input = (char *) malloc(sizeof(char)*19);
 printf("어떤 단어를 검색하시겠습니까? ");
 gets(input); //단어 입력
 printf("입력된 문자열 : %s\n\n",input);
 display_recur(head, input); //입력된 단어를 넘겨서, 함수로 출력

 free(input); //입력받을떄 사용한 메모리 반환
 fclose(fp); //파일 닫기
 system("pause");
 return 0;
}  
