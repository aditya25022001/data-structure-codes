#include<iostream>
using namespace std;
struct node{
    int id;
    node *link;
};
node *top=NULL;
int length(){
    node *len=top;
    int length=0;
    if(len==NULL)
        return 0;
    else{
        while(len!=NULL){
            length++;
            len=len->link;
        }
        return length;
    }
}
void showList(){
    node *tempShow=top;
    if(tempShow==NULL){
        cout<<endl<<"List empty ";
        exit(0);
    }
    else{
        cout<<endl<<"Displaying stack : ";
        while(tempShow!=NULL){
            cout<<tempShow->id<<" ";
            tempShow=tempShow->link;
        }
    }
}
int popNode(){
    node *temp=top;
    if(temp==NULL){
        cout<<endl<<"Stack empty ";
        exit(0);
    }
    else{
        top=top->link;
        cout<<endl<<"Popping : "<<temp->id;
        delete temp;
    }
}
void pushNode(int data){
    node *temp = new node;
    temp->id=data;
    temp->link=top;
    top=temp;
}
int main(){
   // popNode();
    cout<<endl<<length();
    pushNode(1);
    pushNode(2);
    pushNode(3);
    pushNode(4);
    pushNode(5);
    pushNode(6);
    cout<<endl<<length();
    popNode();
    showList();
}