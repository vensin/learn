#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "queue1.h" 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,m,*data,e;
	AQueue q;
	AQueue *Q1=&q;
	LQueue p;
	LQueue *Q2=&p;
	void (*foo1)(void *q),(*foo2)(void *q);;
	foo1=APrint;
	foo2=LPrint;
	do
	{
	   printf("技术所限赋值只能为int型数据！\n");
	   printf("1-创建一个循环队列    2-创建一个链队列\n" );
	   printf("your chioce:");
       scanf("%d",&n);
	   do{ 
	   	if(n==1)
	   	{
	   		system("CLS");
	   	 	printf("0-返回\n");
			printf("1-初始化队列\n");
			printf("2-销毁队列\n");
			printf("3-检查队列是否为空\n");
			printf("4-查看队头元素\n");
			printf("5-确定队列长度\n");
			printf("6-入队\n");
			printf("7-出队\n");
			printf("8-清空队列\n");
			printf("9-遍历函数\n");
			printf("10-检查队列是否已满\n");
		}
		else if(n==2)
		{
			system("CLS");
	   	 	printf("0-返回\n");
			printf("1-初始化队列\n");
			printf("2-销毁队列\n");
			printf("3-检查队列是否为空\n");
			printf("4-查看队头元素\n");
			printf("5-确定队列长度\n");
			printf("6-入队\n");
			printf("7-出队\n");
			printf("8-清空队列\n");
			printf("9-遍历函数\n");
		}
		else
		{
			system("CLS");
			printf("error!please input again!\n");
			continue;
		}
		printf("your chioce:");
        scanf("%d",&m);
        system("CLS");
		if(n==1)
		{
			switch(m)
			{
				case 0:break; 
				case 1:	Q1=&q;
						InitAQueue(Q1);
				       break;
			    case 2:DestoryAQueue(Q1);
			           Q1=NULL;
			           break;
			    case 3:printf("%d",IsEmptyAQueue(Q1));
			           break;
			    case 4:printf("%d",GetHeadAQueue(Q1,&e));
			    	   if(!GetHeadAQueue(Q1,&e))	break;
			           printf("队头元素为%d\n",e);
			           break;
			    case 5:if(LengthAQueue(Q1)==-1)	break;
				       printf("队列长度为%d",LengthAQueue(Q1));
			           break;
			    case 6:printf("请输入一个整数！\n");
			    	   data=(int *)malloc(sizeof(int));
					   scanf("%d",data);
				       printf("%d",EnAQueue(Q1,data));
			           break;
			    case 7:printf("%d",DeAQueue(Q1));
			           break;
			    case 8:ClearAQueue(Q1);
			           break;
			    case 9:printf("%d",TraverseAQueue(Q1,foo1));
			           break;
			    case 10:printf("%d",IsFullAQueue(Q1));
			    	   break;
			    default:printf("this choice is unvaluably");
			}
		}else if(n==2)
		{
			switch(m)
			{
				case 0:break; 
				case 1:Q2=&p;
					   InitLQueue(Q2);
				       break;
			    case 2:DestoryLQueue(Q2);
			    	   Q2=NULL; 
			           break;
			    case 3:printf("%d",IsEmptyLQueue(Q2));
			           break;
			    case 4:if(!GetHeadLQueue(Q2,&e))	break;
				       printf("%d",GetHeadLQueue(Q2,&e));
			    	   printf("队头元素为%d\n",e);
			           break;
			    case 5:if(LengthLQueue(Q2)>=0) 
				       printf("队列长度为%d",LengthLQueue(Q2));
			           break;
			    case 6:printf("请输入一个整数！\n");
			    	   data=(int *)malloc(sizeof(int)); 
					   scanf("%d",data);
				       printf("%d",EnLQueue(Q2,data));
			           break;
			    case 7:printf("%d",DeLQueue(Q2));
			           break;
			    case 8:ClearLQueue(Q2);
			           break;
			    case 9:printf("%d",TraverseLQueue(Q2,foo2));
			           break;
			    default:printf("this choice is unvaluably");
			}
		}
		else if(n==3) ;
		else
		{
			printf("ERROR!please input again");
		}
		if(!m)break;
	    getch();
	    data=NULL;
	  }while (1);
    }while(1) ;
	return 0;
}
