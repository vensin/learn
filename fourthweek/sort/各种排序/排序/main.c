#include <stdio.h>
#include <stdlib.h>
#include "sort.h" 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,i,chioce;
	
    
    	printf("������������1-����   2-�鲢	3-����	4-����");
    	 scanf("%d",&chioce);
    	 printf("���������鳤�ȣ��200000:");
		scanf("%d",&n) ;
		int s[n];
		freopen("200000.txt","r",stdin);
   		 for(i=0;i<n;i++)
    	scanf("%d",&s[i]);
    	 	if(chioce==1)
    	 	{
    	 		clock_t start1 = clock();
				InsertSort(s,n);//���� 
				clock_t diff1;
				diff1= clock()-start1;
				printf("��������ʱ��Ϊ%dms\n",diff1);
			 }
			 
			
			if(chioce==2)
			{
				clock_t start2 = clock();
				MergeSort(s,n);//�鲢���� 
				clock_t diff2 = clock()-start2;
    			printf("�鲢����ʱ��Ϊ%dms\n",diff2);
			}
				
    		if(chioce==3)
    		{
    			clock_t start3 = clock();
				QSort_Recursion(s,0,n-1);//���� 
				clock_t diff3 = clock()-start3;
				printf("��������ʱ��Ϊ%dms\n",diff3);
			}
			
			if(chioce==4)
			{
				clock_t start4 = clock();
	 			CountSort(s,n);//���� 
				clock_t diff4 = clock()-start4;
   	 			printf("��������ʱ��Ϊ%dms\n",diff4);
			}
			
	
	/*clock_t start5 = clock();
	RadixCountSort(s,14);//���� ,��14���Ͳ����� 
	clock_t diff5 = clock()-start5;
	printf("��������ʱ��Ϊ%dms\n",diff5);*/
	return 0;
}
