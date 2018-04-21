#include<stdio.h>
#include<stdlib.h>
#include<malloc.h> 
typedef struct Node 
{ int data; 
  struct Node *next; 
}Node, *ptr_Node;

typedef enum Status 
{ 
	SUCCESS, 
	ERROR 
}Status;
//根据数组生成一条链表，成功则返回头节点，失败返回 NULL 
ptr_Node create(int *arr,int n)
{
	int i;
	ptr_Node head=(ptr_Node)malloc(sizeof(Node)),p=head;
	if(head!=NULL)
	for(i=0;i<n;i++)
	{
	    p->data=*(arr+i);
	    if(i==n-1)
	    {
	    	p->next=NULL;
	    	break;
		}
	    p->next=(ptr_Node)malloc(sizeof(Node));
	    p=p->next;
	}
	else return NULL; 
	return head;
}
//销毁给定的链表 
/*void destroy(ptr_Node head)
{
	ptr_Node p=head;
	if(head!=NULL)
    while(p!=NULL)
    {
    	p=p->next;
    	free(head);
    	head=p;
	}
	if(head==NULL)
	printf("destroy success\n");
	else printf("destroy error\n");
} */
void destroy(ptr_Node *head)
{
	ptr_Node p,q=*head;
	if(*head!=NULL)
    while(q!=NULL)
    {
    	p=q;
    	q=q->next;
    	free(p);
	}
	*head=NULL;
	if(*head==NULL)
	printf("destroy success\n");
	else printf("destroy error\n");
}

//在第 index 位后面插入 node 结点 
//插入成功返回 SUCCESS，失败返回 ERROR 
Status insert(ptr_Node *head, ptr_Node node, int index)
{
	ptr_Node p=*head,q;
	int i=1;
	if(*head!=NULL)
	{
	 while(p!=NULL)
	  {
		if(i==index)
		{
		   q=p->next;
		   node->next=q;
		   p->next=node;
		   break;
		}
		p=p->next;
		i++;
      }
    return SUCCESS;
    }
	return ERROR;
}

//删除第 index 位节点后面的节点，将删除的结点的值保存到（*data）中 
//删除成功返回 SUCCESS，其他情况返回 ERROR 
Status Delete(ptr_Node *head, int index, int *data)
{
	ptr_Node p=*head,q;
	int i=1;
	if(*head!=NULL)
	{
	while(p!=NULL)
	{
		if(i==index&&p->next!=NULL)
		{
		    q=p->next;
			*data=q->data;
			p->next=q->next;
			free(q);
			break;
		}
		p=p->next;
		i++; 
	}
	return SUCCESS;
    }
	return ERROR;
}


//在链表中查找节点值与 data 相等的节点，并返回找到的第一个节点的前一个节点的位置 
//（例：头节点相等，返回 0），没找到或者其他情况返回-1
int search(ptr_Node head, int data)
{
	ptr_Node p=head;
	int i=1;
	if(head!=NULL)
	{
	 if(head->data==data) return 0;
	 while(p!=NULL)
	 {
		if(p->next->data==data)
		{
		   return i;
		   break;
		}
		p=p->next;
		i++;
	 }
    }
    return -1;
}


//将链表中 index 位点后面的结点的值修改为(*data)，将原值保存到(*data) 
//修改成功返回 SUCCESS，其他情况返回 ERROR 
Status edit(ptr_Node head, int index, int *data)
{
	ptr_Node p=head;
	int i=1,temp;
	if(head!=NULL)
	{
	 while(p!=NULL)
	 {
		if(i==index)
		{
		   temp=p->next->data;
		   p->next->data=*data;
		   *data=temp;
		   return SUCCESS;
		   break;
		}
		p=p->next;
		i++;
	 }
    }
	return ERROR;
}

//此题选做,实现单链表按照节点值大小升序排序 
Status sort(ptr_Node *head)
{
	int temp;
	ptr_Node p,q=*head,min;
   	if(*head==NULL||(*head)->next==NULL) return ERROR;
   	while(q!=NULL)
   	{
   		p=q;
   		min=q;
   		while(p!=NULL)
   		{
   			if(p->data<min->data)
   			min=p;
   			p=p->next;
		}
		temp=min->data;
		min->data=q->data;
		q->data=temp;
		q=q->next;
	}
	return SUCCESS;
}

//将链表结点值按照一定的格式输出（每行多少个自己定义，格式越漂亮越好） 
void print(ptr_Node head)
{
	int i=0;
	ptr_Node p=head;
	if(head!=NULL)
	while(p!=NULL)
	{
		printf("第%d个节点：%d\t",i+1,p->data);
		i++;
		p=p->next;
		if(i%5==0) printf("\n");
	}
	else printf("空链表\n"); 
}

