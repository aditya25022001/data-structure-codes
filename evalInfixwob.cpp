#include<iostream>
#include<math.h>
using namespace std;
class itop{
    string iexp[100];
    string pexp[100];
    string oper[100];
    double eval[100], a, b, c;
    int top, length, up, chec, rank, top2, top3;
public:
    
    //intialisation
    itop(int len){
        top=-1;
        up=-1;
        top2=-1;
        top3=-1;
        length =len;
    }

    //get expression
    void getExpr(){
        cout<<endl<<"Enter the expression : ";
        for(int i=0;i<length;i++){
            cin>>iexp[i];
            top2+=1;
        }
    }

    //ranking
    int ranking(string item){
        if(item == "^" || item == "!")
            return 1;
        if(item == "*" || item == "/")
            return 2;
        if(item == "+" || item == "-")
            return 3;
        if(item == "<" || item == ">" || item == "=")
            return 4;
        if(item == "&")
            return 5;
        if(item == "|")
            return 6;
    }

    //pushOp function
    int pushOp(int item, string ite){
        if(up==-1){
            up++;
            oper[up]=ite;
        }
        else{
            for(int i=up;i>=0;i--){
                if(ranking(oper[i])<=item){
                    pushEl(oper[i], 1);
                    up--;
                }
                if(ranking(oper[i])>=item || up==-1){
                    up++;
                    oper[up]=ite;
                    break;
                }
            }
        }
    }

    //push function
    void pushEl(string item, int choice){
        if(choice == 1){
            top++;
            pexp[top]=item;
        }
        else{
            chec=ranking(item);
            pushOp(chec, item);
        }
    }

    //convert the expression
    void convertExp(){
        for(int i=0;i<length;i++){
            if(iexp[i]!="*" && iexp[i]!="^" && iexp[i]!="-" && iexp[i]!="+" && iexp[i]!="/" && iexp[i]!="=" && iexp[i]!=">" && iexp[i]!="<" && iexp[i]!="!" && iexp[i]!="|" && iexp[i]!="&")
                pushEl(iexp[i], 1);
            else{
                pushEl(iexp[i], 2);
            }
        }
        for(int i=up;i>=0;i--)
            pushEl(oper[i], 1);
    }

    //display the expression
    void display(){
        cout<<endl<<"Infix Expression : ";
        for(int i=0;i<=top2;i++)
            cout<<iexp[i]<<" ";
        cout<<endl<<"Postfix Expression : ";
        for(int i=0;i<=top;i++)
            cout<<pexp[i]<<" ";
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
    void pushElEv(double item){
       top3++;
       eval[top3]=item;
    }

    //pop
    void popEl(int r){
       a=eval[top3];
       top3--;
       b=eval[top3];
       top3--;
       switch (r){
        case 1:
           pushElEv(pow(b,a)); 
           break;
        case 2:
           pushElEv(b*a); 
           break;
        case 3:
           pushElEv(b/a); 
           break;
        case 4:
           pushElEv(a+b); 
           break;
        case 5:
           pushElEv(b-a); 
           break;
       }
   }
   
    //evaluate
    void evaluate(){
        if(pexp[1]=="-")
            pushElEv(0);
        for(int i=0;i<length;i++){
            if(pexp[i]=="*" || pexp[i]=="^" || pexp[i]=="-" || pexp[i]=="+" || pexp[i]=="/" || pexp[i]=="!"|| pexp[i]=="|"|| pexp[i]=="&"){
                rank=order(pexp[i]);
                popEl(rank);
            }
            else{
                pushElEv(stod(pexp[i]));
            }
        }
    }

    //display
    void displayAns(){
        cout<<endl<<"Answer is : ";
        for(int i=0;i<=top3;i++)
            cout<<eval[i]<<"  ";
    }
};

int main(){
    int len=0;
    cout<<endl<<"Enter the size of expression including the operators : (<100)";
    cin>>len;
    itop a(len);
    a.getExpr();
    a.convertExp();
    a.display();
    a.evaluate();
    a.displayAns();
}