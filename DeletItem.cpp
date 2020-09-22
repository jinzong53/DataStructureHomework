#include <bits/stdc++.h>

using namespace std;
typedef int ElemType;
#define MAXSIZE 100
typedef struct
{
    ElemType *elem;
    int length;
}SqList;

int InitList(SqList &L)  //初始化一个表
{
    L.elem = new ElemType[MAXSIZE];
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
    return 1;
}
void Function(SqList &L,ElemType item)
{
    //结果非按照原有顺序表示
    int i=0,j=L.length-1;  // 头尾双向指针，当j移动的时候表长减一
    while(i<=j)
    {
        if(L.elem[i]==item&&L.elem[j]!=item) //当i指向的元素与item相等且j指向的元素非item
        {
            L.elem[i]=L.elem[j]; //将j指向的元素赋值给i指向的元素
            L.length--;            //表长减一
            i++;
            j--;
        }
        if(L.elem[i]!=item) i++;  //i指向的不等于item时，i右移动
        if(L.elem[j]==item)     //j指向的元素为item时，略过该元素
        {
            j--;
            L.length--;
        }
    }
}
int TravarseList(SqList L)
{
    if(L.length==0)return 0;
    for(int i=0;i<=L.length-1;i++)
        printf("%d \t",L.elem[i]);
    printf("\n");
    return 1;
}
int main()
{
    /*初始化表*/
    SqList L1;InitList(L1);

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

   Function(L1,3);

   TravarseList(L1);
    return 0;
}
