// 顺序栈.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define MaxSize 50
typedef int ElemType;

//定义栈结构体
typedef struct
{
ElemType data[MaxSize];
int top;
}SqStack;


//初始化栈
void InitStack(SqStack &S)
{
S.top = -1;
}

//判断栈是否为空
bool StackEmpty(SqStack S)
{
if(S.top == -1)
return true; //栈为空
else
return false;
}

//入栈
bool Push(SqStack &S,ElemType x)
{
if(S.top == MaxSize-1)
return false;
S.data[++S.top] = x;
return true;
}

//出栈
bool Pop(SqStack &S,ElemType x)
{
if(S.top == -1)
return false;
x = S.data[S.top--];
printf("%d\n",x); //为查看栈的出栈元素
return true;
}

//获取栈顶元素
bool GetTop(SqStack S,ElemType &x)
{
if(S.top == -1)
return false;
x = S.data[S.top];
printf("%d\n",x); //为查看栈的栈顶元素
return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	SqStack s;
int m,x=0;
InitStack(s);
Push(s,3);
Push(s,9);
Push(s,17);
Push(s,4);
Pop(s,x);
m = StackEmpty(s);
GetTop(s,x);
printf("%d\n",m);

	return 0;
}

