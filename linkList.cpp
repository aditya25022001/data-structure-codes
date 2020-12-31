#include<iostream>
using namespace std;
struct node{
    int id;
    node *link;
};
node *root = NULL;
void reverseList(){
    node *leader=root, *follower=NULL, *temp;
    while(leader!=NULL){
        temp=follower;
        follower=leader;
        leader=leader->link;
        follower->link=temp;
    }
    root=follower;
}
void updateList(int dataToUpdate, int updatedValue){
    node *temp=root;
    if(temp==NULL){
        cout<<endl<<"List is empty!";
        return;
    }
    else{
        while(temp!=NULL){
            if(temp->id==dataToUpdate){
                temp->id=updatedValue;
                return;
            }
            temp=temp->link;
        }
    }
}
void show(){
    node *tempShow = root;
    cout<<endl<<"Displaying link list : ";
    while(tempShow!=NULL){
        cout<<tempShow->id<<" ";
        tempShow=tempShow->link;
    }
}
int length(){
    node *temp=root;
    int length=0;
    if(temp==NULL){
        return 0;
    }
    while(temp!=NULL){
        length++;
        temp=temp->link;
    }
    return length;
}
void deleteNode(int where){
    node *temp = root, *tempPrev = root;
    if(root==NULL){
        cout<<endl<<"List is Empty!";
        exit(0);
    }
    else{
        if(where==1){
            root=temp->link;
            delete temp;
            return;
        }
        else{
            while(temp->link!=NULL){
                tempPrev=temp;
                temp=temp->link;
            }
            tempPrev->link=NULL;
            delete temp;
        }
    }
}
void addNode(int data, int where){
    node *temp = new node;
    temp->id=data;
    temp->link=NULL;
    if(where==1){
        if(root==NULL)
            root=temp;
        else{
            node *tmp=root;
            while(tmp->link!=NULL){
                tmp=tmp->link;
            }
            tmp->link=temp;
        }
    }
    else{
        temp->link=root;
        root=temp;
    }
}
int main(){
    cout<<endl<<" "<<length();
    addNode(1,1);
    addNode(2,1);
    addNode(3,1);
    addNode(4,1);
    addNode(5,1);
    addNode(6,1);
    addNode(7,2);
  //  cout<<endl<<" "<<length();
    show();
    deleteNode(1);
   // cout<<endl<<" "<<length();
   // updateList(5,7);
    show();
    deleteNode(2);
  //  reverseList();
    show();
    return 0;
}