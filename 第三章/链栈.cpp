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
    printf("������ջԪ������");
    scanf("%d",&n);
    count = n;
    printf("������ջԪ��:");
    for(int i=0;i<n;i++){scanf("%d",&e);Push(S,e);}

    printf("������ջԪ��:");
    scanf("%d",&n);Push(S,n);

    printf("��ջԪ��");Pop(S,n);printf("%d \n",n);

    printf("ջ��Ԫ�أ�%d \n",GetTop(S));

    printf("��ջΪ��");
    while(S != NULL)
    {
        Pop(S,n);
        printf("%d ",n);
    }
    return 0;
}
