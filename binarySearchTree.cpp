#include<iostream>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node *root = NULL;
int c=0, h=0;
int ltree, rtree;
int inOrder[10];
int preOrder[10];
int postOrder[10];
int i=0, j=0, k=0;
int maxi(int a, int b){
    return a>b ? a : b;
}
int level(node *t){
    if(t==NULL)
        return 0;
    ltree = level(t->left);
    rtree = level(t->right);
    return maxi(ltree, rtree) + 1;
}
int height(node *t){
    if(t==NULL)
        return -1;
    ltree = height(t->left);
    rtree = height(t->right);
    return maxi(ltree, rtree) + 1;
}
void preOrderTraversal(node *t){
    if(t==NULL)
        return;    
    cout<<"->"<<t->data;
    preOrder[j]=t->data;
    j++;
    preOrderTraversal(t->left);
    preOrderTraversal(t->right);
}
void postOrderTraversal(node *t){
    if(t==NULL)
        return;   
    postOrderTraversal(t->left);
    postOrderTraversal(t->right);
    cout<<"->"<<t->data;
    postOrder[k]=t->data;
    k++;
}
void inOrderTraversal(node *t){
    if(t==NULL)
        return;
    inOrderTraversal(t->left);
    cout<<"->"<<t->data;
    inOrder[i]=t->data;
    i++;
    inOrderTraversal(t->right);
}
int inOrderSuccessor(int dataI){
    for(int p=0;p<i;++p)
        if(inOrder[p]==dataI)
            return inOrder[p+1];
    return -1;
}
int inOrderPredcessor(int dataI){
    for(int p=0;p<i;++p)
        if(inOrder[p]==dataI)
            return inOrder[p-1];
    return -1;
}
int preOrderSuccessor(int dataI){
    for(int p=0;p<j;++p)
        if(preOrder[p]==dataI)
            return preOrder[p+1];
    return -1;
}
int preOrderPredcessor(int dataI){
    for(int p=0;p<j;++p)
        if(preOrder[p]==dataI)
            return preOrder[p-1];
    return -1;
}
int postOrderSuccessor(int dataI){
    for(int p=0;p<k;++p)
        if(postOrder[p]==dataI)
            return postOrder[p+1];
    return -1;
}
int postOrderPredcessor(int dataI){
    for(int p=0;p<k;++p)
        if(postOrder[p]==dataI)
            return postOrder[p-1];
    return -1;
}
int deleteLeaf(int dataI){
    node *tempPrev;
    node *temp = root;
    if(temp==NULL)
        return 0;
    else{
        while(temp!=NULL){
            if(temp->data<dataI){
                tempPrev=temp;
                temp=temp->right;
                c=1;
                continue;
            }
            if(temp->data>dataI){
                tempPrev=temp;
                temp=temp->left;
                c=0;
                continue;
            }
            if(temp->data==dataI && temp!=root && temp->left==NULL && temp->right==NULL){
                if(c==0){
                    tempPrev->left=NULL;
                    delete temp;
                    return 1;
                }
                if(c==1){
                    tempPrev->right=NULL;
                    delete temp;
                    return 1;
                }
            }
            else{
                cout<<endl<<"Cannot delete parent node directly";
                return 0;
            }
        }
    }

}
void addLeaf(int dataI){
    node *temp = new node;
    temp->data = dataI;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
        root=temp;
    else{
        node *tmp = root;
        node *tempPrev;
        while(tmp!=NULL){
            if(temp->data<tmp->data){
                tempPrev=tmp;
                tmp=tmp->left;
                c=0;
            }
            else{
                tempPrev=tmp;
                tmp=tmp->right;
                c=1;
            }
        }
        if(c==0)
            tempPrev->left=temp;
        if(c==1)
            tempPrev->right=temp;
    }
}
void updateLeaf(int dataI, int dataU){
    if(deleteLeaf(dataI)==1)
        addLeaf(dataU);
}
int search(int data){
    int level=0;
    node *temp = root;
    node *tempPrev;
    if(temp==NULL)
        return -1;
    else{
        while(temp!=NULL){
            if(data<temp->data){
                tempPrev=temp;
                temp=temp->left;
                c=0;
            }
            if(data>temp->data){
                tempPrev=temp;
                temp=temp->right;
                c=1;
            }
            if(data==temp->data){
                if(c==0){
                    cout<<endl<<"Left child of "<<tempPrev->data;
                    return 1;
                }
                if(c==1){
                    cout<<endl<<"Right child of "<<tempPrev->data;
                    return 1;
                }
            }
        }
        return -1;
    }
}
int main(){
    addLeaf(5);
    addLeaf(3);
    addLeaf(7);
    addLeaf(2);
    addLeaf(4);
    addLeaf(6);
    addLeaf(8);
    addLeaf(15);
    addLeaf(0);
    addLeaf(-2);
    addLeaf(21);
    cout<<endl<<"Inorder ";
    inOrderTraversal(root);
    cout<<endl<<"Preorder ";
    preOrderTraversal(root);
    cout<<endl<<"Postorder ";
    postOrderTraversal(root);
    cout<<endl<<"Height of tree is : "<<height(root)<<" with levels : "<<level(root);
    cout<<endl<<endl<<"Search 21 : "<<search(21);
}