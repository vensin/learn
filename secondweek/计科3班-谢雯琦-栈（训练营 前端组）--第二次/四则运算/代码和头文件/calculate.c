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
		printf("��ʼ������������\n");
		printf("������һ�����ȴ���2����׺���ʽ\n");
		printf("���ʽΪ��");
		scanf("%s",str1);
		p=str1;
		if(strlen(str1)<3)
		{
			printf("��ʽ�ӹ��̣�\n");
			flag=1;
			getch();
			continue;
		}
		while(i<strlen(str1))
		{
			if((*p<'0'||*p>'9')&&*p!='+'&&*p!='-'&&*p!='/'&&*p!='*')
	   		{
	   			flag=1;
	   			printf("�ñ��ʽ��δ֪���ţ����������룡\n");
	   			getch();
	   			break;
	   		}
	   		p++;
	   		i++;
		} 
		if(flag)
		continue;
		printf("�ñ��ʽ��ֵΪ%d\n",calculate(str1));
		getch();
	}while(1);
}
