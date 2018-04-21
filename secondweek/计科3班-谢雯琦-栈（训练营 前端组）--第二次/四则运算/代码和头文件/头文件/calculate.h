#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
typedef enum Status
{
    ERROR = 0,OK = 1
}Status;

typedef int ElemType;

typedef struct SqStack{
       ElemType	*elem;
       int top;      //用于栈顶指针
       int size;
}SqStack;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack{
	LinkStackPtr top;	  //栈顶指针
	int	count;  //栈中元素个数
}LinkStack;


Status initStack(SqStack *s,int sizes);
Status isEmptyStack(SqStack *s);
Status getTopStack(SqStack *s,ElemType *e);
Status clearStack(SqStack *s);
Status destoryStack(SqStack *s);
Status stackLength(SqStack *s,int *length);
Status pushStack(SqStack *s,ElemType datas);
Status popStack(SqStack *s,ElemType *datas);


Status initLStack(LinkStack *s);
Status isEmptyLStack(LinkStack *s);
Status getTopLStack(LinkStack *s,ElemType *e);
Status clearLStack(LinkStack *s);
Status destoryLStack(LinkStack *s);
Status LStackLength(LinkStack *s,int *length);
Status pushLStack(LinkStack *s,ElemType datas);
Status popLStack(LinkStack *s,ElemType *datas);



int calculate(char *str1)
{
	int n=strlen(str1),i=0,e,temp1,temp2,sum;
	Status flag;
	char str[n],*p=str1;
	SqStack *s;
	flag=initStack(s,n);//初始化 
	if(!flag) printf("ERROR\n");
	while(*p)  //中缀转后缀 
	{
	   if(*p>='0'&&*p<='9')	
	   {
	   	 str[i]=*p;
	   	 i++;
	   }
	   else
	   {
	   	  if(s->top==-1)
	   	    {
	   	    flag=pushStack(s,*p);
			}
	   	  
		  else if(*p=='(')
	   	    flag=pushStack(s,*p);
	   	  
		  else if(*p==')')
	   	  {
	   		
			   while(*(str+i)!='(')
	   		   {
	   			    flag=popStack(s,str+i);
	   		    	i++;
	           }
	           flag=getTopStack(s,&e);
	           if(e=='(')
			        flag=popStack(s,&e);
		  }
		  else if(*p=='+'||*p=='-')
		  {
		  	    flag=getTopStack(s,&e);
		        while(e=='*'||e=='/'||e=='+'||e=='-')
		     	{
				    flag=popStack(s,str+i);
	   			    i++;
	   			    if(isEmptyStack(s))
	   			    break;
				    flag=getTopStack(s,&e);
			    }
			    flag=pushStack(s,*p);
		  }
		  
		  else 
		  {
		  	flag=pushStack(s,*p);
		  }
	   }
	   
	   if(!flag)
	   {
	   	    printf("ERROR");
	     	break;
	   }
	   p++;
	} 
	while(isEmptyStack(s)==0)//栈不为空，全部输出 
	{
		flag=popStack(s,str+i);
		i++;
	}
	*(str+i)='\0'; 
	getch();
	system("CLS");
	p=str;
	s->top=-1; 
	while(*p<'0'||*p>'9')
		p++;
	while(*p)
	{ 
		if(*p>='0'&&*p<='9')
		{
		flag=pushStack(s,*p-'0');
		}
		else
		{
			flag=popStack(s,&temp1);
			flag=popStack(s,&temp2);
			if(*p=='+')
			sum=temp1+temp2;
			
			else if(*p=='-')
			sum=temp2-temp1;
			
			else if(*p=='*')
			sum=temp1*temp2;
			
			else sum=temp2/temp1;
			
			flag=pushStack(s,sum);
		}
			p++;
	}
	flag=getTopStack(s,&sum);
	return sum;
}

#endif // STACK_H_INCLUDED
