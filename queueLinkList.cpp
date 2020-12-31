#include<iostream>
using namespace std;
struct node{
    int id;
    node *link;
};
node *rear=NULL;
node *front=NULL;
int length(){
    node *leng=front;
    int length=0;
    if(leng==NULL){
        return 0;
    }
    else{
        while(leng!=NULL){
            length++;
            leng=leng->link;
        }
        return length;
    }
}
void showQueue(){
    node *tempShow=front;
    if(tempShow==NULL){
        cout<<endl<<"Queue is empty";
        exit(0);
    }
    else{
        cout<<endl<<"Displaying queue : ";
        while(tempShow!=NULL){
            cout<<tempShow->id<<" ";
            tempShow=tempShow->link;
        }
    }
}
int dequeueNode(){
    node *temp=front;
    if(temp==NULL){
        cout<<endl<<"Queue is empty";
        exit(0);
    }
    else{
        front=front->link;
        cout<<endl<<"Popping : "<<temp->id;
        delete temp;
        if(front==NULL)
            rear=NULL; 
    }
}
void enqueueNode(int data){
    node *temp=new node;
    temp->id=data;
    temp->link=NULL;
    if(front==NULL){
        front=temp;
        rear=temp;
    }
    else{
        rear->link=temp;
        rear=temp;
    }
}
int main(){
    cout<<endl<<length();
    enqueueNode(1);
    enqueueNode(2);
    enqueueNode(3);
    enqueueNode(4);
    enqueueNode(5);
    enqueueNode(6);
    cout<<endl<<length();
    dequeueNode();
    showQueue();
}