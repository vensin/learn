#include<stdio.h>
#include<stdlib.h>
#include<malloc.h> 
#include"list2.h"

int main()
{
	int choice=0,n=10,arr[10]={1,3,4,6,4,8,5,7,9,5},index=0,data=5;
	ptr_TNode head,node=(ptr_TNode)malloc(sizeof(TNode));
	node->data=10;
	node->next=NULL;
	do{
	printf("This is a linkedlist\n");
	printf("what you wan to do?\n");
	printf("1-生成  2-删除  3-插入  4-销毁  5-输出链表\n");
	printf("your choice:");
	scanf("%d",&choice);
	system("cls");
	switch(choice)
	{
	case 1:head=create(arr,n);
	     break;
	case 2:printf("%d",delete_T(&head,index,&data));
	     break;
	case 3:printf("%d",insert_T(&head,node,index));
		 break;
	case 4:destroy(head);
		 break;
	case 5:print(head); 
		 break;
	default:printf("error!please input again.");
    }
    printf("按任意键继续");
	getch(); 
	system("cls");
    }while(choice) ;
	return 0;
}
