#include<bits/stdc++.h>

using namespace std;

#define elemtype int
const int maxn=9999;

struct sqlist{
    elemtype *elem;
    int length;
};

void initlist(sqlist &L)//����
{
    L.elem=new elemtype[maxn];
    if(!L.elem)  exit(OVERFLOW);
    L.length=0;
}

void getlist(sqlist &L,int n)//��ʼ��
{
    for(int i=0;i<n;i++)
    {
        cin>>L.elem[i];
    }
    L.length=n;
}

void getvalue(sqlist L,int i,elemtype &e)//ȡֵ
{

    if(i<1||i>L.length){
        cout<<"�Ƿ�����"<<endl;
        return ;
    }

    e=L.elem[i-1];
}

int findlist(sqlist L,elemtype e)//����
{
    for(int i=0;i<L.length;i++)
    {
        if(L.elem[i]==e)
            return i+1;
    }
    return 0;
}

void insertlist(sqlist &L,int i,elemtype e)//����
{
    if(i<1||(i>L.length+1))
    {
        cout<<"�Ƿ�����"<<endl;
        return ;
    }
    if(L.length==maxn)
    {
        cout<<"�Ƿ�����"<<endl;
        return ;
    }
    for(int j=L.length-1;j>=i-1;j--)
    {
        L.elem[j+1]=L.elem[j];
    }
    L.elem[i-1]=e;
    L.length++;
}

void deletelist(sqlist &L,int i)//ɾ��
{
    if(i<1||(i>L.length))
    {
        cout<<"�Ƿ�����"<<endl;
        return ;
    }
    for(int j=i;j<=L.length-1;j++)
    {
        L.elem[j-1]=L.elem[j];
    }
    L.length--;
}

void printlist(sqlist L)//��ӡ
{
    for(int i=0;i<L.length;i++)
    {
        cout<<L.elem[i]<<" ";
    }
    cout<<endl;
}

void mergelist(sqlist x,sqlist y,sqlist &z)//����
{
    int cnt=1;
    for(int i=0;i<x.length;i++)
    {
        if(findlist(z,x.elem[i])==0)
        {
            insertlist(z,cnt++,x.elem[i]);
        }
    }
    for(int i=0;i<y.length;i++)
    {
        if(findlist(z,y.elem[i])==0)
        {
            insertlist(z,cnt++,y.elem[i]);
        }
    }
    z.length=cnt-1;
}

void mdlist(sqlist x,sqlist y,sqlist &z)//����
{
    int cnt=1;
    for(int i=0;i<x.length;i++)
    {
        for(int j=0;j<y.length;j++)
        {
            if((x.elem[i]==y.elem[j])&&findlist(z,x.elem[i])==0)
            {
                insertlist(z,cnt++,x.elem[i]);
            }
        }
    }
    z.length=cnt-1;
}

void chajilist(sqlist x,sqlist y,sqlist &z)//�
{
    int cnt=1;
    for(int i=0;i<x.length;i++)
    {
        if(findlist(y,x.elem[i])==0&&findlist(z,x.elem[i])==0)
        {
            insertlist(z,cnt++,x.elem[i]);
        }
    }
    z.length=cnt-1;
}

int main()
{
    sqlist L;
    int n;
    elemtype value;
    cout<<"������Ԫ�ظ���:"<<endl;
    cin>>n;
    initlist(L);
    cout<<"������Ԫ�أ�"<<endl;
    getlist(L,n);//��ʼ��L����������
    printlist(L);

    cout<<"�������ѯ��λ�ã�"<<endl;
    int h;
    cin>>h;
    getvalue(L,h,value);
    cout<<value<<endl;

    cout<<"�������ѯ��Ԫ�أ�"<<endl;
    cin>>h;
    cout<<findlist(L,h)<<endl;

    cout<<"����������Ԫ�ص�λ�ú�ֵ��"<<endl;
    int a,b;
    cin>>a>>b;
    insertlist(L,a,b);
    printlist(L);

    cout<<"������ɾ����Ԫ�ص�λ�ã�"<<endl;
    cin>>a;
    deletelist(L,a);
    printlist(L);

    cout<<"�������������ϵ�Ԫ�صĸ�����"<<endl;
    sqlist x,y,z,c,d;
    int m;
    cin>>n>>m;
    initlist(x);
    cout<<"�������һ������Ԫ�أ�"<<endl;
    getlist(x,n);
    printlist(x);
    initlist(y);
    cout<<"������ڶ�������Ԫ�أ�"<<endl;
    getlist(y,m);
    printlist(y);

    initlist(z);
    getlist(z,0);
    initlist(c);
    getlist(c,0);
    initlist(d);
    getlist(d,0);//�����������ռ���

    mergelist(x,y,z);
    cout<<"�������ϵĲ���Ϊ��";
    printlist(z);//����

    mdlist(x,y,c);
    cout<<"�������ϵĽ���Ϊ��";
    printlist(c);//����

    chajilist(x,y,d);
    cout<<"�������ϵĲΪ��";
    printlist(d);//�


    return 0;
}
