#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "sort.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
		int s[10000],i;
		freopen("output.txt","r",stdin);
		for(i=0;i<10000;i++)
		scanf("%d",&s[i]);
		
	/*	clock_t start = clock();
  	    QSort_Recursion(s,0,10000-1);
  	    clock_t diff = clock()-start;
	    printf("%dms\n",diff);
	    
	   clock_t start1 = clock();
  	  InsertSort(s,10000);
  	  clock_t diff1 = clock()-start1;
	  printf("%dms\n",diff1);
	  
	  clock_t start2 = clock();
  	  MergeSort(s,10000);
  	  clock_t diff2 = clock()-start2;
	  printf("%dms\n",diff2);
	  
	  clock_t start3 = clock();
  	  CountSort(s,10000);
  	  clock_t diff3 = clock()-start3;
	  printf("%dms\n",diff3);*/
	  	usedtime();
	  clock_t start4 = clock();
  	  RadixCountSort(s,10000);
  	  clock_t diff4 = clock()-start4;
	  printf("%dms\n",diff4);

	  for(i=0;i<10000;i++)
		printf("%d ",s[i]);
	return 0;
}
