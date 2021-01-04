#include<iostream>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node *root = NULL;
int c=0;
void preOrderTraversal(node *t){
    if(t==NULL)
        return;    
    cout<<"->"<<t->data;
    preOrderTraversal(t->left);
    preOrderTraversal(t->right);
}
void postOrderTraversal(node *t){
    if(t==NULL)
        return;   
    postOrderTraversal(t->left);
    postOrderTraversal(t->right);
    cout<<"->"<<t->data;
}
void inOrderTraversal(node *t){
    if(t==NULL)
        return;
    inOrderTraversal(t->left);
    cout<<"->"<<t->data;
    inOrderTraversal(t->right);
}
int inOrderSuccessor(int dataI){
    node *temp = root;
    if(temp==NULL)
        return -1;
    else{

    }
}
int inOrderPredcessor(){}
int preOrderSuccessor(){}
int preOrderPredcessor(){}
int postOrderSuccessor(){}
int postOrderPredcessor(){}
void updateLeaf(){}
void deleteLeaf(){}
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
int main(){
    addLeaf(5);
    addLeaf(3);
    addLeaf(7);
    addLeaf(2);
    addLeaf(4);
    addLeaf(6);
    addLeaf(8);
    addLeaf(9);
    cout<<endl<<"Inorder ";
    inOrderTraversal(root);
    cout<<endl<<"Preorder ";
    preOrderTraversal(root);
    cout<<endl<<"Postorder ";
    postOrderTraversal(root);
}