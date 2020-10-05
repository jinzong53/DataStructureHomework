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
    printf("输入栈元素的数量:");
    scanf("%d",&n);
    count = n;
    printf("输入栈元素:");
    for(int i=0;i<n;i++){scanf("%d",&e);Push(sqstack,e);}

    printf("入栈元素：");
    scanf("%d",&n);Push(sqstack,n);

    printf("出栈元素：");Pop(sqstack,n);printf("%d \n",n);

    printf("栈顶元素：%d \n",GetTop(sqstack));

    printf("顺序栈为:");
    while(sqstack.top!=sqstack.base)
    {
        Pop(sqstack,n);
        printf("%d ",n);
    }
    return 0;
}
