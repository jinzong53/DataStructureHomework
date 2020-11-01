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
        InOrderTraverse(T->lchild); //中序遍历左子树
        cout<<T->data;              //访问根节点
        InOrderTraverse(T->rchild); //中序遍历右子树
    }
}

void PreTraverse(BiTree T)
{
    if(T)
    {
        cout<<T->data;              //访问根节点
        PreTraverse(T->lchild); //中序遍历左子树
        PreTraverse(T->rchild); //中序遍历右子树
    }
}

void LastTraverse(BiTree T)
{
    if(T)
    {
        LastTraverse(T->lchild); //中序遍历左子树
        LastTraverse(T->rchild); //中序遍历右子树
        cout<<T->data;              //访问根节点
    }
}

void LevelTraverse(BiTree T) //层间遍历 
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
        {				//有左孩子时将该节点进队列
			q.push(T->lchild);
		}
		if (T->rchild != NULL)
		{				//有右孩子时将该节点进队列
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
    printf("中序遍历：");InOrderTraverse(T);
    printf("\n");
    printf("先序遍历：");PreTraverse(T);
    printf("\n");
    printf("后序遍历：");LastTraverse(T);
    printf("\n");
    printf("层级遍历：");LevelTraverse(T);
    int num_level=0;
    int num_node=0;
    num_level = Depth(T);
    num_node = NodeCount(T);
    printf("\n深度为：%d \n",num_level);
    printf("结点数为：%d \n",num_node);
    return 0;
}
