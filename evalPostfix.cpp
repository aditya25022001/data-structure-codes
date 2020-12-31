#include<iostream>
#include<math.h>
using namespace std;
class evaluation{
    string pexp[100];
    double eval[100], a, b, c;
    int length, top, rank;
    
public:

    //constructor
    evaluation(int len){
        top=-1;
        length=len;
    }

    //get expression
    void getExpression(){
        cout<<endl<<"Enter expression : ";
        for(int i=0;i<length;i++)
            cin>>pexp[i];
    }

    //ordering
    int order(string a){
        if(a=="^")
            return 1;
        if(a=="*")
            return 2;
        if(a=="/")
            return 3;
        if(a=="+")
            return 4;
        if(a=="-")
            return 5;
    }

   //push
   void pushEl(double item){
       top++;
       eval[top]=item;
   }
   
   //pop
   void popEl(int r){
       a=eval[top];
       top--;
       b=eval[top];
       top--;
       switch (r){
        case 1:
           pushEl(pow(b,a)); 
           break;
        case 2:
           pushEl(b*a); 
           break;
        case 3:
           pushEl(b/a); 
           break;
        case 4:
           pushEl(a+b); 
           break;
        case 5:
           pushEl(b-a); 
           break;
       }
   }
   
    //evaluate
    void evaluate(){
        if(pexp[1]=="-")
            pushEl(0);
        for(int i=0;i<length;i++){
            if(pexp[i]=="*" || pexp[i]=="^" || pexp[i]=="-" || pexp[i]=="+" || pexp[i]=="/" || pexp[i]=="!"|| pexp[i]=="|"|| pexp[i]=="&"){
                rank=order(pexp[i]);
                popEl(rank);
            }
            else{
                pushEl(stod(pexp[i]));
            }
        }
    }

    //display
    void display(){
        for(int i=0;i<=top;i++)
            cout<<eval[i]<<"  ";
    }

};
int main(){
    int lrn=0;
    cout<<endl<<"enter len : ";
    cin>>lrn;
    evaluation e(lrn);
    e.getExpression();
    e.evaluate();
    e.display();
}