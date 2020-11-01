#include <bits/stdc++.h>

using namespace std;
#define MAXSIZE 100

typedef struct
{
    int* base;
    int front;
    int rear;
}SqQueue;
 
 //��ʼ������ 
void InitQueue(SqQueue &Q)
{
    Q.base = new int[MAXSIZE];
    if(!Q.base) exit(OVERFLOW);
    Q.front = Q.rear=0;
}

//���� 
void DeQueue(SqQueue &Q,int &e)
{
    if(Q.front!=Q.rear)
    {
        e = Q.base[Q.front];
        Q.front=(Q.front+1)%MAXSIZE;
    }
}

//���ضӵĳ��� 
int QueueLength(SqQueue Q)
{
    return(Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

//��� 
void EnQueue(SqQueue &Q,int e)
{
    if((Q.rear+1)%MAXSIZE!=Q.front)
    {
        Q.base[Q.rear]=e;
        Q.rear=(Q.rear+1)%MAXSIZE;
    }
}

//��ȡ��ͷԪ�� 
int GetHead(SqQueue Q)
{
    if(Q.front!=Q.rear)
    {
        return Q.base[Q.front];
    }
}

//����һ����
void GreatQueue(SqQueue &Q,int n)
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
	SqQueue Q;int n;
	InitQueue(Q);
	printf("�öӵĳ�ʼԪ��������");scanf("%d",&n);
	GreatQueue(Q,n);
	
	printf("�öӵĳ���Ϊ��%d \n",QueueLength(Q));
	
	printf("���Ԫ��: ");scanf("%d",&n);EnQueue(Q,n);
	
	DeQueue(Q,n);
	printf("����Ԫ��: %d \n",n);
	
	printf("�ö�ȫ��Ԫ��: "); 
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
