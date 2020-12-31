#include<iostream>
using namespace std;
struct node{
    int data;
    node *prev;
    node *next;
};
node *head=NULL; 
void display(int order){
    node *temp = head;
    if(order==1){
        cout<<endl<<"Straight order : ";
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    else{
        cout<<endl<<"Reverse order : ";
        while(temp->next!=NULL){
            temp=temp->next;
        }
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
    }
}
int length(){
    int count=0;
    node *temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
void update(int dataToUpdate, int updatedData){
    node *temp=head;
    while(temp!=NULL){
        if(temp->data == dataToUpdate){
            temp->data=updatedData;
        }
        temp=temp->next;
        }
}
void deleteNode(int data){
    node *temp=head, *tempPrev=head, *tempNext=head;
    while(temp!=NULL){
        if(temp->data==data){
            if(temp==head){
                head=temp->next;
                temp->next->prev=NULL;
                delete temp;
                return;
            }
            else{
                if(temp->next==NULL){
                    temp->prev->next=NULL;
                    delete temp;
                    return;
                }
                else{
                    tempPrev=temp->prev;
                    tempNext=temp->next;
                    tempPrev->next=tempNext;
                    tempNext->prev=tempPrev;
                    delete temp;
                }
            }
        }
        temp=temp->next;
    }
}
void addNode(int data, int where){
    node *temp = new node;
    temp->data=data;
    switch (where){
        case 1:
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
            break;
        case 2:
            temp->next=head;
            head->prev=temp;
            temp->prev=NULL;
            head=temp;
            break;
    }
}
void addAfterBeforeNode(int data, int choice, int reference){
    node *temp = new node;
    temp->data=data;
    node *tmp=head;
    switch (choice){
        case 1:
            while(tmp!=NULL){
                if(tmp->data==reference){
                    tmp->next->prev=temp;
                    temp->next=tmp->next;
                    tmp->next=temp;
                    temp->prev=tmp;
                    break;
                }
                tmp=tmp->next;
            }
            break;
        case 2:
            while(tmp!=NULL){
                if(tmp->data==reference){
                    (tmp->prev)->next=temp;
                    temp->prev=tmp->prev;
                    tmp->prev=temp;
                    temp->next=tmp;
                    break;
                }
                tmp=tmp->next;
            }
            break;
    }
}
int main(){
    addNode(1,1);
    addNode(2,1);
    addNode(3,1);
    addNode(4,1);
    addNode(5,1);
    addNode(6,1);
    addNode(7,1);
    addNode(8,1);
    addNode(9,1);
    addNode(10,1);
    addNode(11,1);
    display(1);
    //display(2);
    addAfterBeforeNode(12,1,8);
    addAfterBeforeNode(23,2,5);
    display(1);
   // display(2);
  //  cout<<endl<<"length : "<<length()<<endl;
  //  display(1);
  //  display(2);
    deleteNode(1);
    deleteNode(7);
    deleteNode(11);
  //  deleteMiddle();
   // cout<<endl<<"length : "<<length()<<endl;
    display(1);
  //  display(2);
   // update(1,10);
   // update(8,13);
   // cout<<endl<<"length : "<<length()<<endl;
   // display(1);
   // display(2);
}