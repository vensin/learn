#include <stdio.h>
#include <stdlib.h>
void color(int *s,int n);
int findmin(int *s,int p,int r,int min);
int findmax(int *s,int p,int r,int max);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void main()
{
	int n,i,k,ch,flag=0;
	do{
		system("CLS");
		flag=0;
		printf("\n1-��ɫ����	2-Ѱ�ҵ�kСֵ	3-Ѱ�ҵ�k��ֵ\nyour chioce:");
		scanf("%d",&ch);
		//getch();
		if(ch>3||ch<0) 
		{printf("this chioce is error"); getch();continue;}
		
		if(ch==1)
		printf("������Ԫ��ֻ��Ϊ0,1��2\n");
		
		printf("���������鳤�ȣ�");
		scanf("%d",&n);
		
		int s[n];
		
		printf("\n����������Ԫ�أ�");
		for(i=0;i<n;i++)
		{
			scanf("%d",&s[i]);
			if(ch==1&&s[i]>2||s[i]<0)
			{
				printf("����Ԫ���зǷ�ֵ");
				flag=1;
				break; 
			}
		}
		if(flag) 
		{
			getch();
			continue;
		}
		printf("\n����Ԫ��Ϊ��");
		for(i=0;i<n;i++)
		printf("%d ",s[i]);
		
		switch(ch)
		{
		case 1:color(s,n);
			printf("\n���������Ԫ��Ϊ��");
			for(i=0;i<n;i++)
			printf("%d ",s[i]);
			break;
		case 2:printf("\nkΪ��");
			scanf("%d",&k);
			printf("\n��%dС��ֵΪ%d",k,findmin(s,0,n-1,k));
			
			break;
		case 3:printf("\nkΪ��");
			scanf("%d",&k);
			printf("\n��%d���ֵΪ%d",k,findmax(s,0,n-1,k));
			
			break;
		}
		getch();
	}while(1);
	
	//	color(s,10);
	

	
}
void swap(int* s, int i, int j) //���ڿ��� 
{
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
}

void color(int *s,int n)
{
	int p0=0,p2=n-1,temp,i=0,j;
	for(i=0;i<n;)
	{
		if(i==p2+1)
		break;
		if(s[i]==0)
		{
			if(i!=p0)
			{
			temp=s[p0];
			s[p0]=s[i];
			s[i]=temp; 	
			}
			else i++;
			p0++;
		}
		else if(s[i]==2)
		{
			if(i!=p2)
			{
				temp=s[p2];
			s[p2]=s[i];
			s[i]=temp;
			}
			else i++;
			p2--;
		}
		else
		i++;
	}
}

int findmin(int *s,int p,int r,int min)
{
	int x = s[p],j = p,i;
	if(r==p)
		return s[p];
    for (i = p + 1; i <= r; i++) {
        // С��pivot�ķŵ����
        if (s[i] < x) {
            swap(s, ++j, i);
        }
    }
    // ������˵��pivotλ��
    swap(s, p, j);
    if(j-p+1>=min)
    {
    	findmin(s, p, j, min);
	}
	else
	{
		findmin(s, j+1, r, min-(j-p+1));
	}
} 

int findmax(int *s,int p,int r,int max)
{
	int x = s[p],j = p,i;
	if(r==p)
		return s[p];
    for (i = p + 1; i <= r; i++) {
        // С��pivot�ķŵ����
        if (s[i] < x) {
            swap(s, ++j, i);
        }
    }
    // ������˵��pivotλ��
    swap(s, p, j);
    if(r-j>=max)
    {
    	findmax(s, j+1, r, max);
	}
	else
	{
		findmax(s, p, j, max-(r-j));
	}
} 
