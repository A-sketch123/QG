// ʵ����ջ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef  char SElemType;
typedef struct StackNode{
	SElemType data;
	struct StackNode *next;
} StackNode, *LinkStack;

//��ջ��ʼ��
Status InitStack(LinkStack &S){
	//����һ����ջS,ջ��ָ���ÿ�
	S=NULL;
	return OK;
}
//��ջ����ջ
Status Push(LinkStack &S,SElemType e){
	//��ջ������Ԫ��e
	LinkStack p;
	p = new StackNode;//�����½ڵ�
	p->data = e;//�������������Ϊe
	p->next = S;//���½ڵ����ջ��
	S = p;//�޸�ջ��ָ��Ϊp
	return OK;
}

//��ջ��ջ
Status Pop(LinkStack &S, SElemType  &e)
{//ɾ��S��ջ������e����
	LinkStack p;
	if (S==NULL)
		return ERROR;
	e = S->data;//ջ��Ԫ�ظ�e
	p = S;
	S=S->next;//�޸�ջ��ָ��
	delete p;
	return OK;
}

//ȡ��ջ��ջ��Ԫ��
SElemType GetTop(LinkStack S)
{//����S��ջ��Ԫ��
	if(S!=NULL)//ջ�ǿ�
		return S->data;//����Ԫ��ֵ
}
int _tmain(int argc, _TCHAR* argv[])
{
	LinkStack S;
	int choose,flag=0;
	SElemType j,t;
	printf("1��ʼ����\n");
	printf("2��ջ��\n");
	printf("3ջ��Ԫ�أ�\n");
	printf("4��ջ��\n");
	printf("5�˳���\n");
	choose = -1;
	while(choose!=0)
	{
		printf("��ѡ��");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1://��ʼ��
			if(InitStack(S))
			{flag=1;
			printf("�ɹ���ջ��ʼ��\n");
			}
			else
				printf("��ʼ��ʧ��\n");
			break;
		case 2:{//��ջ��ջ
		fstream file;
		file.open("SqStack.txt");
		if(!file)
		{
		printf("����δ�ҵ��ļ�\n");
		exit( ERROR);
		}
		if(flag)
		{
		flag=1;
		printf("��ջԪ������Ϊ��\n");
		while(!file.eof())
		{
		 file>>j;//������룬���뵽����j
		 if(file.fail())
			  break;
		 else{
			 Push(S,j);
			 printf("%d",j);
		 }
		}
		printf("\n");
		}else
		printf("ջδ������������ѡ��\n");
		file.close();
      }
	 break;
		case 3:
	{
		  if(flag!=-1&&flag!=0)
		  {
			printf("ջ��Ԫ��Ϊ��\n");
			GetTop(S);
		  }
		  else
			  printf("ջ����Ԫ�أ�������ѡ��\n");
		  break;
	  }

		case 4:{
			if(flag)
			{
			printf("���������ջ��Ԫ��Ϊ��\n");
			while(Pop(S,t))
				printf("%d",t);
			   printf("\n");
			}
			else
				printf("ջδ������������ѡ��");
			break;
			   }
		}
	}

	return 0;
}

