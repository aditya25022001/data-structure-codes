#include<iostream>
#include<math.h>
using namespace std;
class itp{
    string iexp[100], pexp[100], oper[100];
    int chec, top, up, top2, count, len, top3, top4, rank;
    double eval[100], a, b, c;
public:
    
    //constructor
    itp(int length){
        top=-1;
        len=length;
        up=-1;
        top2=-1;
        top4 = -1;
        count=0;
    }
    
    //get expression 
    void getExpr(){
        iexp[0]="(";
        for(int i=1;i<=len;i++){
            cin>>iexp[i];
            top3=i;
        }
        top3++;
        iexp[top3]=")";
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
        if(item == "(")
            return 7;
    }
    
    //push operator
    void pushOp(string item, int o, int value){
        if(up==-1 || o==1){
            up++;
            oper[up]=item;
        }
        else{
            for(int i=up;i>=0;i--){
                if(ranking(oper[i])<=value){
                    pushEl(oper[i], 1);
                    up--;
                }
                if(ranking(oper[i])>=value || up==-1){
                    up++;
                    oper[up]=item;
                    break;
                }
            }
        }
        if(o==2){
            int i =up;
            while(oper[i]!="("){
                pushEl(oper[i],1);
                i--;
                up--;
            }
            up--;
        }
    }

    //push element
    void pushEl(string item, int choice){
        if(choice == 1){
            top++;
            pexp[top]=item;
        }
        else{
            if(item == "(")
                pushOp(item, 1, 6);
            if(item==")")
                pushOp(item, 2, 6);
            else{
                chec=ranking(item);
                pushOp(item, 0 ,chec);
            }

        }
    }
    
    //convert expression
    void convertExp(){
        for(int i=0;i<len+2;i++){
            if(iexp[i]!="*" && iexp[i]!="^" && iexp[i]!="-" && iexp[i]!="+" && iexp[i]!="/" && iexp[i]!="(" && iexp[i]!=")" && iexp[i]!="=" && iexp[i]!=">" && iexp[i]!="<" && iexp[i]!="!" && iexp[i]!="|" && iexp[i]!="&")
                pushEl(iexp[i], 1);
            else{
                pushEl(iexp[i], 2);
            }
        }
        for(int i=up;i>0;i--)
            pushEl(oper[i],1);
    }
    
    //display expression
    void display(){
        cout<<endl<<"Infix Expression : ";
        for(int i=0;i<=top3;i++){
            cout<<iexp[i]<<" ";
        }
        cout<<endl<<"Postfix Expression : ";
        for(int i=0;i<=top;i++){
            if(pexp[i]!="(" && pexp[i]!=")")
                cout<<pexp[i]<<" ";
        }
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
       top4++;
       eval[top4]=item;
    }

    //pop
    void popEl(int r){
       a=eval[top4];
       top4--;
       b=eval[top4];
       top4--;
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
        for(int i=0;i<len+2;i++){
            if(pexp[i]=="(" || pexp[i]==")")
                continue;
            else{
                if(pexp[i]=="*" || pexp[i]=="^" || pexp[i]=="-" || pexp[i]=="+" || pexp[i]=="/" || pexp[i]=="!"|| pexp[i]=="|"|| pexp[i]=="&"){
                    rank=order(pexp[i]);
                    popEl(rank);
                }
                else{
                    pushElEv(stod(pexp[i]));
                }
            }
        }
    }

    //display
    void displayAns(){
        cout<<endl<<"Answer is : ";
        for(int i=0;i<=top4;i++)
            cout<<eval[i]<<"  ";
    }
};
int main(){
    int a;
    cout<<"Enter the size of expression with operators and parenthesis (<100): ";
    cin>>a;
    itp d(a);
    d.getExpr();
    d.convertExp();
    d.display();
    d.evaluate();
    d.displayAns();
    return 0;
}