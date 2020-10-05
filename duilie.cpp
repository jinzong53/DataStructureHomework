#include <bits/stdc++.h>

using namespace std;
#define MAXSIZE 100

typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;
typedef struct
{
    Queue front;
    Queue rear;
}LinkQueue;

void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
}

void EnQueue(LinkQueue &Q,int e)
{
    QNode* p = new QNode;
    p->next = NULLl;Q.rear->next=p;
    Q.rear=p;
}

void DeQueue(LinkQueue &Q,int &e)
{
    if((Q.front)!=Q.rear)
    {
        QNode* p = Q.front->next;
        e = p->data;
        Q.front->next=p->next;
        if(Q.rear==p) Q.rear = Q.front;
        delete p;
    }
}

int GetHead(LinkQueue Q)
{
    if(Q.front!=Q.rear)
        return Q.front->next->data;
}
int main()
{
    return 0;
}
