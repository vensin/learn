#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "queue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void InitAQueue(AQueue *Q)//创建队列 front,rear初始值为-1 
{
	int i=0;
	if(Q!=NULL&&Q->data!=NULL)
	{
		for(i;i<MAXQUEUE;i++)
		Q->data[i]=NULL;
		Q->front=-1;
		Q->rear=-1;
		Q->data_size=0;
		printf("创建成功！\n"); 
	}
	else
		printf("创建失败！\n"); 
}

void InitLQueue(LQueue *Q)
{
	if(Q!=NULL)
	{
		Q->front=NULL;
		Q->rear=NULL;
		Q->data_size=0;
		printf("创建成功！\n");
	}
	else 
		printf("创建失败！\n"); 
}

void DestoryAQueue(AQueue *Q)//销毁队列 
{
	int i=0,flag=1;
	if(Q==NULL)
	{
		printf("队列不存在\n");
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
		printf("销毁成功！\n");
	else 
		printf("销毁失败！\n");
}

void DestoryLQueue(LQueue *Q)
{
	Node *p;
	if(Q==NULL)
	{
		printf("队列不存在\n");
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
		printf("销毁成功！\n"); 
	}
	else printf("销毁失败！\n");
}

Status IsFullAQueue(const AQueue *Q)//检查队列是否已满
{
	int flag=0;
	if(Q==NULL)
	{
		printf("队列不存在\n");
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
		printf("已满\n");
		return TRUE;
	}

	else
		{
		printf("未满\n");
		return FLASE;
	}
}

Status IsEmptyAQueue(const AQueue *Q)//检查是否为空
{
	if(Q!=NULL)
	{
		if(Q->front==-1&&Q->rear==-1)
		{ 
	    printf("为空！\n");
		return  TRUE;
		}
		else
		{
	    printf("不为空！\n");
		return FLASE;	
		}
	}
	else
	{
		printf("队列不存在\n");
		return FLASE;
	}
} 

Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q==NULL)
	{
		printf("队列不存在\n");
		return FLASE;
	}
	if(Q->front==NULL)
	{
		printf("为空！\n");
		return  TRUE;
	}
	else 
	{
	    printf("不为空！\n");
		return FLASE;	
	}
}

Status GetHeadAQueue(AQueue *Q, void *e)//查看头元素
{
	if(Q==NULL)
	{
		printf("该队列不存在！\n");
		return FLASE;
	}
	if(!IsEmptyAQueue(Q))
	{
		*(int *)e=*(int *)Q->data[Q->front];
		return TRUE;
	}
	else 
	{
		printf("错误!\n") ;
		return FLASE;
	}
}
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(Q->front!=NULL)
	{
		*(int *)e=*(int *)Q->front->data;
		printf("--%d***\n",*(int *)Q->front->data);//赋值就好想出问题了 
	
		return TRUE;
	}
	else
		{
		printf("错误!\n") ;
		return FLASE;
	}
}

int LengthAQueue(AQueue *Q)//确定队列长度
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
	 	printf("队列不存在\n");
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

Status EnAQueue(AQueue *Q, void *data)//入队
{
	if(Q==NULL)
	{
		printf("队列不存在\n");
		return FLASE;
	}
	if(IsFullAQueue(Q))
	{
	printf("失败\n") ;	
	return FLASE;
	}
	else if(IsEmptyAQueue(Q))
	{
		Q->data[0]=data;
		Q->front=0;
		Q->rear=0;
		Q->data_size=1;
		system("CLS");
		printf("成功\n") ;
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
		printf("成功\n") ;
		return TRUE;
	}
 } 
 
 Status EnLQueue(LQueue *Q, void *data)//入队的 
 {	
 	if(Q==NULL)
	{
		printf("队列不存在\n");
		return FLASE;
	}
 	if(IsEmptyLQueue(Q))
 	{
 		Q->front=(Node*)malloc(sizeof(Node));
 		Q->front->data=data;
		printf("头元素为%d\n",*(int *)Q->front->data);
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
	 	printf("一样的"); 
	 	printf("头元素为%d",*(int *)Q->front->data);
	 	printf("尾元素为%d",*(int *)Q->rear->data);
	 	printf("成功\n") ;
	 	return TRUE;
	 }
	 else
	 {
	 	printf("失败\n") ;
	 	return FLASE;
	 }
 }
 
 Status DeAQueue(AQueue *Q)//出队
 {
 	if(Q==NULL)
	{
		printf("队列不存在\n");
		return FLASE;
	}
 	if(IsEmptyAQueue(Q))
 	{
	 	printf("失败\n") ;
	 	return FLASE;
	 }
	else
	{
		if(Q->front>=MAXQUEUE)
			Q->front=0;
		Q->data[Q->front]=NULL;
		Q->front++;
		Q->data_size--; 
		printf("成功\n") ;
	 	return TRUE;
	}
} 

Status DeLQueue(LQueue *Q)
{
	if(Q==NULL)
	{
		printf("队列不存在\n");
		return FLASE;
	}
	Node *p;
	if(!IsEmptyLQueue(Q)) 
	{
		p=Q->front;
		Q->front=Q->front->next;
		free(p);
		Q->data_size--;
		printf("头元素为%d",*(int *)Q->front->data);
		printf("成功\n") ;
	 	return TRUE;
	}
	else {
	 	printf("失败\n") ;
	 	return FLASE;
	 }
}

void ClearAQueue(AQueue *Q)//清空队列
{
	int i=0,flag=1;
	if(Q==NULL)
	{
		printf("队列不存在\n");
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
		printf("清空成功！\n");
	else 
		printf("清空失败！\n");
} 

void ClearLQueue(LQueue *Q)
{

  	Node *p=NULL;
	if(Q==NULL)
	 printf("队列不存在\n");
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
		printf("清空成功！\n");
	}
	else
		printf("ERROR\n");
} 

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))//遍历
{
	int i=Q->front,j;
	if(Q==NULL)
	{
		printf("该队列不存在！\n");
		return FLASE;
	}
	if(Q!=NULL&&!IsEmptyAQueue(Q))
	{	
		for(j=1;j<=Q->data_size;i++,j++)
		{
			if(i>=MAXQUEUE)
				i=0;
			printf("第%d个节点为:",j);
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
		printf("该队列不存在！\n");
		return FLASE;
	}
	else if(!IsEmptyLQueue(Q))
	{
		p=Q->front;
		while(p!=NULL)
		{
			
			printf("第%d个节点为:",i);
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
