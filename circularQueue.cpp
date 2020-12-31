#include<iostream>
using namespace std;
int front = -1, rare = -1, choice, size;        

//contents
int contents(){
    cout<<endl;
    cout<<"Push element on to circular queue : 1"<<endl;
    cout<<"Pop element from circular queue   : 2"<<endl;
    cout<<"Display circular queue            : 3"<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    return choice;
}

//push
void push(int circularQueue[], int item){
    if(front == 0 && rare == size-1 || rare + 1 == front)
        cout<<endl<<" Circular queue is full ! ";
    else{
        if(rare == size-1)
            rare=-1;
        rare++;
        circularQueue[rare] = item;
        if(front == -1)
            front=0;
    }
}

//pop
void pop(int circularQueue[]){
    if(front==-1)
        cout<<endl<<"Circular queue is empty ! ";
    else{
        if(front == rare){
            cout<<endl<<"Popping : "<<circularQueue[front];
            front = -1;
            rare = -1;    
        }
        else{
            cout<<endl<<"Popping : "<<circularQueue[front];
            if(front == size-1){
                front = 0;
            }
            else{
                front++;
            }
        }
    }
}

//show
void show(int circularQueue[]){
    if(front == -1)
        cout<<endl<<"Circular queue is empty !";
    else{
        cout<<endl<<"Displaying Circular queue : ";
        if(rare>=front)
            for(int i=front;i<=rare;i++)
                cout<<circularQueue[i]<<" ";
        else{
            for(int i=front;i<size;i++)
                cout<<circularQueue[i]<<" ";
            for(int i=0;i<=rare;i++)
                cout<<circularQueue[i]<<" ";
        }
    }
}

int main(){
    char ans ;
    int element;
    cout<<"Do you want to create Circular queue ? (y/n) :";
    cin>>ans;
    if(ans == 'y' || ans == 'Y'){
        cout<<endl<<"Entre the size of your Circular queue : ";
        cin>>size;
    }
    int circularQueue[size]; 
    while(ans=='y' || ans == 'Y'){
        cout<<endl<<"Menu for user";   
        choice = contents();
        switch (choice){
        case 1:
            cout<<endl<<"Enter element : ";
            cin>>element;
            push(circularQueue, element);
            cout<<endl<<"Do you want to continue : (y/n) : ";
            cin>>ans;
            break;
        case 2:
            pop(circularQueue);
            cout<<endl<<"Do you want to continue : (y/n) : ";
            cin>>ans;
            break;
        case 3:
            show(circularQueue);
            cout<<endl<<"Do you want to continue : (y/n) : ";
            cin>>ans;
            break;
        default:
            cout<<endl<<"Wrong choice entered !";
            break;
        }
    }
}