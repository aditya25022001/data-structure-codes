#include<iostream>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node *root = NULL;
int c=0;
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
int search(int data){
    node *temp = root;
    node *tempPrev;
    if(temp==NULL){
        cout<<endl<<"Empty tree";
        return -1;
    }
    else{
        while(temp!=NULL){
            if(data<temp->data){
                tempPrev=temp;
                temp=temp->left;
                if(temp==NULL)
                    break;
                c=0;
            }
            if(data>temp->data){
                tempPrev=temp;
                temp=temp->right;
                if(temp==NULL)
                    break;
                c=1;
            }
            if(data==temp->data){
                if(c==0){
                    cout<<"Found";
                    cout<<endl<<"Left child of "<<tempPrev->data;
                    return 1;
                }
                if(c==1){
                    cout<<"Found";
                    cout<<endl<<"Right child of "<<tempPrev->data;
                    return 1;
                }
            }
        }
        cout<<endl<<"Not found!";
        return -1;
    }
}
int main(){
    addLeaf(8);
    addLeaf(3);
    addLeaf(10);
    addLeaf(1);
    addLeaf(6);
    addLeaf(14);
    addLeaf(4);
    addLeaf(7);
    addLeaf(13);
    search(7);
    search(15);
    return 0; 
}