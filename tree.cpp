#include<iostream>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node *root = NULL;
void preOrderTraversal(){}
void postOrderTraversal(){}
void inOrderTraversal(node *t){
    
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
        while(tmp!=NULL){
            if(temp->data<tmp->data){
                cout<<temp->data<<" "; 
                tmp=tmp->left;
            }
            else{
                tmp=tmp->right;
            }
        }
        tmp=temp;
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
    inOrderTraversal(root);
}