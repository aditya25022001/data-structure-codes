#include<iostream>
using namespace std;
class itop{
    char iexp[100];
    char pexp[100];
    char oper[100];
    int top, length, up, chec, top2;
public:
    
    itop(int len){
        top=-1;
        up=-1;
        top2=-1;
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
    int ranking(char item){
        if(item == '^')
            return 1;
        if(item == '*' || item == '/')
            return 2;
        if(item == '+' || item == '-')
            return 3;
    }

    //pushOp function
    int pushOp(int item, char ite){
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
    void pushEl(char item, int choice){
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
            if(iexp[i]!='*' && iexp[i]!='^' && iexp[i]!='-' && iexp[i]!='+' && iexp[i]!='/')
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
};

int main(){
    int len=0;
    cout<<endl<<"Enter the size of expression including the operators : (<100)";
    cin>>len;
    itop a(len);
    a.getExpr();
    a.convertExp();
    a.display();

}