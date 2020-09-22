#include <bits/stdc++.h>

using namespace std;
typedef int ElemType;
#define MAXSIZE 100
typedef struct
{
    ElemType *elem;
    int length;
}SqList;

int InitList(SqList &L)  //��ʼ��һ����
{
    L.elem = new ElemType[MAXSIZE];
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
    return 1;
}
void Function(SqList &L,ElemType item)
{
    //����ǰ���ԭ��˳���ʾ
    int i=0,j=L.length-1;  // ͷβ˫��ָ�룬��j�ƶ���ʱ�����һ
    while(i<=j)
    {
        if(L.elem[i]==item&&L.elem[j]!=item) //��iָ���Ԫ����item�����jָ���Ԫ�ط�item
        {
            L.elem[i]=L.elem[j]; //��jָ���Ԫ�ظ�ֵ��iָ���Ԫ��
            L.length--;            //����һ
            i++;
            j--;
        }
        if(L.elem[i]!=item) i++;  //iָ��Ĳ�����itemʱ��i���ƶ�
        if(L.elem[j]==item)     //jָ���Ԫ��Ϊitemʱ���Թ���Ԫ��
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
    /*��ʼ����*/
    SqList L1;InitList(L1);

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

   Function(L1,3);

   TravarseList(L1);
    return 0;
}
