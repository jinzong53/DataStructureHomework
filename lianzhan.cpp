#include <bits/stdc++.h>

using namespace std;

typedef struct StackNode
{
    int data;
    struct StackNode* next;
}StackNode,*LinkStack;

void InitStack(LinkStack &S)
{
    S = NULL;
}

//入栈
void Push(LinkStack &S,int e)
{
    StackNode* node = new StackNode();
    node->data = e;
    node->next = S;
    S = node;
}

//出栈
void Pop(LinkStack &S,int &e)
{
    if(S!=NULL)
    {
        e = S->data;
        StackNode* node = new StackNode();
        node = S;
        S = S->next;
        delete node;
    }
}

//get top of Stacl
int GetTop(LinkStack &S)
{
    if(S!=NULL)
    {
        return S->data;
    }
}
int main()
{
    LinkStack S; InitStack(S);
    int n,count,e;
    printf("输入链栈元素的数量:");
    scanf("%d",&n);
    count = n;
    printf("输入链栈元素:");
    for(int i=0;i<n;i++){scanf("%d",&e);Push(S,e);}

    printf("入栈元素：");
    scanf("%d",&n);Push(S,n);

    printf("出栈元素：");Pop(S,n);printf("%d \n",n);

    printf("栈顶元素：%d \n",GetTop(S));

    printf("链栈为:");
    while(S != NULL)
    {
        Pop(S,n);
        printf("%d ",n);
    }
    return 0;
    return 0;
}
