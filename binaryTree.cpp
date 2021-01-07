#include<iostream>
using namespace std;
struct node{
    string data;
    node *left;
    node *right;
};
int index=0;
string treeLeaves[100];
node *root=NULL;
node *parents[100];
node *parents1[100];
void createTree(int n){
    index=0;
    for(int i=0;i<n;i++){
        if(treeLeaves[i]!="(" && treeLeaves[i]!="," && treeLeaves[i]!=")"){
            node *temp = new node;
            temp->data = treeLeaves[i];
            temp->right=NULL;
            temp->left=NULL;
            if(treeLeaves[i-1]=="(" && treeLeaves[i+1]=="(" && root!=NULL){
                parents[index-1]->left=temp;
                parents[index]=temp;
                index++;
            }
            if(treeLeaves[i-1]=="," && treeLeaves[i+1]=="(" && root!=NULL){
                parents[index-1]->right=temp;
                parents[index]=temp;
                index++;
            }
            if(treeLeaves[i-1]=="," && treeLeaves[i+1]==")" && root!=NULL){
                parents[index-1]->right=temp;
                index--;
            }
            if(treeLeaves[i-1]=="(" && treeLeaves[i+1]=="," && root!=NULL){
                parents[index-1]->left=temp;
            }
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
void traverseInOrderRecursion(node *t){
    if(t==NULL)
        return;
    traverseInOrderRecursion(t->left);
    cout<<"->"<<t->data;
    traverseInOrderRecursion(t->right);
}
void traversePreOrderRecursion(node *t){
    if(t==NULL)
        return;
    cout<<"->"<<t->data;
    traversePreOrderRecursion(t->left);
    traversePreOrderRecursion(t->right);   
}
void traversePostOrderRecursion(node *t){
    if(t==NULL)
        return;
    traversePostOrderRecursion(t->left);
    traversePostOrderRecursion(t->right);
    cout<<"->"<<t->data;
}
void traverseInOrderIterative(){
    index=-1;
    node *temp = root;
    while(temp!=NULL || index!=-1){
        if(temp!=NULL){
            index++;
            parents1[index]=temp;
            temp=temp->left;
        }
        else{
            temp=parents1[index];
            index--;
            cout<<"->"<<temp->data;
            temp=temp->right;
        }
    }
}
void traversePreOrderIterative(){
    index=-1;
    node *temp = root;
    index++;
    parents1[index]=temp;
    while (index>-1){
        temp = parents1[index];
        cout<<"->"<<temp->data;
        index--;
        if (temp->right){
            index++;
            parents1[index]=temp->right;
        }
        if (temp->left){
            index++;
            parents1[index]=temp->left;
        }
    }
}
void traversePostOrderIterative(){
    index=-1;
    index++;
    int indexPost = -1;
    node *temp = root;
    parents1[index]=temp;
    string post[100];
    while(index>-1){
        temp = parents1[index];
        index--;
        indexPost++;
        post[indexPost]=temp->data;
        if(temp->left){
            index++;
            parents1[index]=temp->left;
        } 
        if(temp->right){
            index++;
            parents1[index]=temp->right;
        }
    }
    while (indexPost>-1){
        cout<<"->"<<post[indexPost];
        indexPost--;
    }
}
int main(){
    int n;
    cout<<endl<<"Enter tree string size with parenthesis and comma : ";
    cin>>n;
    cout<<endl<<"Enter tree string one by one with parenthesis and comma : ";
    for(int i=0;i<n;i++)
        cin>>treeLeaves[i];
    createTree(n);
    cout<<endl<<"Inorder ";
    traverseInOrderRecursion(root);
    cout<<endl<<"Preorder ";
    traversePreOrderRecursion(root);
    cout<<endl<<"Postorder ";
    traversePostOrderRecursion(root);
    cout<<endl<<"Inorder ";
    traverseInOrderIterative();
    cout<<endl<<"Preorder ";
    traversePreOrderIterative();
    cout<<endl<<"Postorder ";
    traversePostOrderIterative();
    return 0;
}