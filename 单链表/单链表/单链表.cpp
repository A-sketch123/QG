// ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include<malloc.h>
struct Node{
	int data;   //������
	struct Node* next;//ָ����
};
struct Node* createList()
{
struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
//headNode ��Ϊ�˽ṹ�����,����ʹ��ǰҪ�ȳ�ʼ��
headNode ->next = NULL;
return headNode;
}

//�������
struct Node* createNode( int data)
{
	struct Node*newNode =  (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode ->next=NULL;
	return newNode;
}

//��ӡ����
void printList(struct Node* headNode)
{
	struct Node* pMove = headNode ->next;
	while(pMove)
	{
		printf("%d\t",pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}
//ɾ��ָ��λ�ý��
void deleteNodeByAppoin(struct Node *headNode,int posData)
{
	struct Node*posNode = headNode ->next;
	struct Node*posNodeFront = headNode;
	if(posNode ==NULL)
		printf("�޷�ɾ��������Ϊ��\n");
	else
	{
	while(posNode ->data!=posData)
	{
	posNodeFront =posNode;
	posNode = posNodeFront->next;
	if(posNode==NULL)
	{
		printf("û�ҵ������Ϣ���޷�ɾ��\n");
		return;
	}
	}
	posNodeFront->next=posNode->next;
	free(posNode);
}
}
//�����㣬�����������ĸ�����������������Ƕ���
void insertNodeByHead( struct Node* headNode, int data)
{
	//����������
	struct Node* newNode =  createNode(data);
	newNode->next= headNode ->next;
	headNode ->next= newNode;
}

int _tmain(int argc, _TCHAR* argv[])
{
	struct Node*list= createList();
	insertNodeByHead(list,1);
	insertNodeByHead(list,2);
	insertNodeByHead(list,3);
	printList(list);
   deleteNodeByAppoin(list,2);
   printList(list);
	
	return 0;
}

