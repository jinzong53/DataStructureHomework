#include <bits/stdc++.h>

using namespace std;
#define MAXSIZE 100

typedef struct
{
    int* base;
    int front;
    int rear;
}SqQueue;

void InitQueue(SqQueue &Q)
{
    Q.base = new int[MAXSIZE];
    if(!Q.base) exit(OVERFLOW);
    Q.front = Q.rear=0;
}

void DeQueue(SqQueue &Q,int &e)
{
    if(Q.front!=Q.rear)
    {
        e = Q.base[Q.front];
        Q.front=(Q.front+1)%MAXSIZE;
    }
}

int QueueLength(SqQueue Q)
{
    return(Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

void EnQueue(SqQueue &Q,int e)
{
    if((Q.rear+1)%MAXSIZE!=Q.front)
    {
        Q.base[Q.rear]=e;
        Q.rear=(Q.rear+1)%MAXSIZE;
    }
}

int GetHead(SqQueue Q)
{
    if(Q.front!=Q.rear)
    {
        return Q.base[Q.front];
    }
}

int main()
{
    return 0;
}
