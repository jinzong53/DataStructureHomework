#include <bits/stdc++.h>

using namespace std;
#define MAXSIZE 100

typedef struct
{
    int* base;
    int front;
    int rear;
}SqQueue;
 
 //初始化队列 
void InitQueue(SqQueue &Q)
{
    Q.base = new int[MAXSIZE];
    if(!Q.base) exit(OVERFLOW);
    Q.front = Q.rear=0;
}

//出队 
void DeQueue(SqQueue &Q,int &e)
{
    if(Q.front!=Q.rear)
    {
        e = Q.base[Q.front];
        Q.front=(Q.front+1)%MAXSIZE;
    }
}

//返回队的长度 
int QueueLength(SqQueue Q)
{
    return(Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

//入队 
void EnQueue(SqQueue &Q,int e)
{
    if((Q.rear+1)%MAXSIZE!=Q.front)
    {
        Q.base[Q.rear]=e;
        Q.rear=(Q.rear+1)%MAXSIZE;
    }
}

//获取对头元素 
int GetHead(SqQueue Q)
{
    if(Q.front!=Q.rear)
    {
        return Q.base[Q.front];
    }
}

//输入一个队
void GreatQueue(SqQueue &Q,int n)
{
	int temp;
	printf("该队的元素:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		EnQueue(Q,temp);
	}
} 
int main()
{
	SqQueue Q;int n;
	InitQueue(Q);
	printf("该队的初始元素数量：");scanf("%d",&n);
	GreatQueue(Q,n);
	
	printf("该队的长度为：%d \n",QueueLength(Q));
	
	printf("入队元素: ");scanf("%d",&n);EnQueue(Q,n);
	
	DeQueue(Q,n);
	printf("出队元素: %d \n",n);
	
	printf("该队全部元素: "); 
	DeQueue(Q,n);
	printf("%d",n);
	int temp = QueueLength(Q);
	for(int i=0;i<temp;i++)
	{
		DeQueue(Q,n);
		printf(" -> %d",n);
	}
    return 0;
}
