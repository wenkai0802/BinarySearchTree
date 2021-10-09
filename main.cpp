#include <iostream>

using namespace std;
class Node{
public:
    Node *lChild;
    int data;
    int height;
    Node *rChild;
};
class AVLTree{
public:
    Node *root;

    BinaryTree(){
        root=NULL;
    }
    int NodeHeight(Node *p)
    {
        int hl;
        int hr;

        hl = (p && p->lChild) ? p->lChild->height : 0;
        hr = (p && p->rChild) ? p->rChild->height : 0;

        return hl > hr ? hl + 1 : hr + 1;

    }
    Node * rInsert(Node *p, int key)
    {
        Node *t;
        if(p==NULL)
        {
            t=new Node;
            t->data=key;
            t->height=1;
            t->lChild=NULL;
            t->rChild=NULL;
            if(root==NULL)root=t;
            return t;
        }
        if(key < p->data)
        {
            p->lChild = rInsert(p->lChild,key);
        }
        else
        {
            p->rChild = rInsert(p->rChild,key);

        }
        p->height=NodeHeight(p);

        if(BalanceFactor(p)==2 && BalanceFactor(p->lChild)==1)
        {
            return LLRotation(p);
        }
        else if(BalanceFactor(p)==2 && BalanceFactor(p->lChild)==-1)
        {
            return LRRotation(p);
        }
        else if(BalanceFactor(p)==-2 && BalanceFactor(p->rChild)==-1){
            return RRRotation(p);
        }else if(BalanceFactor(p)==-2 && BalanceFactor(p->rChild)==1)
        {
            return RLRotation(p);
        }
        return p;
    }
    int BalanceFactor(Node *p)
    {
        int hl,hr;
        hl = (p && p->lChild) ? p->lChild->height : 0;
        hr = (p && p->rChild) ? p->rChild->height : 0;
        return hl-hr;

    }
    void display()
    {
        Inorder(root);
    }
    Node * inPre(Node *p)
    {
        while(p&&p->rChild)
        {
            p=p->rChild;
        }
        return p;
    }
    Node * inSucc(Node *p)
    {
        while(p&&p->lChild)
        {
            p=p->lChild;
        }
        return p;
    }
    Node * LLRotation(Node *p)
    {
        Node *pl = p->lChild;
        Node *plr = pl->rChild;
        pl->rChild = p;
        p->lChild = plr;

        p->height = NodeHeight(p);
        pl->height = NodeHeight(pl);

        if(root==p)root=pl;
        return pl;
    }
    Node * RRRotation(Node *p)
    {
        Node *pr = p->rChild;
        Node *prl = pr->lChild;
        pr->lChild = p;
        p->rChild = prl;

        p->height = NodeHeight(p);
        pr->height = NodeHeight(pr);

        if(root==p)root=pr;
        return pr;
    }
    Node * LRRotation(Node *p)
    {
        Node *left = p->lChild;
        Node *mid = left->rChild;
        left->rChild = mid->lChild;
        p->lChild = mid->rChild;
        mid->lChild = left;
        mid->rChild = p;

        left->height = NodeHeight(left);
        p->height = NodeHeight(p);

        mid->height = NodeHeight(mid);

        if(root==p)root=mid;
        return mid;

    }
    Node * RLRotation(Node *p)
    {
        Node *right = p->rChild;
        Node *mid = mid->lChild;

        p->rChild = mid->lChild;
        right->lChild = mid->rChild;
        mid->rChild = right;
        mid->lChild = p;

        right->height = NodeHeight(right);
        p->height = NodeHeight(p);

        mid->height = NodeHeight(mid);

        if(root ==p)root=mid;
        return mid;

    }
    void Inorder(Node *p)
    {

        if(p)
        {
            Inorder(p->lChild);
            cout<<p->data<<"->";
            Inorder(p->rChild);
        }
    }
};
int main()
{
    AVLTree avl = AVLTree();
    avl.rInsert(avl.root,20);
    avl.rInsert(avl.root,30);
    avl.rInsert(avl.root,40);
    avl.rInsert(avl.root,35);
    avl.rInsert(avl.root,32);
    avl.rInsert(avl.root,37);
    avl.display();
    return 0;
}
