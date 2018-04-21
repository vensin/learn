#include <stdio.h>
#include <malloc.h>
#include <string.h> 

//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)  //��ʼ��
{
	if(s!=NULL)
	{
	s->elem=(ElemType*)malloc(sizes * sizeof(ElemType));
    s->size=sizes;
    s->top=-1;
    }  
    if((s->elem)!=NULL) return OK;
    else return ERROR;
}


Status isEmptyStack(SqStack *s)   //�ж��Ƿ�Ϊ��
{
    if(s->top==-1) return OK;
	else return ERROR; 
}


Status getTopStack(SqStack *s,ElemType *e)   //�õ�ͷԪ��
{
    if(s->top!=-1)
    {
    	*e=s->elem[s->top];
    	return OK;
	}
	else return ERROR;
}


Status clearStack(SqStack *s)   //���
{
    if(s->top!=-1)
    {
    	s->top=-1;
		return OK;
    }
    else return ERROR;
}


Status destoryStack(SqStack *s)  //����
{
   if(!s->elem)
    {
    	free(s->elem);
    	s->elem=NULL;
    	return OK;
	}
	else return ERROR;
    
}


Status stackLength(SqStack *s,int* length)   //��ⳤ��
{
    if(s->elem!=NULL)
    {
    	*length=s->top+1;
    	printf("length=%d\n",*length);
    	return OK;
	}
	else return ERROR;
}

Status pushStack(SqStack *s,ElemType datas)  //��ջ
{

    if(s->top<(s->size-1))
    {
    	(s->elem)[(s->top)+1]=datas;
    	s->top+=1;
    	return OK;
	}
	else return ERROR;
}

Status popStack(SqStack *s,ElemType *datas)   //��ջ
{
    if(s->top!=-1)
    {
    	*datas=s->elem[s->top];
    	s->top--;
    	return OK;
	}
	else return ERROR; 
}

//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
    s->top=(LinkStackPtr)malloc(sizeof(StackNode));
    s->top->next=NULL;
    if(s->top!=NULL) return OK;
    else return ERROR;
}

Status isEmptyLStack(LinkStack *s)  //�ж������Ƿ�Ϊ��
{
    if(s->top!=NULL)
    {
    	printf("��Ϊ�ա�\n");
    	return OK;
	}
    else return ERROR;
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

Status clearLStack(LinkStack *s)   //�������
{
    LinkStackPtr p;
    if(s->top!=NULL)
    {
    	while(s->top->next!=NULL)
    	{
    	   p=s->top;
    	   s->top=p->next;
    	   free(p);
		}
		return OK;
	}
	else return ERROR;
}

Status destoryLStack(LinkStack *s)   //��������
{
    LinkStackPtr p;
    if(s->top!=NULL)
    {
    	while(s->top!=NULL)
    	{
    	   p=s->top;
    	   s->top=p->next;
    	   free(p);
		}
		s->top=NULL;
		return OK;
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

Status pushLStack(LinkStack *s,ElemType datas)   //��ջ
{
	LinkStackPtr p;
	int n;
	LStackLength(s,&n);
	if(n<s->count)
	{
		p=(LinkStackPtr)malloc(sizeof(StackNode));
		p->data=datas;
		p->next=s->top;
		s->top=p;
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
