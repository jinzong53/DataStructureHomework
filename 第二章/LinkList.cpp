#include <bits/stdc++.h>
using namespace std;
#define OK 1
#define ERROR 0
#define MAXSIZE 100
typedef int  Status;
typedef int  ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;

Status InitList(LinkList &L)
{
    L = new LNode;
    L->next = NULL;
    return OK;
}
LNode* LocateElem(LinkList L,ElemType e)
{//金科 1821010010
    LNode* p = L->next; //指向首元结点
    while(p&&p->data!=e)
    {
        p = p->next;
    }
    return p;
}

Status GetElem(LinkList L,int i,ElemType &e)
{//金科 1821010010
    LNode* p = L->next; //指向首元结点
    int j = 1;
    while(p&&j<i)
    {
        p = p->next;
        ++j;
    }
    if(!p||j>i) return ERROR;
    e = p->data;
    return OK;
}

Status InsertElem(LinkList &L,int i,ElemType e)
{
    LinkList p;
    p=L;
    int j=0;
    while(p&&j<i-1)
    {
        p=p->next;
        j++;
    }

    if(!p||j>i-1)
        return ERROR;
    LNode* s = new LNode(); //要定义空间
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}

Status DeleteElem(LinkList &L,int i)
{
    LinkList p = L;
    int j = 0;
    while(p&&j<i-1)
    {
        p = p->next;
        ++j;
    }
    if(!p||j>i-1) return ERROR;
    LNode* temp;
    temp = p->next;
    p->next = p->next->next;
    delete temp;
    return OK;
}

void CreateList_R(LinkList &L,int n)
{
    L = new LNode;
    L->next = NULL;
    LNode* Rpoint = L;
    printf("输入表的元素：");
    for(int i=0;i<n;++i)
    {
        LNode* p = new LNode;
        cin>>p->data;
        p->next = NULL;
        Rpoint->next = p;
        Rpoint = p;
    }
}

void Show(LinkList L)
{
    LNode* p = L->next;
    while(p)
    {
        cout<<p->data<<"\t";
        p = p->next;
    }
}

void MergeList(LinkList &LA,LinkList &LB,LinkList &LC)
{
    LNode *p = LA->next;
    LNode *q = LB->next;
    LNode *r;
    LC = LA;
    LC->next = NULL;
    free(LB);
    r = LC;
     while(p!=NULL && q!=NULL)
     {
         if(p->data <= q->data)
         {
             r->next = p;
             p = p->next;
             r = r->next;
         }
         else{
             r->next = q;
             q = q->next;
             r = r->next;
         }
     }
     r->next = NULL;

     if(p!=NULL){
         r->next = p;
     }
     if(q!=NULL)
         r->next = q;

}
int main()
{
    /*初始化表*/
    LinkList L1;InitList(L1);
    LinkList L2;InitList(L2);
    LinkList L3;InitList(L3);

   /*输入表*/
    int n,i;printf("输入表1的元素数量：");scanf("%d",&n);CreateList_R(L1,n);
    printf("输入表2的元素数量：");scanf("%d",&n);CreateList_R(L2,n);
    printf("\n");

    /*打印表*/
    printf("表1：");Show(L1);
    printf("\n");
    printf("表2：");Show(L2);
    printf("\n");

    /*查询返回结点*/
    printf("查询表1的数值：");scanf("%d",&n);
    LNode* p = LocateElem(L1,n);
    if(p!=NULL) printf("存在");
    else printf("不存在");
    printf("\n");

    /*查询返回data*/
    printf("查询表1的位置：");scanf("%d",&n);
    int e;
    GetElem(L1,n,e);
    printf("该位置值为: %d",e);
    printf("\n");

    /*插入*/
    printf("插入表1的元素的位置和数值大小：");scanf("%d %d",&n,&i);
    InsertElem(L1,n,i);
    printf("表1：");Show(L1);
    printf("\n");

    /*删除*/
    printf("删除表1的元素的位置：");scanf("%d",&n);
    DeleteElem(L1,n);
    printf("表1：");Show(L1);
    printf("\n");
    printf("\n");
    printf("\n");
    /*归并表*/
    MergeList(L1,L2,L3);
    printf("归并结果：");Show(L3);
    return 0;
}
