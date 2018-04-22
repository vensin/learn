#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "queue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void InitAQueue(AQueue *Q)//�������� front,rear��ʼֵΪ-1 
{
	int i=0;
	if(Q!=NULL&&Q->data!=NULL)
	{
		for(i;i<MAXQUEUE;i++)
		Q->data[i]=NULL;
		Q->front=-1;
		Q->rear=-1;
		Q->data_size=0;
		printf("�����ɹ���\n"); 
	}
	else
		printf("����ʧ�ܣ�\n"); 
}

void InitLQueue(LQueue *Q)
{
	if(Q!=NULL)
	{
		Q->front=NULL;
		Q->rear=NULL;
		Q->data_size=0;
		printf("�����ɹ���\n");
	}
	else 
		printf("����ʧ�ܣ�\n"); 
}

void DestoryAQueue(AQueue *Q)//���ٶ��� 
{
	int i=0,flag=1;
	if(Q==NULL)
	{
		printf("���в�����\n");
		flag=0;
	}
	else
	{
		for(;i<MAXQUEUE;i++)
		{
		Q->data[i]=NULL;
		}
	i=0;
	while(i<MAXQUEUE)
	    {
	    	if(Q->data[i]!=NULL)
	      	{
	      		flag=0;
	      		printf("emmm");
	      	    break;
			}
			i++;
		}
	}
	if(flag)
		printf("���ٳɹ���\n");
	else 
		printf("����ʧ�ܣ�\n");
}

void DestoryLQueue(LQueue *Q)
{
	Node *p;
	if(Q==NULL)
	{
		printf("���в�����\n");
	}
	else if(Q->front!=NULL)
	{
		while(Q->front!=Q->rear)
		{
		p=Q->front;
		Q->front=Q->front->next; 
		free(p->data);
		free(p);
		}
		Q->rear=NULL;
		free(Q->front);
		Q->front=NULL;
		printf("���ٳɹ���\n"); 
	}
	else printf("����ʧ�ܣ�\n");
}

Status IsFullAQueue(const AQueue *Q)//�������Ƿ�����
{
	int flag=0;
	if(Q==NULL)
	{
		printf("���в�����\n");
		return FLASE; 
	}
 	if(Q->front<Q->rear)
 	
 		if(Q->rear-Q->front+1==MAXQUEUE)
 			flag=1;
	
	else if(Q->front>Q->rear)
	
		if(Q->rear+1==Q->front)
		flag=1;
	
	else
		flag=0;
	if(flag)
	{
		printf("����\n");
		return TRUE;
	}

	else
		{
		printf("δ��\n");
		return FLASE;
	}
}

Status IsEmptyAQueue(const AQueue *Q)//����Ƿ�Ϊ��
{
	if(Q!=NULL)
	{
		if(Q->front==-1&&Q->rear==-1)
		{ 
	    printf("Ϊ�գ�\n");
		return  TRUE;
		}
		else
		{
	    printf("��Ϊ�գ�\n");
		return FLASE;	
		}
	}
	else
	{
		printf("���в�����\n");
		return FLASE;
	}
} 

Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q==NULL)
	{
		printf("���в�����\n");
		return FLASE;
	}
	if(Q->front==NULL)
	{
		printf("Ϊ�գ�\n");
		return  TRUE;
	}
	else 
	{
	    printf("��Ϊ�գ�\n");
		return FLASE;	
	}
}

Status GetHeadAQueue(AQueue *Q, void *e)//�鿴ͷԪ��
{
	if(Q==NULL)
	{
		printf("�ö��в����ڣ�\n");
		return FLASE;
	}
	if(!IsEmptyAQueue(Q))
	{
		*(int *)e=*(int *)Q->data[Q->front];
		return TRUE;
	}
	else 
	{
		printf("����!\n") ;
		return FLASE;
	}
}
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(Q->front!=NULL)
	{
		*(int *)e=*(int *)Q->front->data;
		printf("--%d***\n",*(int *)Q->front->data);//��ֵ�ͺ���������� 
	
		return TRUE;
	}
	else
		{
		printf("����!\n") ;
		return FLASE;
	}
}

int LengthAQueue(AQueue *Q)//ȷ�����г���
{
	if(Q!=NULL)
	
		if(Q->front<Q->rear)
			return Q->rear-Q->front+1;
		else if(Q->front>Q->rear)
			return MAXQUEUE-Q->front+Q->rear+1;
		else if(Q->front==-1&&Q->rear==-1)
			return 0;
		else 
			return 1;
	else 
	 {
	 	printf("���в�����\n");
	 	return -1;
	 }
} 

int LengthLQueue(LQueue *Q)
{
	int count=0;
	Node *p=Q->front;
	if(Q!=NULL)
	{
		while(p!=NULL)
		{
	   		count++;
	   		p=p->next;
		}
		return count;
	}
	else
		return -1;
}

