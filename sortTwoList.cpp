#include<iostream>
using namespace std;
struct node{
    int id;
    node *link;
};
node *root3 = NULL;
node *root1 = NULL;
node *root2 = NULL;
void show(int listNo){
    if(listNo==1){
        node *tempShow = root1;
        cout<<endl<<"Displaying link list : ";
        while(tempShow!=NULL){
            cout<<tempShow->id<<" ";
            tempShow=tempShow->link;
        }
    }
    if(listNo==2){
        node *tempShow1 = root2;
        cout<<endl<<"Displaying link list : ";
        while(tempShow1!=NULL){
            cout<<tempShow1->id<<" ";
            tempShow1=tempShow1->link;
        }
    }
    if(listNo==3){
        node *tempShow2 = root3;
        cout<<endl<<"Displaying link list : ";
        while(tempShow2!=NULL){
            cout<<tempShow2->id<<" ";
            tempShow2=tempShow2->link;
        }
    }
}
int length(int listNo){
    if(listNo==1){
        node *temp=root1;
        int length1=0;
        if(temp==NULL){
            return 0;
        }
        while(temp!=NULL){
            length1++;
            temp=temp->link;
        }
        return length1;
    }
    else{
        node *temp1=root2;
        int length=0;
        if(temp1==NULL){
            return 0;
        }
        while(temp1!=NULL){
            length++;
            temp1=temp1->link;
        }
        return length;
    }
}
void addNode(int data, int listNo){
    if(listNo==1){
        node *temp = new node;
        temp->id=data;
        temp->link=NULL;
        if(root1==NULL)
            root1=temp;
        else{
            node *tmp=root1;
            while(tmp->link!=NULL){
                tmp=tmp->link;
            }
            tmp->link=temp;
        }
    }
    if(listNo==2){
        node *temp1 = new node;
        temp1->id=data;
        temp1->link=NULL;
        if(root2==NULL)
            root2=temp1;
        else{
            node *tmp1=root2;
            while(tmp1->link!=NULL){
                tmp1=tmp1->link;
            }
            tmp1->link=temp1;
        }
    }
    if(listNo==3){
        node *temp2 = new node;
        temp2->id=data;
        temp2->link=NULL;
        if(root3==NULL)
            root3=temp2;
        else{
            node *tmp2=root3;
            while(tmp2->link!=NULL){
                tmp2=tmp2->link;
            }
            tmp2->link=temp2;
        }
    }
}
void sortedmerge(node *a, node *b){
    if(a==NULL){
        root3=b;
        return;
    }
    else{
        if(b==NULL){
            root3=a;
            return;
        }
    }
    while(a!=NULL && b!=NULL){
        if(a->id<b->id){
            addNode(a->id,3);
            a=a->link;
        }
        if(a->id>b->id){
            addNode(b->id,3);
            b=b->link;
        }
        if(a->id==b->id){
            addNode(a->id,3);
            a=a->link;
            b=b->link;
        }
    }
    while(a!=NULL){
        addNode(a->id,3);
        a=a->link;
    }
    while(b!=NULL){
        addNode(b->id,3);
        b=b->link;
    }
}
int main(){
    addNode(-2,1);
    addNode(4,1);
    addNode(7,1);
    addNode(8,1);
    addNode(10,1);
    addNode(4,2);
    addNode(5,2);
    addNode(9,2);
    addNode(10,2);
    addNode(17,2);
    show(1);
    show(2);
    sortedmerge(root1, root2);
    show(3);
}