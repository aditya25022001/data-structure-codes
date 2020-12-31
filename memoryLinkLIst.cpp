#include<iostream>
using namespace std;
struct node{
    int size;
    node *link;
};
node *root = NULL;
void show(){
    node *tempShow = root;
    cout<<endl<<"Displaying link list : ";
    while(tempShow!=NULL){
        cout<<tempShow->size<<" ";
        tempShow=tempShow->link;
    }
}
void getField(int size2){
    int a=0;
    node *temp=root, *tempPrev=root;
    while(temp!=NULL){
        if(temp->size>=size2){
            temp->size-=size2;
            if(temp->size==0){
                cout<<endl<<"Best fit element found!";
                tempPrev->link=temp->link;
                delete temp;
            }
            cout<<endl<<"Memory found!";
            return;
        }
        tempPrev=temp;
        temp=temp->link;
    }
    if(a==0){
        cout<<endl<<"No such memory slot found";
    }
}
void addField(int size1){
    node *temp=new node;
    temp->size=size1;
    temp->link=NULL;
    if(root==NULL)
        root=temp;
    else{
        node *t=root;
        while(t->link!=NULL)
            t=t->link;
        t->link=temp;
    }
}
int main(){
    addField(15000);
    addField(8000);
    addField(41000);
    addField(16607);
    addField(21304);
    show();
    getField(14000);
    getField(41000);
    getField(42000);
    show();
    return 0;
}

