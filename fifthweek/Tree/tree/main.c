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
		printf("1-创建二叉树  2-销毁二叉树  3-先序遍历  4-中序遍历  5-后序遍历  6-层序遍历  7-构造二叉树  8-求值\n");
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
					printf("创建成功！\n");
				else
					printf("创建失败！\n");
				break;
			case 2:
				if(!DestroyBiTree(T))
					{
						printf("销毁成功！\n");
						T=NULL;
					}
					
				else
					printf("销毁失败！\n");
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
				printf("请输入二叉树定义："); 
				CreateBiTree(&T);
				break;
			case 8:
				Value(&T);
			default:
				printf("该选项不存在！\n");
				getch(); 
				break;
		}
		printf("按任意键返回"); 
		getch();
	}while(1);
	return 0;
}
