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

//������������һ��˫�������ɹ��򷵻�ͷ�ڵ㣬ʧ�ܷ��� NULL 
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

//˫������,ɾ���� index λ�ڵ����Ľڵ㣬��ɾ���Ľ���ֵ���浽��*data���� 
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
//˫������,�ڵ� index λ������� node ��� 
//����ɹ����� SUCCESS��ʧ�ܷ��� ERROR 
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
//���ٸ��������� 
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
//��������ֵ����һ���ĸ�ʽ�����ÿ�ж��ٸ��Լ����壬��ʽԽƯ��Խ�ã�
void print(ptr_TNode head)
{
	int i=0;
	ptr_TNode p=head;
	if(head!=NULL)
	while(p!=NULL)
	{
		printf("��%d���ڵ㣺%d\t",i+1,p->data);
		i++;
		p=p->next;
		if(i%5==0) printf("\n");
	}
	else printf("������\n");
}

