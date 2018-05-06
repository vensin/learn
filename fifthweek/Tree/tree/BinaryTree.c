#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "BinaryTree.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

Status InitBiTree(BiTree T)
{
	if(T!=NULL)
	{
	
//	  TElemType ch;   
//    printf("������ڵ�ֵ��");
//    scanf("%d",&ch); 
	    BiTree l = (BiTree)malloc(sizeof(TElemType)),r = (BiTree)malloc(sizeof(TElemType));
	    l->lchild=NULL;
	    l->rchild=NULL;
	    r->lchild=NULL;
	    r->rchild=NULL;
	    if(l!=NULL && r!=NULL)
	    {  
			T->lchild=l;
			T->rchild=r; 
			return SUCEESS; 
	    }  
	    else
	    return ERROR;
	}
	else
	    return ERROR;
} 
Status DestroyBiTree(BiTree T)
{
	if(T!=NULL)
	{
		 if (T->lchild!=NULL)  
        {  
            DestroyBiTree(T->lchild);  
            T->lchild = NULL;  
        }  
        if (T->rchild!=NULL)  
        {  
            DestroyBiTree(T->rchild);  
            T->rchild = NULL;  
        }
		free(T);  
        return SUCEESS;
	}
	else
		return ERROR;
	
}
Status CreateBiTree(BiTree* T)
{
	char data;
	data=getchar();
	while(data==' '||data =='\n')
		data=getchar();
	if(T!=NULL)
	{
		if(data=='#')
		{
		*T=NULL;
		}
		else
		{
		*T=(BiTree)malloc(sizeof(TElemType)); 
		(*T)->data=data;
		printf("%c\n",data);
		CreateBiTree( &((*T)->lchild) );
		CreateBiTree( &((*T)->rchild) );
		}
		
	return SUCEESS;
	}
	else 
		return ERROR;
		
	
}
Status PreOrderTraverse(BiTree T)
{
	if(T!=NULL)
	{	visit(T);
		PreOrderTraverse(T->lchild);  
    	PreOrderTraverse(T->rchild); 
    	return SUCEESS;
	}
	else
		return ERROR;
   
}
Status InOrderTraverse(BiTree T)
{
	if(T!=NULL)
	{
		InOrderTraverse(T->lchild);  
		visit(T);
    	InOrderTraverse(T->rchild); 
    	return SUCEESS;
	} 
	else
		return ERROR;
}
Status PostOrderTraverse(BiTree T)
{
	if(T!=NULL)
	{
		InOrderTraverse(T->lchild);  
    	InOrderTraverse(T->rchild); 
    	visit(T);
    	return SUCEESS;
	} 
	else
		return ERROR;
}


Status LevelOrderTraverse(BiTree T)
{
	int QueueMaxSize=100;
	BiTree temp;
    BiTree queue[QueueMaxSize];      //���������ʹ�õ����飬Ԫ������Ϊָ�����ָ������
    int front = 0;
    int rear = 0;
    if (T != NULL)                  //��������
    {
        queue[rear] = T;
        rear = (rear + 1) % QueueMaxSize;
    }
    while (front != rear)
    {
        temp = queue[front];
        front = (front + 1) % QueueMaxSize;
        printf("%c ", temp -> data);
        if (temp -> lchild != NULL)     //���������������
        {
            queue[rear] = temp -> lchild;
            rear = (rear + 1) % QueueMaxSize;
        }
        if (temp -> rchild != NULL)
        {
            queue[rear] = temp -> rchild;
            rear = (rear + 1) % QueueMaxSize;
        }
    }
}

int Value(BiTree T)
{
	if(T==NULL)  
        return 0;  
    if(T->data <='9'&&T->data >='0')  
        return (T->data-'0');  
    else  
    {  
        switch(T->data)            //��Ϊ��һ����T->data��Ϊ���������������Һ��ӽڵ��Ҳ���  
        {  
            case'+':  return Value(T->lchild) + Value(T->rchild); break;  
            case'-':  return Value(T->lchild) - Value(T->rchild); break;  
            case'*':  return Value(T->lchild) * Value(T->rchild); break;  
            case'/':  return Value(T->lchild) / Value(T->rchild); break;  
        }  
    }  
}


Status visit(BiTree T)
{
	if(T!=NULL)
	{
	printf("�ڵ�ֵΪ��%c\n",T->data);	
		return SUCEESS;
	}
	else
		return ERROR;
}
