#include <bits/stdc++.h>
using namespace std;

#define OK 1
#define ERROR 0
#define MAXSIZE 100

typedef int  Status;
typedef int  ElemType;
typedef struct
{
    ElemType* elem;
    int length;
}SqList;

Status InitList(SqList &L)  //��ʼ��һ����
{
    L.elem = new ElemType[MAXSIZE];
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
    return OK;
}

Status GetElem(SqList L,int i,ElemType &e)  //��ȡ���е�Ԫ��
{
    if(i<1||i>L.length) return ERROR;
    e=L.elem[i-1];
    return OK;
}

Status PriorElem(SqList L,int i,ElemType &e) //iǰ��һ��Ԫ��
{
    if(i<1||i>L.length) return ERROR;
    if(i==1) return ERROR;
    e=L.elem[i-2];
    return OK;
}
Status NextElem(SqList L,int i,ElemType &e)  //����һ��Ԫ��
{
    if(i<1||i>L.length) return ERROR;
    if(i==L.length) return ERROR;
    e=L.elem[i];
    return OK;
}
bool ListEmpty(SqList L) //�жϱ��Ƿ�Ϊ��
{
    return L.length==0?true:false;
}

int LocateElem(SqList L,ElemType e)  //���Ҷ�λԪ��
{
    int i=0;
    while(i<L.length&&L.elem[i]!=e)
        i++;
    if(i>L.length-1)
        return ERROR;
    else
        return i+1;
}

Status ClearList(SqList &L) //��ձ�
{
    L.length=0;
    return OK;
}


Status ModifyList(SqList &L,int i,ElemType e) //�޸ı�ĵ�i��Ԫ��Ϊe
{
    if(i<1||i>L.length) return ERROR;
    L.elem[i-1]=e;
    return OK;
}

Status InsertList(SqList &L,int i,ElemType e) //�����
{
    if(i<1||i>L.length) return ERROR;
    if(L.length==MAXSIZE) return ERROR;
    for(int j=L.length-1;j>=i-1;j--)
    {
        L.elem[j+1] = L.elem[j];
    }
    L.elem[i-1]=e;
    L.length++;
    return OK;
}

Status DeleteList(SqList &L,int i) //ɾ����
{
    if(i<1||i>L.length) return ERROR;
    if(L.length==MAXSIZE) return ERROR;
    for(int j=i-1;j<=L.length-1;j++)
    {
        L.elem[j] = L.elem[j+1];
    }
    L.length--;
    return OK;
}

Status DestoryList(SqList &L) //���ٱ�
{
    if(L.length>0) delete[] L.elem;
    return OK;
}

Status Intersection(SqList L1,SqList L2,SqList &L3) //�󽻼�
{
    int temp=0;
    for(int i=0;i<L1.length;i++)
    {
        for(int j=0;j<L2.length;j++)
        {
            if(L1.elem[i]==L2.elem[j])
            {
               L3.elem[temp]=L2.elem[i] ;
               temp++;
               L3.length++;
            }
        }
    }
    return OK;
}

Status Sum(SqList L1,SqList L2,SqList &L3) //�󲢼�
{
    int temp=0;
    L3 = L1;
    while(temp<L2.length)
    {
        if(LocateElem(L3,L2.elem[temp])==ERROR)
        {
            L3.elem[L3.length]=L2.elem[temp];
            L3.length++;
        }
        temp++;
    }
    return OK;
}

Status Difference(SqList L1,SqList L2,SqList &L3)//��
{
    int temp=0;
    //L3 = L1;//����ǳ����
    while(temp<L2.length)
    {
        if(LocateElem(L1,L2.elem[temp])==ERROR)
        {
            L3.elem[L3.length]=L2.elem[temp];
            L3.length++;
        }
        temp++;
    }
    return OK;
}

Status TravarseList(SqList L)
{
    if(L.length==0)return ERROR;
    for(int i=0;i<=L.length-1;i++)
        printf("%d \t",L.elem[i]);
    printf("\n");
    return OK;
}
int main()
{
    /*��ʼ����*/
    SqList L1;InitList(L1);
    SqList L2;InitList(L2);
    SqList L3;InitList(L3);

   /*�����*/
   int length,position,value;
   printf("�����1��Ԫ��������");
   scanf("%d",&length);
   printf("�����1��Ԫ�أ�");
   for(int i=0;i<length;i++)
   {
       scanf("%d",&L1.elem[i]);
       L1.length++;
   }

   printf("\n");

   printf("�����2��Ԫ��������");
   scanf("%d",&length);
   printf("�����2��Ԫ�أ�");
   for(int i=0;i<length;i++)
   {
       scanf("%d",&L2.elem[i]);
       L2.length++;
   }

   printf("\n");

   /*�޸�*/
    printf("�����1����Ҫ�޸�Ԫ����ź�ֵ��");
    scanf("%d %d",&position,&value);
    ModifyList(L1,position,value);
    printf("��ӡ��");
    TravarseList(L1);
    printf("\n");

    /*����*/
    printf("�����1����Ҫ����Ԫ����ź�ֵ��");
    scanf("%d %d",&position,&value);
    InsertList(L1,position,value);
    printf("��ӡ��");
    TravarseList(L1);
    printf("\n");

    /*ɾ��*/
    printf("�����1����Ҫɾ��Ԫ����ţ�");
    scanf("%d",&position);
    DeleteList(L1,position);
    printf("��ӡ��");
    TravarseList(L1);
    printf("\n");

    printf("��1�ͱ�2�Ľ���Ϊ��");
    Intersection(L1,L2,L3);
    TravarseList(L3);
    InitList(L3);

    printf("��1�ͱ�2�Ĳ���Ϊ��");
    Sum(L1,L2,L3);
    TravarseList(L3);
    InitList(L3);

    printf("��1�ͱ�2�ĲΪ��");
    Difference(L1,L2,L3);
    TravarseList(L3);
    return 0;
}

