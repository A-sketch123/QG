// 实现链栈.cpp : 定义控制台应用程序的入口点。
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

//链栈初始化
Status InitStack(LinkStack &S){
	//构建一个空栈S,栈顶指针置空
	S=NULL;
	return OK;
}
//链栈的入栈
Status Push(LinkStack &S,SElemType e){
	//在栈顶插入元素e
	LinkStack p;
	p = new StackNode;//生成新节点
	p->data = e;//将结点数据域置为e
	p->next = S;//将新节点插入栈顶
	S = p;//修改栈顶指针为p
	return OK;
}

//链栈出栈
Status Pop(LinkStack &S, SElemType  &e)
{//删除S的栈顶，用e返回
	LinkStack p;
	if (S==NULL)
		return ERROR;
	e = S->data;//栈顶元素给e
	p = S;
	S=S->next;//修改栈顶指针
	delete p;
	return OK;
}

//取链栈的栈顶元素
SElemType GetTop(LinkStack S)
{//返回S的栈顶元素
	if(S!=NULL)//栈非空
		return S->data;//返回元素值
}
int _tmain(int argc, _TCHAR* argv[])
{
	LinkStack S;
	int choose,flag=0;
	SElemType j,t;
	printf("1初始化：\n");
	printf("2入栈：\n");
	printf("3栈顶元素：\n");
	printf("4出栈：\n");
	printf("5退出：\n");
	choose = -1;
	while(choose!=0)
	{
		printf("请选择：");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1://初始化
			if(InitStack(S))
			{flag=1;
			printf("成功对栈初始化\n");
			}
			else
				printf("初始化失败\n");
			break;
		case 2:{//链栈入栈
		fstream file;
		file.open("SqStack.txt");
		if(!file)
		{
		printf("错误，未找到文件\n");
		exit( ERROR);
		}
		if(flag)
		{
		flag=1;
		printf("进栈元素依次为：\n");
		while(!file.eof())
		{
		 file>>j;//左出右入，右入到变量j
		 if(file.fail())
			  break;
		 else{
			 Push(S,j);
			 printf("%d",j);
		 }
		}
		printf("\n");
		}else
		printf("栈未建立，请重新选择\n");
		file.close();
      }
	 break;
		case 3:
	{
		  if(flag!=-1&&flag!=0)
		  {
			printf("栈顶元素为：\n");
			GetTop(S);
		  }
		  else
			  printf("栈中无元素，请重新选择\n");
		  break;
	  }

		case 4:{
			if(flag)
			{
			printf("依次输出的栈顶元素为：\n");
			while(Pop(S,t))
				printf("%d",t);
			   printf("\n");
			}
			else
				printf("栈未建立，请重新选择");
			break;
			   }
		}
	}

	return 0;
}

