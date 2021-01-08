#include<iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node*right;
};
node *root=NULL;
node *rootThreaded = NULL;
int c=0, i=0;
node *inOrder[10];
void inOrderTraversal(node *t){
    if(t==NULL)
        return;
    inOrderTraversal(t->left);
    inOrder[i]=t;
    if(i==0)
        rootThreaded=t;
    i++;
    inOrderTraversal(t->right);
}
void addLeaf(int dataI){
    node *temp = new node;
    temp->data = dataI;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL){
        root=temp;
        rootThreaded = root;
    }
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
void convertSingleThreaded(){
    for(int j=0;j<i-1;++j)
        inOrder[j]->left=inOrder[j+1];
}
void convertDoubleThreaded(){
    for(int j=0;j<i-1;++j)
        inOrder[j]->left=inOrder[j+1];
    for(int j=1;j<i;++j)
        inOrder[j]->right=inOrder[j-1];
}
void disp(){
    node *temp=rootThreaded;
    while(temp!=NULL){
        cout<<"->"<<temp->data;
        temp=temp->left;
    }
}
int iosuc(int k){
    node *temp = rootThreaded;
    while(temp->data!=k)
        temp=temp->left;
    return temp->left->data;
}
int iopred(int k){
    node *temp = rootThreaded;
    while(temp->data!=k)
        temp=temp->left;
    if(temp->right!=NULL)
        return temp->right->data;
    else
        return -1;
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
    inOrderTraversal(root);
    //convertSingleThreaded();
    //disp();
    convertDoubleThreaded();
    cout<<endl<<"io suc of -2 : "<<iosuc(-2);
    cout<<endl<<"io pred of -2 : "<<iopred(-2);
    cout<<endl<<"io pred of 5 : "<<iopred(5);
    cout<<endl<<"io pred of 21 : "<<iopred(21);
    cout<<endl<<"io pred of 7 : "<<iopred(7);
}