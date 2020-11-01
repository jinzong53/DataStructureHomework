#include <bits/stdc++.h>
using namespace std;

typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;

void InOrderTraverse(BiTree T)
{
    if(T)
    {
        InOrderTraverse(T->lchild); //�������������
        cout<<T->data;              //���ʸ��ڵ�
        InOrderTraverse(T->rchild); //�������������
    }
}

void PreTraverse(BiTree T)
{
    if(T)
    {
        cout<<T->data;              //���ʸ��ڵ�
        PreTraverse(T->lchild); //�������������
        PreTraverse(T->rchild); //�������������
    }
}

void LastTraverse(BiTree T)
{
    if(T)
    {
        LastTraverse(T->lchild); //�������������
        LastTraverse(T->rchild); //�������������
        cout<<T->data;              //���ʸ��ڵ�
    }
}

void LevelTraverse(BiTree T) //������ 
{
    queue<BiTree> q;
    int i=0;
    if(T)
    {
        q.push(T);
    }
    while(q.empty()!=true&&i<=100)
    {
        cout<<q.front()->data;
        T = q.front(); //
        q.pop();
        if (T->lchild != NULL)
        {				//������ʱ���ýڵ������
			q.push(T->lchild);
		}
		if (T->rchild != NULL)
		{				//���Һ���ʱ���ýڵ������
			q.push(T->rchild);
		}
    }
}

int Depth(BiTree T)
{
    if(!T) return 0;
    else
    {
        int m = Depth(T->lchild);
        int n = Depth(T->rchild);
        if(m>n) return m+1;
        else return n+1;

    }
}

int NodeCount(BiTree T)
{
    if(T==NULL) return 0;
    else return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}
void CreateBiTree(BiTree &T)
{
    char ch;
    cin>>ch;
    if(ch=='#') T=NULL;
    else
    {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
int main()
{
    BiTree T;
    CreateBiTree(T);
    printf("���������");InOrderTraverse(T);
    printf("\n");
    printf("���������");PreTraverse(T);
    printf("\n");
    printf("���������");LastTraverse(T);
    printf("\n");
    printf("�㼶������");LevelTraverse(T);
    int num_level=0;
    int num_node=0;
    num_level = Depth(T);
    num_node = NodeCount(T);
    printf("\n���Ϊ��%d \n",num_level);
    printf("�����Ϊ��%d \n",num_node);
    return 0;
}
