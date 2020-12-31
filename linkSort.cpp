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
void addNode(int data){
    node *temp = new node;
    temp->id=data;
    temp->link=NULL;
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
void createSortedArray(int arr[], int len){
    node *temp=root;
    int index=0;
    while(temp!=NULL){
        temp->id=arr[index];
        index++;
        temp=temp->link;
    }
    cout<<endl<<"Sorted list : ";
    show();
}
void sortArray(int arr[], int len){
    int temp;
    for(int i=0;i<len;++i)
        for(int j=0;j<len;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    createSortedArray(arr,len);
}
void sortList(){
    node *temp=root;
    if(temp==NULL){
        cout<<endl<<"Empty list";
        exit(0);
    }
    else{
        int index=0;
        int arr[length()];
        while(temp!=NULL){
            arr[index]=temp->id;
            index++;
            temp=temp->link;
        }
        sortArray(arr,length());
    }
}
int main(){
    addNode(4);
    addNode(-2);
    addNode(31);
    addNode(8);
    addNode(7);
    addNode(14);
    addNode(5);
    addNode(21);
    addNode(16);
    addNode(10);
    show();
    sortList();
}