#include<iostream>
using namespace std;
struct node{
    char data;
    node *left;
    node *right;
};
char treeLeaves[100];
node *parent;
node *root=NULL;
void addLeaf(char a, char b){
    node *temp = new node;
    temp->data=a;
    temp->right=NULL;
    temp->left=NULL;
    if(root==NULL)
        root=temp;
    if(b=='p')
        parent=temp;
    if(b=='s')
        parent->left=temp;
    if(b=='o'){
        parent->right=temp;
        node *tmp=root;
        while(tmp->left!=parent || tmp->right!=parent){
            
        }
    }
}
void createTree(int n){
    for(int i=1;i<n;++i){
        if(treeLeaves[i+1]=='('){
            addLeaf(treeLeaves[i], 'p');
            i++;
        }       
        if(treeLeaves[i+1]==','){
            addLeaf(treeLeaves[i], 's');
            i++;
        } 
        if(treeLeaves[i+1]==')'){
            addLeaf(treeLeaves[i], 'o');
            i++;
        }
        if(treeLeaves[i]==')' || treeLeaves[i]=='(' || treeLeaves[i]==',');
    }
}
void traverseInOrderRecursion(node *t){
    if(t==NULL)
        return;
    traverseInOrderRecursion(t->left);
    traverseInOrderRecursion(t->right);
}
void traversePreOrderRecursion(){
    
}
void traversePostOrderRecursion(){
    
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
    return 0;
}