#include<iostream>
using namespace std;
class itp{
    char iexp[100], pexp[100], oper[100], paren[100];
    int chec, top, up, top2, count, len, top3;
public:
    
    //constructor
    itp(int length){
        top=-1;
        len=length;
        up=-1;
        top2=-1;
        count=0;
    }
    
    //get expression 
    void getExpr(){
        iexp[0]='(';
        for(int i=1;i<=len;i++){
            cin>>iexp[i];
            top3=i;
        }
        top3++;
        iexp[top3]=')';
    }
    
    //ranking
     int ranking(char item){
        if(item == '^' || item == '!')
            return 1;
        if(item == '*' || item == '/')
            return 2;
        if(item == '+' || item == '-')
            return 3;
        if(item == '<' || item == '>' || item == '=')
            return 4;
        if(item == '&')
            return 5;
        if(item == '|')
            return 6;
    }
    //push operator
    void pushOp(char item, int o, int value){
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
            while(oper[i]!='('){
                pushEl(oper[i],1);
                i--;
                up--;
            }
            up--;
        }
    }

    //push element
    void pushEl(char item, int choice){
        if(choice == 1){
            top++;
            pexp[top]=item;
        }
        else{
            if(item == '(')
                pushOp(item, 1, 6);
            if(item==')')
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
            if(iexp[i]!='*' && iexp[i]!='^' && iexp[i]!='-' && iexp[i]!='+' && iexp[i]!='/' && iexp[i]!='(' && iexp[i]!=')' && iexp[i]!='=' && iexp[i]!='>' && iexp[i]!='<' && iexp[i]!='!' && iexp[i]!='|' && iexp[i]!='&')
                pushEl(iexp[i], 1);
            else{
                pushEl(iexp[i], 2);
            }
        }
        for(int i=up;i>0;i--)
            pushEl(oper[i],1);
    }
 
    void display(){
        cout<<endl<<"Postfix Expression : ";
        for(int i=0;i<=top;i++){
            if(pexp[i]!='(' && pexp[i]!=')')
                cout<<pexp[i]<<" ";
        }
    }
};
int main(){
    int a;
    cout<<"size : ";
    cin>>a;
    itp d(a);
    d.getExpr();
    d.convertExp();
    d.display();
    return 0;
}