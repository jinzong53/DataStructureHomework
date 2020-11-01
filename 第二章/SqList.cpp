#include<bits/stdc++.h>

using namespace std;

#define elemtype int
const int maxn=9999;

struct sqlist{
    elemtype *elem;
    int length;
};

void initlist(sqlist &L)//申请
{
    L.elem=new elemtype[maxn];
    if(!L.elem)  exit(OVERFLOW);
    L.length=0;
}

void getlist(sqlist &L,int n)//初始化
{
    for(int i=0;i<n;i++)
    {
        cin>>L.elem[i];
    }
    L.length=n;
}

void getvalue(sqlist L,int i,elemtype &e)//取值
{

    if(i<1||i>L.length){
        cout<<"非法输入"<<endl;
        return ;
    }

    e=L.elem[i-1];
}

int findlist(sqlist L,elemtype e)//查找
{
    for(int i=0;i<L.length;i++)
    {
        if(L.elem[i]==e)
            return i+1;
    }
    return 0;
}

void insertlist(sqlist &L,int i,elemtype e)//插入
{
    if(i<1||(i>L.length+1))
    {
        cout<<"非法输入"<<endl;
        return ;
    }
    if(L.length==maxn)
    {
        cout<<"非法输入"<<endl;
        return ;
    }
    for(int j=L.length-1;j>=i-1;j--)
    {
        L.elem[j+1]=L.elem[j];
    }
    L.elem[i-1]=e;
    L.length++;
}

void deletelist(sqlist &L,int i)//删除
{
    if(i<1||(i>L.length))
    {
        cout<<"非法输入"<<endl;
        return ;
    }
    for(int j=i;j<=L.length-1;j++)
    {
        L.elem[j-1]=L.elem[j];
    }
    L.length--;
}

void printlist(sqlist L)//打印
{
    for(int i=0;i<L.length;i++)
    {
        cout<<L.elem[i]<<" ";
    }
    cout<<endl;
}

void mergelist(sqlist x,sqlist y,sqlist &z)//并集
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

void mdlist(sqlist x,sqlist y,sqlist &z)//交集
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

void chajilist(sqlist x,sqlist y,sqlist &z)//差集
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
    cout<<"请输入元素个数:"<<endl;
    cin>>n;
    initlist(L);
    cout<<"请输入元素："<<endl;
    getlist(L,n);//初始化L并输入数据
    printlist(L);

    cout<<"请输入查询的位置："<<endl;
    int h;
    cin>>h;
    getvalue(L,h,value);
    cout<<value<<endl;

    cout<<"请输入查询的元素："<<endl;
    cin>>h;
    cout<<findlist(L,h)<<endl;

    cout<<"请输入插入的元素的位置和值："<<endl;
    int a,b;
    cin>>a>>b;
    insertlist(L,a,b);
    printlist(L);

    cout<<"请输入删除的元素的位置："<<endl;
    cin>>a;
    deletelist(L,a);
    printlist(L);

    cout<<"请输入两个集合的元素的个数："<<endl;
    sqlist x,y,z,c,d;
    int m;
    cin>>n>>m;
    initlist(x);
    cout<<"请输入第一个集合元素："<<endl;
    getlist(x,n);
    printlist(x);
    initlist(y);
    cout<<"请输入第二个集合元素："<<endl;
    getlist(y,m);
    printlist(y);

    initlist(z);
    getlist(z,0);
    initlist(c);
    getlist(c,0);
    initlist(d);
    getlist(d,0);//申请了三个空集合

    mergelist(x,y,z);
    cout<<"两个集合的并集为：";
    printlist(z);//并集

    mdlist(x,y,c);
    cout<<"两个集合的交集为：";
    printlist(c);//交集

    chajilist(x,y,d);
    cout<<"两个集合的差集为：";
    printlist(d);//差集


    return 0;
}
