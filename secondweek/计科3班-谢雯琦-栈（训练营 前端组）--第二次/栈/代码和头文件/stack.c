#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "stack.h"
#include "calculate.h" 

//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化
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


Status isEmptyStack(SqStack *s)   //判断是否为空
{
    if(s->top==-1) return OK;
	else return ERROR; 
}


Status getTopStack(SqStack *s,ElemType *e)   //得到头元素
{
    if(s->top!=-1)
    {
    	*e=s->elem[s->top];
    	return OK;
	}
	else return ERROR;
}


Status clearStack(SqStack *s)   //清空
{
    if(s->top!=-1)
    {
    	s->top=-1;
		return OK;
    }
    else return ERROR;
}


Status destoryStack(SqStack *s)  //销毁
{
   if(!s->elem)
    {
    	free(s->elem);
    	s->elem=NULL;
    	return OK;
	}
	else return ERROR;
    
}


Status stackLength(SqStack *s,int* length)   //检测长度
{
    if(s->elem!=NULL)
    {
    	*length=s->top+1;
    	printf("length=%d\n",*length);
    	return OK;
	}
	else return ERROR;
}

Status pushStack(SqStack *s,ElemType datas)  //入栈
{

    if(s->top<(s->size-1))
    {
    	(s->elem)[(s->top)+1]=datas;
    	s->top+=1;
    	return OK;
	}
	else return ERROR;
}

Status popStack(SqStack *s,ElemType *datas)   //出栈
{
    if(s->top!=-1)
    {
    	*datas=s->elem[s->top];
    	s->top--;
    	return OK;
	}
	else return ERROR; 
}

//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
    s->top=(LinkStackPtr)malloc(sizeof(StackNode));
    s->top->next=NULL;
    if(s->top!=NULL) return OK;
    else return ERROR;
}

Status isEmptyLStack(LinkStack *s)  //判断链表是否为空
{
    if(s->top!=NULL)
    {
    	printf("不为空。\n");
    	return OK;
	}
    else return ERROR;
}

Status getTopLStack(LinkStack *s,ElemType *e)  //得到链表头元素
{
    if(s->top!=NULL)
    {
    	*e=s->top->data;
    	return OK;
	}
	else return ERROR;

}

Status clearLStack(LinkStack *s)   //清空链表
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

Status destoryLStack(LinkStack *s)   //销毁链表
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

Status LStackLength(LinkStack *s,int *length)    //检测链表长度
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

Status pushLStack(LinkStack *s,ElemType datas)   //入栈
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

Status popLStack(LinkStack *s,ElemType *datas)   //出栈
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
void main()
{
	int n,m=0,sizes=8,length,sum; 
	SqStack  a,*s=&a;
	LinkStack b,*h=&b;
	ElemType e,datas=20;
	s->elem=NULL;
	do
	{
	   printf("1-创建一个顺序栈    2-创建一个链栈\n" );
	   printf("your chioce:");
       scanf("%d",&n);
      
	   system("CLS");
	   do{ 
	   	if(n==3)
		{
			char str1[20];
			printf("请输入一个少于20字符的表达式\n");
			scanf("%s",str1);
			sum=calculate(str1);
			printf("结果为%d\n",sum);
			break;
		 } 
	   	system("CLS");
	    printf("0-返回\n");
		printf("1-初始化\n");
		printf("2-判断是否为空\n");
		printf("3-得到头元素\n");
		printf("4-清空\n");
		printf("5-销毁\n");
		printf("6-检测长度\n");
		printf("7-入栈\n");
		printf("8-出栈\n");
		printf("your chioce:");
        scanf("%d",&m);
        system("CLS");
		if(n==1)
		{
			switch(m)
			{
				case 0:break; 
				case 1:printf("%d",initStack(s,sizes));
				       break;
			    case 2: printf("%d",isEmptyStack(s));
			           break;
			    case 3:printf("%d",getTopStack(s,&e));
			           break;
			    case 4:printf("%d",clearStack(s));
			           break;
			    case 5:printf("%d",destoryStack(s));
			           break;
			    case 6:printf("%d",stackLength(s,&length));
			           break;
			    case 7:printf("%d",pushStack(s,datas));
			           break;
			    case 8:printf("%d",popStack(s,&datas));
			           break;
			    default:printf("this chioce is unvaluably");
			}
		}else if(n==2)
		{
			switch(m)
			{
				case 0:break; 
				case 1:printf("%d",initLStack(h));
				       break;
			    case 2: printf("%d",isEmptyLStack(h));
			           break;
			    case 3:printf("%d",getTopLStack(h,&e));
			           break;
			    case 4:printf("%d",clearLStack(h));
			           break;
			    case 5:printf("%d",destoryLStack(h));
			           break;
			    case 6:printf("%d",LStackLength(h,&length));
			           break;
			    case 7:printf("%d",pushLStack(h, datas));
			           break;
			    case 8:printf("%d",popLStack(h,&datas));
			           break;
			    default:printf("this chioce is unvaluably");
			}
		}
		else if(n==3) ;
		else
		{
			printf("ERROR!please input again");
		}
		if(!m)break;
	    getch();
	  }while (1);
    }while(1) ;
 } 
