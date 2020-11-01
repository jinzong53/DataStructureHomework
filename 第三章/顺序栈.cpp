#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 100

typedef struct
{
    int* base;
    int* top;
    int stacksize;
}SqStack;

void InitStack(SqStack &S)
{
    S.base  = new int[MAXSIZE];
    if(!S.base) exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = MAXSIZE;
}

void Push(SqStack &S,int e)
{
    if(S.top-S.base!=S.stacksize) *S.top++=e;
}

void Pop(SqStack &S,int &e)
{
    if(S.top-S.base!=S.stacksize) e = *--S.top;
}

int GetTop(SqStack S)
{
    if(S.top!=S.base)
        return *(S.top-1);
}
int main()
{
    SqStack sqstack; InitStack(sqstack);
    int n,count,e;
    printf("����ջ��Ԫ�ظ���:");
    scanf("%d",&n);
    count = n;
    printf("����ջԪ��");
    for(int i=0;i<n;i++){scanf("%d",&e);Push(sqstack,e);}

    printf("��ջԪ��");
    scanf("%d",&n);Push(sqstack,n);

    printf("��ջԪ��");Pop(sqstack,n);printf("%d \n",n);

    printf("ջ����%d \n",GetTop(sqstack));

    printf("˳��ջΪ:");
    while(sqstack.top!=sqstack.base)
    {
        Pop(sqstack,n);
        printf("%d ",n);
    }
    return 0;
}
