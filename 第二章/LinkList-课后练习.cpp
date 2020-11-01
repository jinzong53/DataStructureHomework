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
{
    LNode* p = L->next; //指向首元结点
    while(p&&p->data!=e)
    {
        p = p->next;
    }
    return p;
}

Status GetElem(LinkList L,int i,ElemType &e)
{
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

Status InsertElem(LinkList L,int i,ElemType e)
{
    LNode* p = L->next; //指向首元结点
    LNode* s;
    s->data = e;
    int j = 1;
    while(p&&j<i-1)
    {
        p = p->next;
        ++j;
    }
    if(!p||j>i-1) return ERROR;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status DeleteElem(LinkList &L,int i)
{
    LNode* p = L->next; //指向首元结点
    int j = 1;
    while(p&&j<i-1)
    {
        p = p->next;
        ++j;
    }
    if(!p||j>i-1) return ERROR;
    LNode* temp = p->next;
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
    LNode* pa = LA->next;
    LNode* pb = LB->next;
    LC=LA;
    LNode*                                                                                                                                                                                                                                                                                                                                                                                                                                                                     pc=LC;
    while(pa&&pb)
    {
        if(pa->data<=pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc=pb;
            pb=pb->next;
        }
    }
    pc->next = pa?pa:pb;
    delete LB;

}

LNode* FindMax(LinkList L)
{
    LNode* p_temp = L->next;
    LNode* p = L->next;
    int e = L->next->data;
    p_temp = p_temp->next;
    while(p_temp)
    {
        if(e<=p_temp->data)
        {
            e = p_temp->data;
            p = p_temp;
        }
        p_temp = p_temp->next;
    }
    return p;
}

void ReseverList(LinkList &L)
{
    LNode* p1 = L->next;
    LNode* p2 = L->next->next;
    LNode* temp ;  //防止p2后面链表的丢失
    while(p2 != NULL)
    {
        temp = p2->next;
        p2->next = p1;
        p1 = p2;    //指针前移
        p2 = temp;  //指针前移
    }
    L->next->next = NULL; //头结点没有改变过，将原来的首元结点设置为链尾
    L->next = p1; //p1移动原链表的链尾，设置头结点
}

int main()
{
    /*初始化表*/
    LinkList L1;InitList(L1);


   /*输入表*/
    int n;printf("输入表1的元素数量：");scanf("%d",&n);CreateList_R(L1,n);
    printf("\n");

    /*打印表*/
    printf("表1:");Show(L1);
    printf("\n");


    LNode* node = FindMax(L1);
    cout<<"MAX:"<<node->data;
    printf("\n");

    ReseverList(L1);
    Show(L1);
    return 0;
}
