#include<iostream>
using namespace std;
struct node{
    char data;
    node *prev;
    node *next;
};
node *head=NULL;
int length(){
    int count=0;
    node *temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
void addNode(char data){
    node *temp = new node;
    temp->data=data;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
        temp->prev=head;
        head->prev=NULL;
    }
    else{
        node *tmp = head;
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=temp;
        temp->prev=tmp;
    }
}
void Palindrome(){
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node *tmp=temp;
    temp=head;
    int x=length();
    int z=0;
    int y=1;
    if(x%2==1){
        while(temp!=tmp){
            if(temp->data==tmp->data){
                z++;
            }
            temp=temp->next;
            tmp=tmp->prev;
        }
        if(z==x/2){
            cout<<"Palindrome";
        }
    }
    if(x%2==0){
        while(y<=x/2){
            if(temp->data==tmp->data){
                z++;
            }
            temp=temp->next;
            tmp=tmp->prev;
            y++;
        }
        if(z==x/2){
            cout<<"Palindrome";
        }
    }
}
int main(){
    addNode('a');
    addNode('e');
    addNode('t');
    addNode('e');
    addNode('a');
 //   addNode('a');
    Palindrome();
}