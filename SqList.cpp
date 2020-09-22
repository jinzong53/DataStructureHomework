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

Status InitList(SqList &L)  //初始化一个表
{
    L.elem = new ElemType[MAXSIZE];
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
    return OK;
}

Status GetElem(SqList L,int i,ElemType &e)  //获取表中的元素
{
    if(i<1||i>L.length) return ERROR;
    e=L.elem[i-1];
    return OK;
}

Status PriorElem(SqList L,int i,ElemType &e) //i前面一个元素
{
    if(i<1||i>L.length) return ERROR;
    if(i==1) return ERROR;
    e=L.elem[i-2];
    return OK;
}
Status NextElem(SqList L,int i,ElemType &e)  //后面一个元素
{
    if(i<1||i>L.length) return ERROR;
    if(i==L.length) return ERROR;
    e=L.elem[i];
    return OK;
}
bool ListEmpty(SqList L) //判断表是否为空
{
    return L.length==0?true:false;
}

int LocateElem(SqList L,ElemType e)  //查找定位元素
{
    int i=0;
    while(i<L.length&&L.elem[i]!=e)
        i++;
    if(i>L.length-1)
        return ERROR;
    else
        return i+1;
}

Status ClearList(SqList &L) //清空表
{
    L.length=0;
    return OK;
}


Status ModifyList(SqList &L,int i,ElemType e) //修改表的第i个元素为e
{
    if(i<1||i>L.length) return ERROR;
    L.elem[i-1]=e;
    return OK;
}

Status InsertList(SqList &L,int i,ElemType e) //插入表
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

Status DeleteList(SqList &L,int i) //删除表
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

Status DestoryList(SqList &L) //销毁表
{
    if(L.length>0) delete[] L.elem;
    return OK;
}

Status Intersection(SqList L1,SqList L2,SqList &L3) //求交集
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

Status Sum(SqList L1,SqList L2,SqList &L3) //求并集
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

Status Difference(SqList L1,SqList L2,SqList &L3)//求差集
{
    int temp=0;
    //L3 = L1;//属于浅拷贝
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
    /*初始化表*/
    SqList L1;InitList(L1);
    SqList L2;InitList(L2);
    SqList L3;InitList(L3);

   /*输入表*/
   int length,position,value;
   printf("输入表1的元素数量：");
   scanf("%d",&length);
   printf("输入表1的元素：");
   for(int i=0;i<length;i++)
   {
       scanf("%d",&L1.elem[i]);
       L1.length++;
   }

   printf("\n");

   printf("输入表2的元素数量：");
   scanf("%d",&length);
   printf("输入表2的元素：");
   for(int i=0;i<length;i++)
   {
       scanf("%d",&L2.elem[i]);
       L2.length++;
   }

   printf("\n");

   /*修改*/
    printf("输入表1的需要修改元素序号和值：");
    scanf("%d %d",&position,&value);
    ModifyList(L1,position,value);
    printf("打印表：");
    TravarseList(L1);
    printf("\n");

    /*插入*/
    printf("输入表1的需要插入元素序号和值：");
    scanf("%d %d",&position,&value);
    InsertList(L1,position,value);
    printf("打印表：");
    TravarseList(L1);
    printf("\n");

    /*删除*/
    printf("输入表1的需要删除元素序号：");
    scanf("%d",&position);
    DeleteList(L1,position);
    printf("打印表：");
    TravarseList(L1);
    printf("\n");

    printf("表1和表2的交集为：");
    Intersection(L1,L2,L3);
    TravarseList(L3);
    InitList(L3);

    printf("表1和表2的并集为：");
    Sum(L1,L2,L3);
    TravarseList(L3);
    InitList(L3);

    printf("表1和表2的差集为：");
    Difference(L1,L2,L3);
    TravarseList(L3);
    return 0;
}

