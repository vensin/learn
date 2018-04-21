#include <stdio.h>
#include <stdlib.h>
#include<string.h> 
#include "calculate.h" 
#include "stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void main(int argc, char *argv[]) {
	char str1[20];
	char* p;
	int i,flag=0;
	do
	{
		system("CLS");
		i=0;
		flag=0;
		printf("开始进行四则运算\n");
		printf("请输入一个长度大于2的中缀表达式\n");
		printf("表达式为：");
		scanf("%s",str1);
		p=str1;
		if(strlen(str1)<3)
		{
			printf("该式子过短！\n");
			flag=1;
			getch();
			continue;
		}
		while(i<strlen(str1))
		{
			if((*p<'0'||*p>'9')&&*p!='+'&&*p!='-'&&*p!='/'&&*p!='*')
	   		{
	   			flag=1;
	   			printf("该表达式有未知符号，请重新输入！\n");
	   			getch();
	   			break;
	   		}
	   		p++;
	   		i++;
		} 
		if(flag)
		continue;
		printf("该表达式的值为%d\n",calculate(str1));
		getch();
	}while(1);
}
