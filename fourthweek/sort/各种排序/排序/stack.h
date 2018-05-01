#include <stdio.h>
#include <malloc.h>
#include <string.h>
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status
{
    ERROR = 0,OK = 1
}Status;

typedef int ElemType;


typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack{
	LinkStackPtr top;	  //ջ��ָ��
	int	count;  //ջ��Ԫ�ظ���
}LinkStack;



Status initLStack(LinkStack *s);
Status isEmptyLStack(LinkStack *s);
Status getTopLStack(LinkStack *s,ElemType *e);
Status pushLStack(LinkStack *s,ElemType datas);
Status popLStack(LinkStack *s,ElemType *datas);
Status LStackLength(LinkStack *s,int *length);


Status initLStack(LinkStack *s)   //��ʼ��
{
    s->top=NULL;
    s->count=0;
    if(s!=NULL) return OK;
    else return ERROR;
}

Status isEmptyLStack(LinkStack *s)  //�ж������Ƿ�Ϊ��
{
    if(s->top!=NULL)
    {
    	//printf("��Ϊ��\n");
    	return OK;
	}
    else 
	{
		printf("Ϊ��\n");
		return ERROR;
	}
}

Status getTopLStack(LinkStack *s,ElemType *e)  //�õ�����ͷԪ��
{
    if(s->top!=NULL)
    {
    	*e=s->top->data;
    	return OK;
	}
	else return ERROR;

}
Status pushLStack(LinkStack *s,ElemType datas)   //��ջ
{
	LinkStackPtr p;
	int n;
	LStackLength(s,&n);
	if(n<s->count)
	{
		p=(LinkStackPtr)malloc(sizeof(StackNode));
		p->data=datas;
		if(s->top==NULL)
			s->top=p;
		else{
			p->next=s->top;
		    s->top=p;
		}
		
		return OK;
	}
	else return ERROR;
}

Status popLStack(LinkStack *s,ElemType *datas)   //��ջ
{
	LinkStackPtr p=s->top;
	if(s->top!=NULL)
	{
       *datas=s->top->data;
       s->top=s->top->next;
       free(p);
	}
	else return ERROR;
}
Status LStackLength(LinkStack *s,int *length)    //���������
{
	StackNode* p=s->top;
    *length=0;
    if(s->top!=NULL)
    {
    	while(p!=NULL)
    	{
    		*length++;
    		p=p->next;
		}
		printf("length=%d\n",*length);
		return OK;
	}
	else return ERROR;
}

#endif // STACK_H_INCLUDED
