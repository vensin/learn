#include<stdio.h>
#include<stdlib.h>
#include<malloc.h> 
#include"list1.h"

int main()
{
	int chioce=0,n=10,arr[10]={1,3,4,6,4,8,5,7,9,5},index=5,data=5;
	ptr_Node head,node=(ptr_Node)malloc(sizeof(Node));
	node->data=10;
	node->next=NULL;
	do{
	printf("This is a linkedlist\n");
	printf("what you wan to do?\n");
	printf("1-生成  2-销毁  3-插入  4-删除  5-查找  6-修改  7-排序  8-输出链表\n");
	printf("your chioce:");
	scanf("%d",&chioce);
	system("cls");
	switch(chioce)
	{
	case 1:head=create(arr,n);
	     break;
	case 2:destroy(&head);
	     break;
	case 3:printf("%d",insert(&head,node,index));
		 break;
	case 4:printf("%d",Delete(&head,index,&data));
		 break;
	case 5:printf("%d",search(head,data));
		 break;
	case 6:printf("%d",edit(head,index,&data));
		 break;
	case 7:printf("%d",sort(&head));
		 break;
	case 8:print(head);
		 break;
	default:printf("error!please input again.");
    }
    printf("\n按任意键继续");
	getch(); 
	system("cls");
    }while(chioce) ;
	return 0;
}
