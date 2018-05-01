#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void QSort_Recursion(int *s,int p,int r);
void usedtime()
{
	/*int s[12]={12,23,45,76,4,35,67,434,6567,78,56,78},i=0;
	clock_t start = clock();
 	RadixCountSort(s,12);
		for(i=0;i<12;i++)
		printf("%d ",s[i]);
	clock_t diff = clock()-start;
	printf("%dms\n",diff);*/
}

void InsertSort(int *s,int n)//插入排序 
{
	int i=1,j=0,m,temp;
	for(;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(s[j]>s[i])//如果大于s[i] ，往前移 
			{
				temp=s[i];
				for(m=i;m>j;m--)
				s[m]=s[m-1];
				s[j]=temp;
				break;
			}
		}
	}
}



void Merge(int A[],int Temp[],int L,int R,int RightEnd)//合并两个有序序列
{
    int LeftEnd=R-1;
    int p=L,i;
    int num=RightEnd-L+1;
    while(L<=LeftEnd&&R<=RightEnd)
        if(A[L]<=A[R])
            Temp[p++]=A[L++];
        else
            Temp[p++]=A[R++];
    while(L<=LeftEnd)
        Temp[p++]=A[L++];
    while(R<=RightEnd)
        Temp[p++]=A[R++];
    for(i=0;i<num;i++,RightEnd--)
        A[RightEnd]=Temp[RightEnd];
}

void MSort(int A[],int Temp[],int L,int RightEnd)
{
	int center;
    if(L<RightEnd-1)
    {
        center=(L+RightEnd)/2;
        MSort(A,Temp,L,center);
        MSort(A,Temp,center+1,RightEnd);
        Merge(A,Temp,L,center+1,RightEnd);
    }
} 

void MergeSort(int *s,int n)//归并排序 
{
	int *Temp=(int *)malloc(n*sizeof(int));
    if(Temp)
    {
        MSort(s,Temp,0,n-1);
        free(Temp);
    }
    else
        printf("ERROR\n");
}

void swap(int* s, int i, int j) //用于快排 
{
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
}
    
void  selectpivot(int *s,int p,int r) 
{
	int max,middle=(p+r)/2;
	if(s[middle]>s[r])
		swap(s,middle,r);
	if(s[p]>s[r])
		swap(s,p,r);
	if(s[middle]>s[p])
		swap(s,middle,p);
}

void QSort_Recursion(int *s,int p,int r)//快排 
{
		if (p >= r)
            return;
        selectpivot(s,p,r);//三位取中为基准 
        int x = s[p],j = p,i;
        for (i = p + 1; i <= r; i++) {
            // 小于pivot的放到左边
            if (s[i] < x) {
                swap(s, ++j, i);
            }
        }
        // 交换左端点和pivot位置
        swap(s, p, j);
        // 递归子序列
        QSort_Recursion(s, p, j - 1);
        QSort_Recursion(s, j + 1, r);
}

int partion(int* root,int low,int high)
{
 int part=root[low];
 while(low<high)
 {
 while(low<high&&root[high]>part) high--;
 root[low]=root[high];
 while(low<high&&root[low]<part) low++;
 root[high]=root[low];
 }
 root[low]=part;
 return low;
}
 
void QSort(int* root,int low,int high)
{
	LinkStack b,*h=&b;
    initLStack(h);
 	int k,temp,j,i;
 	if(low<high)
 	{
 		pushLStack(h,low);
 		pushLStack(h,high);
 	while(!isEmptyLStack(h))
 	{
  
  		getTopLStack(h,&j);
  		printf("gg");
 		 popLStack(h,&j);
  		getTopLStack(h,&i);
  		popLStack(h,&i);
 
  		k=partion(root,i,j);
 
  		if(i<k-1)
  		{
  			pushLStack(h,i);
  			pushLStack(h,k-1);
  		}
  		if(k+1<j)
  		{
 			pushLStack(h,k+1);
  			pushLStack(h,j);
  		}
 	}
	}
}

void CountSort(int *s,int n)
{
	int i=0,max=s[0],*count,*sort;
	for(;i<n;i++)
		max=max<s[i]?s[i]:max;
	count =(int *)malloc((max+1)*sizeof(int));
	sort = (int *)malloc(n*sizeof(int));
	if(count&&sort)
	{
		for(i=0;i<max+1;i++)
			count[i]=0; 
		for(i=0;i<n;i++)//count存放各个数对应的个数 
			count[s[i]]++;
		/*for(i=1;i<n;i++)//count存放小于等于s[i]的数的个数 
			count[s[i]]+=count[s[i-1]];*/
		for(i=1;i<max+1;i++)
			count[i] += count[i - 1]; 
		for(i=n-1;i>=0;i--)
		{
			sort[count[s[i]]-1]=s[i];
			count[s[i]]--;
		}
		for(i=0;i<n;i++)
			s[i]=sort[i];
		free(count);
		free(sort);
	}
	else
		printf("ERROR!\n");
}

/*void RadixCountSort(int *s,int n)
{
	int  max=s[0],i,temp[10],exp=1;
	for(i = 0; i < n; i++) 
        if(s[i] > max) max = s[i];
    while(max/exp> 0)
    {
    	int Count[10] = {0};
 
        for(i = 0; i < n; i++)
            Count[s[i]/exp%10]++;
		for(i = 1; i < 10; i++)
            Count[i] += Count[i-1];
        for(i = n - 1; i >= 0; i--)
           temp[Count[s[i]/exp%10]-1] = s[i];
        for(i = 0; i < n; i++)
            s[i] = temp[i];
        exp *= 10;
	}
}*/
void RadixCountSort(int *a, int arraySize)//这份copy的也不行 
{
    int i, bucket[10], maxVal = 0, digitPosition =1 ;
     for(i = 0; i < arraySize; i++) {
        if(a[i] > maxVal) maxVal = a[i];
     }

     while(maxVal/digitPosition > 0) {
   
        int digitCount[10] = {0};

        for(i = 0; i < arraySize; i++)
             digitCount[a[i]/digitPosition%10]++;

         for(i = 1; i < 10; i++)
             digitCount[i] += digitCount[i-1];
 
        for(i = arraySize - 1; i >= 0; i--)
             bucket[--digitCount[a[i]/digitPosition%10]] = a[i];

        for(i = 0; i < arraySize; i++)
             a[i] = bucket[i];

         digitPosition *= 10;
     }   
  }
