// ˳��ջ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#define MaxSize 50
typedef int ElemType;

//����ջ�ṹ��
typedef struct
{
ElemType data[MaxSize];
int top;
}SqStack;


//��ʼ��ջ
void InitStack(SqStack &S)
{
S.top = -1;
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack S)
{
if(S.top == -1)
return true; //ջΪ��
else
return false;
}

//��ջ
bool Push(SqStack &S,ElemType x)
{
if(S.top == MaxSize-1)
return false;
S.data[++S.top] = x;
return true;
}

//��ջ
bool Pop(SqStack &S,ElemType x)
{
if(S.top == -1)
return false;
x = S.data[S.top--];
printf("%d\n",x); //Ϊ�鿴ջ�ĳ�ջԪ��
return true;
}

//��ȡջ��Ԫ��
bool GetTop(SqStack S,ElemType &x)
{
if(S.top == -1)
return false;
x = S.data[S.top];
printf("%d\n",x); //Ϊ�鿴ջ��ջ��Ԫ��
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

