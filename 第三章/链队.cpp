#include <bits/stdc++.h>

using namespace std;
#define MAXSIZE 100

//结点结构 
typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode,*QueuePtr;

// 指针结构 
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

//初始化 
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
}

//入队 
void EnQueue(LinkQueue &Q, int e) {
	QueuePtr p;
	p = new QNode; 
	p->data = e; 
	p->next = NULL;
	Q.rear->next = p; 
	Q.rear = p; 
}

//出队 
int DeQueue(LinkQueue &Q,int &e)
{
    if((Q.front)!=Q.rear)
    {
        QueuePtr p;
		p = Q.front->next; 
		e = p->data;
		Q.front->next = p->next; 
		if (Q.rear == p)
			Q.rear = Q.front; 
		delete p; 
		return 1;
    }
    else
    {
    	return 0;
	}
}

//返回对头 
int GetHead(LinkQueue Q)
{
    if(Q.front!=Q.rear)
        return Q.front->next->data;
}


//输入一个队
void GreatQueue(LinkQueue &Q,int n)
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
	LinkQueue Q;int n;int status;
	InitQueue(Q);
	printf("该队的初始元素数量：");scanf("%d",&n);
	GreatQueue(Q,n);
	
	
	printf("入队元素: ");scanf("%d",&n);EnQueue(Q,n);
	
	status = DeQueue(Q,n);
	printf("出队元素: %d \n",n);
	
	printf("队头元素: %d \n",GetHead(Q));
	
	printf("该队列剩余的所有元素：");
	status = DeQueue(Q,n);
	while(status != 0)
	{
		printf(" %d ",n); 
		status = DeQueue(Q,n);	
	} 
    return 0;
}
