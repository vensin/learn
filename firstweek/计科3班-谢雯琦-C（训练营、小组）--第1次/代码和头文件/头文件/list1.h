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
//������������һ�������ɹ��򷵻�ͷ�ڵ㣬ʧ�ܷ��� NULL 
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
//���ٸ��������� 
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

//�ڵ� index λ������� node ��� 
//����ɹ����� SUCCESS��ʧ�ܷ��� ERROR 
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

//ɾ���� index λ�ڵ����Ľڵ㣬��ɾ���Ľ���ֵ���浽��*data���� 
//ɾ���ɹ����� SUCCESS������������� ERROR 
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


//�������в��ҽڵ�ֵ�� data ��ȵĽڵ㣬�������ҵ��ĵ�һ���ڵ��ǰһ���ڵ��λ�� 
//������ͷ�ڵ���ȣ����� 0����û�ҵ����������������-1
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


//�������� index λ�����Ľ���ֵ�޸�Ϊ(*data)����ԭֵ���浽(*data) 
//�޸ĳɹ����� SUCCESS������������� ERROR 
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

//����ѡ��,ʵ�ֵ������սڵ�ֵ��С�������� 
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

//��������ֵ����һ���ĸ�ʽ�����ÿ�ж��ٸ��Լ����壬��ʽԽƯ��Խ�ã� 
void print(ptr_Node head)
{
	int i=0;
	ptr_Node p=head;
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

