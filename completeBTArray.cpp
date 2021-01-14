//construct array from complete binary tree

#include<iostream>
using namespace std;
struct node{
    string data;
    node *right;
    node *left;
};

node *root=NULL;             //root node of the tree since we have to create the tree not given then compile it in the array 
node *parents[100];          //a structure needed to create the tree
node *queue[100];            //used to create array from created tree
string arrayOfTree[100];     //array of trees created 
string treeLeaves[100];      //user input for the string of tree to costruct the tree and then to convertthe tree into array
int index=0;                 //for the array of tree
int front=-1, rear=-1;       //for the queue

//left child of the element
string leftChild(string data){

}

//right child of the element
string rightChild(string data){

}

//parent of the element
string parent(string data){

}

//sibling of the element
string sibling(string data){

}

//push data into the queue
void push(node *item){
    if(rear == 99)
        cout<<endl<<" Queue is full ! ";
    else{
        rear++;
        queue[rear] = item;
        if(front == -1)
            front=0;
    }
}

//pop elements from the queue
void pop(){
    if(front == -1)
        cout<<endl<<"Queue is empty ! ";
    else{
        front++;
        if(front > rear){
            front = -1;
            rear = -1;
        }
    }
}

//check if the queue is empty
int isEmpty(){
    if(front==-1 || front>rear)
        return 1;
    else
        return 0;
}

//create the array of tree
int createArray(node *t){
    index=0;
    node *temp=t;
    push(temp);
    while(isEmpty()!=1){
        node *tmp = queue[front];
        arrayOfTree[index] = tmp->data;
        index++;
        pop();
        if(tmp->left!=NULL)
            push(tmp->left);
        if(tmp->right!=NULL)
            push(tmp->right);
    }
}

//create tree of input string
void createTree(int n){
    index=0;
    for(int i=0;i<n;i++){
        if(treeLeaves[i]!="(" && treeLeaves[i]!="," && treeLeaves[i]!=")"){
            node *temp = new node;
            temp->data = treeLeaves[i];
            temp->right=NULL;
            temp->left=NULL;

            //case 1 children of left child
            if(treeLeaves[i-1]=="(" && treeLeaves[i+1]=="(" && root!=NULL){
                parents[index-1]->left=temp;
                parents[index]=temp;
                index++;
            }

            //case 2 children of right child
            if(treeLeaves[i-1]=="," && treeLeaves[i+1]=="(" && root!=NULL){
                parents[index-1]->right=temp;
                parents[index]=temp;
                index++;
            }

            //case 3 right child
            if(treeLeaves[i-1]=="," && treeLeaves[i+1]==")" && root!=NULL){
                parents[index-1]->right=temp;
                index--;
            }

            //case 4 left child
            if(treeLeaves[i-1]=="(" && treeLeaves[i+1]=="," && root!=NULL){
                parents[index-1]->left=temp;
            }

            //case 5 only child
            if(treeLeaves[i-1]=="(" && treeLeaves[i+1]==")" && root!=NULL){
                parents[index-1]->left=temp;
                index--;
            }
            if(root==NULL){
                root=temp;
                parents[index]=temp;
                index++;
            }
        }
        if(treeLeaves[i]==")" && treeLeaves[i+1]==")")
            index--;
    }
}

//main method
int main(){
    int n;
    cout<<endl<<"Enter tree string size with parenthesis and comma : ";
    cin>>n;
    cout<<endl<<"Enter sring of tree : "<<endl;
    for(int i=0;i<n;i++)
        cin>>treeLeaves[i];
    createTree(n);
    createArray(root);
    for(int i=0;i<index;i++)
        cout<<arrayOfTree[i]<<"  ";
    return 0;
}