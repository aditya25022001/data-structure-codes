#include<iostream>
using namespace std;
class Stack{
    int stack[100], top, choice, len;

public:
    
    //contents
    int contents(){
        cout<<"Push element on to stack : 1"<<endl;
        cout<<"Pop element from stack   : 2"<<endl;
        cout<<"Display stack            : 3"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        return choice;
    }

    //create
    Stack(int size){
        top=-1;
        len=size;
    }

    //add
    void push(int item){
        if(top==len-1){
            cout<<endl<<"Stack Overflow";
        }
        else{
            top++;
            stack[top] = item;
        }
    }
    
    //delete
    void pop(){
        if(top == -1)
            cout<<endl<<"Stack is empty";
        else{
            cout<<endl<<"Deleting : "<<stack[top];
            top--;
        }
    }

    //displaying the stack
    void show(){
        cout<<endl<<"Displaying stack : ";
        for(int i=0;i<=top;i++)
            cout<<stack[i]<<" ";
    }
};
int main(){
    //provide the size of the stack you want with the constructor
    char ans ;
    int size, choice, element;
    cout<<"Do you want to create stack ? (y/n) :";
    cin>>ans;
    if(ans == 'y' || ans == 'Y'){
        cout<<endl<<"Entre the size of your stack : ";
        cin>>size;
    }
    Stack s(size); 
    while(ans=='y' || ans == 'Y'){
        cout<<"Menu for user : "<<endl;   
        choice = s.contents();
        switch (choice){
        case 1:
            cout<<endl<<"Enter element : ";
            cin>>element;
            s.push(element);
            cout<<endl<<"Do you want to continue : (y/n) : ";
            cin>>ans;
            break;
        case 2:
            s.pop();
            cout<<endl<<"Do you want to continue : (y/n) : ";
            cin>>ans;
            break;
        case 3:
            s.show();
            cout<<endl<<"Do you want to continue : (y/n) : ";
            cin>>ans;
            break;
        default:
            cout<<endl<<"Wrong choice entered !";
            break;
        }
    }
}