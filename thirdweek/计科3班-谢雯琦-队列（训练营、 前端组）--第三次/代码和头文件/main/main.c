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
	   printf("�������޸�ֵֻ��Ϊint�����ݣ�\n");
	   printf("1-����һ��ѭ������    2-����һ��������\n" );
	   printf("your chioce:");
       scanf("%d",&n);
	   do{ 
	   	if(n==1)
	   	{
	   		system("CLS");
	   	 	printf("0-����\n");
			printf("1-��ʼ������\n");
			printf("2-���ٶ���\n");
			printf("3-�������Ƿ�Ϊ��\n");
			printf("4-�鿴��ͷԪ��\n");
			printf("5-ȷ�����г���\n");
			printf("6-���\n");
			printf("7-����\n");
			printf("8-��ն���\n");
			printf("9-��������\n");
			printf("10-�������Ƿ�����\n");
		}
		else if(n==2)
		{
			system("CLS");
	   	 	printf("0-����\n");
			printf("1-��ʼ������\n");
			printf("2-���ٶ���\n");
			printf("3-�������Ƿ�Ϊ��\n");
			printf("4-�鿴��ͷԪ��\n");
			printf("5-ȷ�����г���\n");
			printf("6-���\n");
			printf("7-����\n");
			printf("8-��ն���\n");
			printf("9-��������\n");
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
			           printf("��ͷԪ��Ϊ%d\n",e);
			           break;
			    case 5:if(LengthAQueue(Q1)==-1)	break;
				       printf("���г���Ϊ%d",LengthAQueue(Q1));
			           break;
			    case 6:printf("������һ��������\n");
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
			    	   printf("��ͷԪ��Ϊ%d\n",e);
			           break;
			    case 5:if(LengthLQueue(Q2)>=0) 
				       printf("���г���Ϊ%d",LengthLQueue(Q2));
			           break;
			    case 6:printf("������һ��������\n");
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
