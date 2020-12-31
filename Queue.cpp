#include<iostream>
using namespace std;
int front = -1, rare = -1, choice, size;        

//contents
int contents(){
    cout<<endl;
    cout<<"Push element on to queue : 1"<<endl;
    cout<<"Pop element from queue   : 2"<<endl;
    cout<<"Display queue            : 3"<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    return choice;
}

//push
void push(int queue[], int item){
    if(rare == size-1)
        cout<<endl<<" Queue is full ! ";
    else{
        rare++;
        queue[rare] = item;
        if(front == -1)
            front=0;
    }
}

//pop
void pop(int queue[]){
    if(front == -1)
        cout<<endl<<"Queue is empty ! ";
    else{
        cout<<endl<<"Popping : "<<queue[front];
        front++;
        if(front > rare){
            front = -1;
            rare = -1;
        }
    }
}

//show
void show(int queue[]){
    if(front == -1)
        cout<<endl<<"Queue is empty !";
    else{
        cout<<endl<<"Displaying queue : ";
        for(int i=front;i<=rare;i++)
            cout<<queue[i]<<" ";
    }
}

int main(){
    char ans ;
    int element;
    cout<<"Do you want to create queue ? (y/n) :";
    cin>>ans;
    if(ans == 'y' || ans == 'Y'){
        cout<<endl<<"Entre the size of your queue : ";
        cin>>size;
    }
    int queue[size]; 
    while(ans=='y' || ans == 'Y'){
        cout<<endl<<"Menu for user";   
        choice = contents();
        switch (choice){
        case 1:
            cout<<endl<<"Enter element : ";
            cin>>element;
            push(queue, element);
            cout<<endl<<"Do you want to continue : (y/n) : ";
            cin>>ans;
            break;
        case 2:
            pop(queue);
            cout<<endl<<"Do you want to continue : (y/n) : ";
            cin>>ans;
            break;
        case 3:
            show(queue);
            cout<<endl<<"Do you want to continue : (y/n) : ";
            cin>>ans;
            break;
        default:
            cout<<endl<<"Wrong choice entered !";
            break;
        }
    }
}