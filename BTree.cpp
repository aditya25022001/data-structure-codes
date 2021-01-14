#include<iostream>
using namespace std;
struct node{
    string data;
    node *left;
    node *right;
};
int index=0, ltree, rtree;
string treeLeaves[100];
node *root=NULL;
node *parents[100];
node *parents1[100];
void createTree(int n){
    index=0;
    for(int i=1;i<n-1;i++){
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
    cout<<endl<<"Enter tree string one by one with parenthesis and comma";
    cout<<endl<<"If only right child of any present then enter as following";
    cout<<endl<<"Eg. if 6 has only right child 7 then enter 6(,7) :";
    cout<<endl;
    for(int i=0;i<n;i++)
        cin>>treeLeaves[i];
    createTree(n);
    cout<<endl<<"Inorder Recursion ";
    traverseInOrderRecursion(root);
    cout<<endl<<endl<<"Preorder Recursion ";
    traversePreOrderRecursion(root);
    cout<<endl<<endl<<"Postorder Recursion ";
    traversePostOrderRecursion(root);
    cout<<endl<<endl<<"Inorder Iterative ";
    traverseInOrderIterative();
    cout<<endl<<endl<<"Preorder Iterative ";
    traversePreOrderIterative();
    cout<<endl<<endl<<"Postorder Iterative ";
    traversePostOrderIterative();
}