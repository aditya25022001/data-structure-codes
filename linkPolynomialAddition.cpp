#include<iostream>
using namespace std;
struct node{
    int coeff;
    int power;
    node *link;
};
node *root3 = NULL; //result
node *root1 = NULL; //p1
node *root2 = NULL; //p2
void show(int listNo){
    if(listNo==1){
        node *tempShow = root1;
        cout<<endl<<"Polynomial 1 : ";
        while(tempShow!=NULL){
            if(tempShow->power>0)
            cout<<tempShow->coeff<<"x^"<<tempShow->power<<"+";
            else{
                cout<<tempShow->coeff<<"x^"<<tempShow->power;
                }
            tempShow=tempShow->link;
        }
    }
    if(listNo==2){
        node *tempShow1 = root2;
        cout<<endl<<"Polynomial 2 : ";
        while(tempShow1!=NULL){
            if(tempShow1->power>0)
            cout<<tempShow1->coeff<<"x^"<<tempShow1->power<<"+";
            else{
                cout<<tempShow1->coeff<<"x^"<<tempShow1->power;
                }
            tempShow1=tempShow1->link;
        }
    }
    if(listNo==3){
        node *tempShow2 = root3;
        cout<<endl<<"Resultant polynomial : ";
        while(tempShow2!=NULL){
            if(tempShow2->power>0)
                cout<<tempShow2->coeff<<"x^"<<tempShow2->power<<"+";
            else{
                cout<<tempShow2->coeff<<"x^"<<tempShow2->power;
                }
            tempShow2=tempShow2->link;
        }
    }
}
void addNode(int coef, int pow, int listNo){
    if(listNo==1){
        node *temp = new node;
        temp->coeff=coef;
        temp->power=pow;
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
        temp1->coeff=coef;
        temp1->power=pow;
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
        temp2->coeff=coef;
        temp2->power=pow;
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
void addPolynomial(){
    int netCoef;
    node *tmp1=root1, *tmp2=root2;
    while(tmp1!=NULL && tmp2!=NULL){
        if(tmp1->power==tmp2->power){
            netCoef=tmp1->coeff+tmp2->coeff;
            if(netCoef!=0)
                addNode(netCoef,tmp1->power,3);
            tmp1=tmp1->link, tmp2=tmp2->link; 
            continue;
        }
        if(tmp1->power>tmp2->power){
            addNode(tmp1->coeff,tmp1->power,3);
            tmp1=tmp1->link;
            continue;
        }
        if(tmp1->power<tmp2->power){
            addNode(tmp2->coeff,tmp2->power,3);
            tmp2=tmp2->link;
            continue;
        }
    }
    while(tmp1!=NULL){
        addNode(tmp1->coeff,tmp1->power,3);
        tmp1=tmp1->link;
    }
    while(tmp2!=NULL){
        addNode(tmp2->coeff,tmp2->power,3);
        tmp2=tmp2->link;
    }
}
int main(){
    int coef, pow, terms;
    cout<<endl<<"Enter terms in p1 :";
    cin>>terms;
    cout<<endl<<"Enter polynomial 1 : coefficient then power"<<endl;
    for(int i=0;i<terms;i++){
        cout<<"Coeff : ";
        cin>>coef;
        cout<<"Power: ";
        cin>>pow;
        cout<<endl;
        addNode(coef,pow,1);
    }
    cout<<endl<<"Enter terms in p2 :";
    cin>>terms;
    cout<<endl<<"Enter polynomial 2 : coefficient then power";
    for(int i=0;i<terms;i++){
        cout<<"Coeff : ";
        cin>>coef;
        cout<<"Power: ";
        cin>>pow;
        cout<<endl;
        addNode(coef,pow,2);
    }
    addPolynomial();
    show(1);
    show(2);
    show(3);
}