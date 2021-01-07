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
void createTree(int n){
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

}
void traversePreOrderIterative(){
    
}
void traversePostOrderIterative(){
    
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
    return 0;
}