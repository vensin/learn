#include <stdio.h>
#include <stdlib.h>
#include "sort.h" 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,i,chioce;
	
    
    	printf("想用哪种排序？1-插入   2-归并	3-快排	4-计数");
    	 scanf("%d",&chioce);
    	 printf("请输入数组长度，最长200000:");
		scanf("%d",&n) ;
		int s[n];
		freopen("200000.txt","r",stdin);
   		 for(i=0;i<n;i++)
    	scanf("%d",&s[i]);
    	 	if(chioce==1)
    	 	{
    	 		clock_t start1 = clock();
				InsertSort(s,n);//插入 
				clock_t diff1;
				diff1= clock()-start1;
				printf("插入排序时间为%dms\n",diff1);
			 }
			 
			
			if(chioce==2)
			{
				clock_t start2 = clock();
				MergeSort(s,n);//归并排序 
				clock_t diff2 = clock()-start2;
    			printf("归并排序时间为%dms\n",diff2);
			}
				
    		if(chioce==3)
    		{
    			clock_t start3 = clock();
				QSort_Recursion(s,0,n-1);//快排 
				clock_t diff3 = clock()-start3;
				printf("快速排序时间为%dms\n",diff3);
			}
			
			if(chioce==4)
			{
				clock_t start4 = clock();
	 			CountSort(s,n);//计数 
				clock_t diff4 = clock()-start4;
   	 			printf("计数排序时间为%dms\n",diff4);
			}
			
	
	/*clock_t start5 = clock();
	RadixCountSort(s,14);//基数 ,到14个就不行了 
	clock_t diff5 = clock()-start5;
	printf("基数排序时间为%dms\n",diff5);*/
	return 0;
}