Status EnAQueue(AQueue *Q, void *data)//���
{
	if(Q==NULL)
	{
		printf("���в�����\n");
		return FLASE;
	}
	if(IsFullAQueue(Q))
	{
	printf("ʧ��\n") ;	
	return FLASE;
	}
	else if(IsEmptyAQueue(Q))
	{
		Q->data[0]=data;
		Q->front=0;
		Q->rear=0;
		Q->data_size=1;
		system("CLS");
		printf("�ɹ�\n") ;
		return TRUE;
	}
	else
	{
		if(Q->rear==MAXQUEUE-1) 
		{
			Q->rear==0;
			Q->data[Q->rear]=data;
			Q->data_size++;
		}
		else
		{
			Q->rear++;
			Q->data[Q->rear]=data;
			Q->data_size++;
		}
		system("CLS");
		printf("�ɹ�\n") ;
		return TRUE;
	}
 } 
 
 Status EnLQueue(LQueue *Q, void *data)//��ӵ� 
 {	
 	if(Q==NULL)
	{
		printf("���в�����\n");
		return FLASE;
	}
 	if(IsEmptyLQueue(Q))
 	{
 		Q->front=(Node*)malloc(sizeof(Node));
 		Q->front->data=data;
		printf("ͷԪ��Ϊ%d\n",*(int *)Q->front->data);
 		Q->front->next=NULL;
 		Q->rear=Q->front;
 		Q->data_size=1;
	 }
	 else
	 {
	 	Q->rear->next=(Node*)malloc(sizeof(Node));
	 
	 	Q->rear=Q->rear->next;
	 	Q->rear->data=data;
	 	Q->rear->next=NULL;
	 	Q->data_size++;
	 	printf("omg");
	 }
	 //system("CLS");
	 if(Q->rear!=NULL)
	 {
	 	if(Q->front==Q->rear)
	 	printf("һ����"); 
	 	printf("ͷԪ��Ϊ%d",*(int *)Q->front->data);
	 	printf("βԪ��Ϊ%d",*(int *)Q->rear->data);
	 	printf("�ɹ�\n") ;
	 	return TRUE;
	 }
	 else
	 {
	 	printf("ʧ��\n") ;
	 	return FLASE;
	 }
 }
 
 Status DeAQueue(AQueue *Q)//����
 {
 	if(Q==NULL)
	{
		printf("���в�����\n");
		return FLASE;
	}
 	if(IsEmptyAQueue(Q))
 	{
	 	printf("ʧ��\n") ;
	 	return FLASE;
	 }
	else
	{
		if(Q->front>=MAXQUEUE)
			Q->front=0;
		Q->data[Q->front]=NULL;
		Q->front++;
		Q->data_size--; 
		printf("�ɹ�\n") ;
	 	return TRUE;
	}
} 

Status DeLQueue(LQueue *Q)
{
	if(Q==NULL)
	{
		printf("���в�����\n");
		return FLASE;
	}
	Node *p;
	if(!IsEmptyLQueue(Q)) 
	{
		p=Q->front;
		Q->front=Q->front->next;
		free(p);
		Q->data_size--;
		printf("ͷԪ��Ϊ%d",*(int *)Q->front->data);
		printf("�ɹ�\n") ;
	 	return TRUE;
	}
	else {
	 	printf("ʧ��\n") ;
	 	return FLASE;
	 }
}

void ClearAQueue(AQueue *Q)//��ն���
{
	int i=0,flag=1;
	if(Q==NULL)
	{
		printf("���в�����\n");
		flag=0;
	}
	else
	{
		for(;i<MAXQUEUE;i++)
	{
		Q->data[i]=NULL;
	}
	i=0;
	while(i<MAXQUEUE)
	    {
	    	if(Q->data[i]!=NULL)
	      	{
	      		flag=0;
	      	    break;
			}
			i++;
		}
	}
	if(flag)
		printf("��ճɹ���\n");
	else 
		printf("���ʧ�ܣ�\n");
} 

void ClearLQueue(LQueue *Q)
{

  	Node *p=NULL;
	if(Q==NULL)
	 printf("���в�����\n");
	else if(Q->front!=NULL)
	{
		while(Q->front!=Q->rear)
		{
		p=Q->front;
		Q->front=Q->front->next; 
		free(p->data);
		free(p);
		}
		Q->rear=NULL;
		free(Q->front);
		Q->front=NULL;
		printf("��ճɹ���\n");
	}
	else
		printf("ERROR\n");
} 

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))//����
{
	int i=Q->front,j;
	if(Q==NULL)
	{
		printf("�ö��в����ڣ�\n");
		return FLASE;
	}
	if(Q!=NULL&&!IsEmptyAQueue(Q))
	{	
		for(j=1;j<=Q->data_size;i++,j++)
		{
			if(i>=MAXQUEUE)
				i=0;
			printf("��%d���ڵ�Ϊ:",j);
			(*foo)(Q->data[i]);
		}
		return TRUE;
	}
	else return FLASE;
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	Node *p;
	int i=1;
	if(Q==NULL)
	{
		printf("�ö��в����ڣ�\n");
		return FLASE;
	}
	else if(!IsEmptyLQueue(Q))
	{
		p=Q->front;
		while(p!=NULL)
		{
			
			printf("��%d���ڵ�Ϊ:",i);
			(*foo)(p->data);
			i++;
			p=p->next;	
		}
		return TRUE;
	}
	else
	{
		printf("ERROR!\n");
		return FLASE;
	}
}

void APrint(void *q)
{
 	printf("%d\n",*(int *)q);
}

void LPrint(void *q)
{
	printf("%d\n",*(int *)q);
}
