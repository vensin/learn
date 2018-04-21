#include<stdio.h>
#include<stdlib.h>
#include<malloc.h> 

typedef struct TNode 
{ 
	int data; 
	struct TNode *next;
	struct TNode *pre;
}TNode, *ptr_TNode;

typedef enum Status 
{
	SUCCESS,
	ERROR 
}Status;

//根据数组生成一条双向链表，成功则返回头节点，失败返回 NULL 
ptr_TNode create(int *arr, int n)
{
   int i;
	ptr_TNode head=(ptr_TNode)malloc(sizeof(TNode)),p=head;
	if(head!=NULL)
	{
	 head->pre=NULL;
	 for(i=0;i<n;i++)
	 {
	    p->data=*(arr+i);
	    if(i==n-1)
	    {
	    	p->next=NULL;
	    	break;
		}
	    p->next=(ptr_TNode)malloc(sizeof(TNode));
	    p->next->pre=p; 
	    p=p->next;
	 }
    }
	else return NULL; 
	return head;	
}

//双向链表,删除第 index 位节点后面的节点，将删除的结点的值保存到（*data）中 
Status delete_T(ptr_TNode *head, int index, int *data)
{
	ptr_TNode p=*head,q;
	int i=1;
	if(*head!=NULL)
	{
		if(index==0)
		{
			q=*head;
		    *head=(*head)->next;
		    (*head)->pre=NULL;
			*data=q->data;
			free(q);
		 } 
		else
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
//双向链表,在第 index 位后面插入 node 结点 
//插入成功返回 SUCCESS，失败返回 ERROR 
Status insert_T(ptr_TNode *head, ptr_TNode node, int index)
{
	ptr_TNode p=*head,q;
	int i=1;
	if(*head!=NULL)
	{
	 while(p!=NULL)
	  {
		if(i==index)
		{
		   q=p->next;
		   node->next=q;
		   node->pre=p;
		   p->next=node;
		   q->pre=node;
		   break;
		}
		p=p->next;
		i++;
      }
    return SUCCESS;
    }
	return ERROR;
}
//销毁给定的链表 
void destroy(ptr_TNode head)
{
	ptr_TNode p;
    while(head!=NULL)
    {
    	p=head;
    	head=head->next;
    	free(p);
	}
}
//将链表结点值按照一定的格式输出（每行多少个自己定义，格式越漂亮越好）
void print(ptr_TNode head)
{
	int i=0;
	ptr_TNode p=head;
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

