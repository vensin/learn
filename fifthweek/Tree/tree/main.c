#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.c"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int choice;
	BiTree T;
	
	do
	{
		system("CLS");
		choice =0; 
		printf("1-����������  2-���ٶ�����  3-�������  4-�������  5-�������  6-�������  7-���������  8-��ֵ\n");
		printf("your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
				break;
			case 1:
				T=(BiTree)malloc(sizeof(TElemType));
				T->lchild=NULL;
				T->rchild=NULL;
				if(!InitBiTree(T))
					printf("�����ɹ���\n");
				else
					printf("����ʧ�ܣ�\n");
				break;
			case 2:
				if(!DestroyBiTree(T))
					{
						printf("���ٳɹ���\n");
						T=NULL;
					}
					
				else
					printf("����ʧ�ܣ�\n");
				break;
			case 3:
				PreOrderTraverse(T);
				break; 
			case 4:
				InOrderTraverse(T);
				break;
			case 5:
				PostOrderTraverse(T);
				break;
			case 6:
				LevelOrderTraverse(T);
				break;
			case 7:
				printf("��������������壺"); 
				CreateBiTree(&T);
				break;
			case 8:
				Value(&T);
			default:
				printf("��ѡ����ڣ�\n");
				getch(); 
				break;
		}
		printf("�����������"); 
		getch();
	}while(1);
	return 0;
}
