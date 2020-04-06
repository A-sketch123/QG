// 单链表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include<malloc.h>
struct Node{
	int data;   //数据域
	struct Node* next;//指针域
};
struct Node* createList()
{
struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
//headNode 成为了结构体变量,变量使用前要先初始化
headNode ->next = NULL;
return headNode;
}

//创建结点
struct Node* createNode( int data)
{
	struct Node*newNode =  (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode ->next=NULL;
	return newNode;
}

//打印链表
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
//删除指定位置结点
void deleteNodeByAppoin(struct Node *headNode,int posData)
{
	struct Node*posNode = headNode ->next;
	struct Node*posNodeFront = headNode;
	if(posNode ==NULL)
		printf("无法删除，链表为空\n");
	else
	{
	while(posNode ->data!=posData)
	{
	posNodeFront =posNode;
	posNode = posNodeFront->next;
	if(posNode==NULL)
	{
		printf("没找到相关信息，无法删除\n");
		return;
	}
	}
	posNodeFront->next=posNode->next;
	free(posNode);
}
}
//插入结点，参数：插入哪个链表，插入结点的数据是多少
void insertNodeByHead( struct Node* headNode, int data)
{
	//创建插入结点
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

