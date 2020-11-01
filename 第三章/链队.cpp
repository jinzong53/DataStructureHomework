#include <bits/stdc++.h>

using namespace std;
#define MAXSIZE 100

//���ṹ 
typedef struct QNode
{
    int data;
    struct QNode *next;
}QNode,*QueuePtr;

// ָ��ṹ 
typedef struct
{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

//��ʼ�� 
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
}

//��� 
void EnQueue(LinkQueue &Q, int e) {
	QueuePtr p;
	p = new QNode; 
	p->data = e; 
	p->next = NULL;
	Q.rear->next = p; 
	Q.rear = p; 
}

//���� 
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

//���ض�ͷ 
int GetHead(LinkQueue Q)
{
    if(Q.front!=Q.rear)
        return Q.front->next->data;
}


//����һ����
void GreatQueue(LinkQueue &Q,int n)
{
	int temp;
	printf("�öӵ�Ԫ��:");
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
	printf("�öӵĳ�ʼԪ��������");scanf("%d",&n);
	GreatQueue(Q,n);
	
	
	printf("���Ԫ��: ");scanf("%d",&n);EnQueue(Q,n);
	
	status = DeQueue(Q,n);
	printf("����Ԫ��: %d \n",n);
	
	printf("��ͷԪ��: %d \n",GetHead(Q));
	
	printf("�ö���ʣ�������Ԫ�أ�");
	status = DeQueue(Q,n);
	while(status != 0)
	{
		printf(" %d ",n); 
		status = DeQueue(Q,n);	
	} 
    return 0;
}
