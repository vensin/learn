#include <stdio.h>
#include <malloc.h>
typedef char TElemType;   // �������������Ԫ������Ϊ�ַ�

typedef struct SqBiTree{
   TElemType *elem;     // 0�ŵ�Ԫ����
   int lastIndex;              // ���������һ�����ı��
}SqBiTree ;    // ˳��洢�Ķ�����

typedef struct  BiTNode {
    TElemType      data;     // ������
    struct BiTNode  *lchild,*rchild;  // ���Һ���ָ��
    //int Tag;
} BiTNode,*BiTree;   // ��������

typedef enum {
	SUCEESS,
	ERROR
}Status;


Status InitBiTree(BiTree T);
//�������������ն�����T
Status DestroyBiTree(BiTree T);
//��ʼ������������T����
//����������ݻٶ�����T
Status CreateBiTree(BiTree* T);
//��ʼ������ definition�����������Ķ���
//�����������definition���������T


//���²��ֺ�������δָ����������
Status visit(BiTree T);
Status PreOrderTraverse(BiTree T);
//��ʼ������������T���ڣ�visitΪ�Խ��Ĳ�����Ӧ�ú���
//����������������T����ÿ��������visit����һ���ҽ�һ�Σ�һ��visitʧ�ܣ������ʧ��
Status InOrderTraverse(BiTree T);	//�������
Status PostOrderTraverse(BiTree T);	//�������
Status LevelOrderTraverse(BiTree T);	//�������
//int Value(BiTNode T);			//������Ķ�������ֵ

/*
��ʾ�����ڽ��ṹ�������ø�Tagֵ��־������������������������
�ɸ�����Ҫ�������Ӳ���.
*/
