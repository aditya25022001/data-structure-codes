#include<iostream>
using namespace std;
struct node{
    int id;
    node *link;
};
node *root = NULL;
void show(){
    node *tempShow = root;
    cout<<endl<<"Displaying link list : ";
    while(tempShow->link!=root){
        cout<<tempShow->id<<" ";
        tempShow=tempShow->link;
    }
    cout<<tempShow->id;
}
int length(){
    node *temp=root;
    int length=0;
    if(temp==NULL){
        return 0;
    }
    while(temp->link!=root){
        length++;
        temp=temp->link;
    }
    return length+1;
}
void updateList(int dataToUpdate, int updatedValue){
    node *temp=root;
    if(temp==NULL){
        cout<<endl<<"List is empty!";
        return;
    }
    else{
        int a=0;
        while(temp->link!=root){
            if(temp->id==dataToUpdate){
                temp->id=updatedValue;
                a=1;
                return;
            }
            temp=temp->link;
        }
        if(a==0 && temp->id==dataToUpdate){
            temp->id=updatedValue;
        }
    }
}
void deleteNode(int data){
    node *temp = root, *tempPrev = root;
    if(root==NULL){
        cout<<endl<<"List is Empty!";
        exit(0);
    }
    else{
        int a=0;
        while(temp->link!=root){
            if(temp->id==data){
                if(temp==root){
                    while(tempPrev->link!=root)
                        tempPrev=tempPrev->link;
                    tempPrev->link=temp->link;
                    root=tempPrev->link;
                    delete temp;
                    a=1;
                    return;
                }
                else{
                    tempPrev->link=temp->link;
                    a=1;
                    delete temp;
                    return;
                }
            }
            tempPrev=temp;
            temp=temp->link;
        }
        if(a==0 && temp->id==data){
            tempPrev->link=temp->link;
            delete temp;
            return;
        }
    }
}
void addNode(int data){
    node *temp = new node;
    temp->id=data;
    if(root==NULL){
        root=temp;
        temp->link=root;
    }
    else{
        node *tmp=root;
        while(tmp->link!=root){
            tmp=tmp->link;
        }
        tmp->link=temp;
        temp->link=root;
    }
    
}
int main(){
   // cout<<endl<<" "<<length();
    addNode(1);
    addNode(2);
    addNode(3);
    addNode(4);
    addNode(5);
    addNode(6);
    show();
    cout<<endl<<length();
    updateList(4,5);
    updateList(6,7);
    addNode(10);
    cout<<endl<<length();
    //cout<<endl<<" "<<length();
    show();
    deleteNode(10);
    show();
}