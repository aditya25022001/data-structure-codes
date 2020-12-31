#include<iostream>
using namespace std;
class multipleStack{
    int top1, top2, top3, len1, len2, len3, choice;
    int megaStack[300];
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

    //constructor for two stack
    void initialize(int leng1, int leng2){
        top1 = -1;
        len1 = leng1;
        len2 = leng2;
        top2 = top1 + leng1;
    }

    //constructor for three stack
    void initialize(int leng1, int leng2, int leng3){
        top1 = -1;
        len1 = leng1;
        len2 = leng2;
        len3 = leng3;
        top2 = top1 + leng1;
        top3 = top2 + leng2;
    }

    //push
    void push(int item, int noOfStacks, int stackNo){
        if(noOfStacks == 2 && stackNo>2 || noOfStacks == 3 && stackNo>3){
            cout<<endl<<"Enter valid inputs !";
            exit(0);
        }
        if(noOfStacks == 2){
            switch(stackNo){
                case 1:
                    if(top1 == len1-1)
                        cout<<endl<<"Stack full !";
                    else{
                        top1++;
                        megaStack[top1] = item;
                    }
                    break;
                case 2:
                    if(top2 == len1 + len2 -1)
                        cout<<endl<<"Stack full !";
                    else{
                        top2++;
                        megaStack[top2] = item;
                    }
                    break;
            }
        }
        if(noOfStacks == 3){
            switch(stackNo){
                case 1:
                    if(top1 == len1-1)
                        cout<<endl<<"Stack full !";
                    else{
                        top1++;
                        megaStack[top1] = item;
                    }
                    break;
                case 2:
                    if(top2 == len1 + len2 -1)
                        cout<<endl<<"Stack full !";
                    else{
                        top2++;
                        megaStack[top2] = item;
                    }
                    break;
                case 3:
                    if(top3 == len1 + len2 + len3-1)
                        cout<<endl<<"Stack full !";
                    else{
                        top3++;
                        megaStack[top3] = item;
                    }
                    break;
            }
        }
    }

    //pop
    void pop(int noOfStacks, int stackNo){
        if(noOfStacks == 2 && stackNo>2 || noOfStacks == 3 && stackNo>3){
            cout<<endl<<"Enter valid inputs!";
            exit(0);
        }
        if(noOfStacks == 2){
            switch(stackNo){
                case 1:
                    if(top1 == -1)
                        cout<<endl<<"Stack empty !";
                    else{
                        cout<<endl<<"Popping or Deleting : "<<megaStack[top1];
                        top1--;
                    }
                    break;
                case 2:
                    if(top2 == len1-1)
                        cout<<endl<<"Stack empty !";
                    else{
                        cout<<endl<<"Popping or Deleting : "<<megaStack[top2];
                        top2--;
                    }
                    break;
            }
        }
        if(noOfStacks == 3){
            switch(stackNo){
                case 1:
                    if(top1 == -1)
                        cout<<endl<<"Stack empty !";
                    else{
                        cout<<endl<<"Popping or Deleting : "<<megaStack[top1];
                        top1--;
                    }
                    break;
                case 2:
                    if(top2 == len1-1)
                        cout<<endl<<"Stack empty !";
                    else{
                        cout<<endl<<"Popping or Deleting : "<<megaStack[top2];
                        top2--;
                    }
                    break;
                case 3:
                    if(top3 == len1 + len2 -1)
                        cout<<endl<<"Stack empty !";
                    else{
                        cout<<endl<<"Popping or Deleting : "<<megaStack[top3];
                        top3--;
                    }
                    break;
            }
        }
    }

    //display
    void display(int noOfStacks, int stackNo){
        if(noOfStacks == 2 && stackNo>2 || noOfStacks == 3 && stackNo>3){
            cout<<endl<<"Enter valid inputs !";
            exit(0);
        }
        if(noOfStacks == 2){
            switch(stackNo){
                case 1:
                    if(top1 == -1)
                        cout<<endl<<"Stack empty !";
                    else{
                        cout<<endl<<"Displaying stack "<<stackNo<<" : ";
                        for(int i=0;i<=top1;i++)
                            cout<<megaStack[i]<<" ";
                    }
                    break;
                case 2:
                    if(top2 == len1 - 1)
                        cout<<endl<<"Stack empty !";
                    else{
                        cout<<endl<<"Displaying stack "<<stackNo<<" : ";
                        for(int i=len1;i<=top2;i++)
                            cout<<megaStack[i]<<" ";
                    }
                    break;
            }
        }
        if(noOfStacks == 3){
            switch(stackNo){
                case 1:
                    if(top1 == -1)
                        cout<<endl<<"Stack empty !";
                    else{
                        cout<<endl<<"Displaying stack "<<stackNo<<" : ";
                        for(int i=0;i<=top1;i++)
                            cout<<megaStack[i]<<" ";
                    }
                    break;
                case 2:
                    if(top2 == len1 - 1)
                        cout<<endl<<"Stack empty !";
                    else{
                        cout<<endl<<"Displaying stack "<<stackNo<<" : ";
                        for(int i=len1;i<=top2;i++)
                            cout<<megaStack[i]<<" ";
                    }
                    break;
                case 3:
                    if(top3 == len1 + len2 -1)
                        cout<<endl<<"Stack empty !";
                    else{
                        cout<<endl<<"Displaying stack "<<stackNo<<" : ";
                        for(int i=len1+len2;i<=top3;i++)
                            cout<<megaStack[i]<<" ";
                    }
            }
        }
    }
};
int main(){
    char ans ;
    int size1, choice, element, noOfStacks, size2, size3, stackNumber;
    cout<<"Do you want to create multiple stacks ? (y/n) :";
    cin>>ans;
    multipleStack s;
    if(ans == 'y' || ans == 'Y'){
        cout<<endl<<"Entre number of stacks (either 2 or 3) : ";
        cin>>noOfStacks;
        if(noOfStacks==2){
            cout<<endl<<"Enter the size of 1st stack (<100) : ";
            cin>>size1;
            cout<<endl<<"Enter the size of 2nd stack (<100) : ";
            cin>>size2;
            s.initialize(size1,size2);
        }
        else{
            if(noOfStacks == 3){
            cout<<endl<<"Enter the size of 1st stack (<100) : ";
            cin>>size1;
            cout<<endl<<"Enter the size of 2nd stack (<100) : ";
            cin>>size2;
            cout<<endl<<"Enter the size of 3rd stack (<100) : ";
            cin>>size3;
            s.initialize(size1, size2, size3);
            }
            else{
                cout<<endl<<"Wrong no of stacks!";
                exit(0);
            }
        }
    }
    while(ans=='y' || ans == 'Y'){
        cout<<"Menu for user : "<<endl;   
        choice = s.contents();
        switch (choice){
        case 1:
            cout<<endl<<"Enter stack number : ";
            cin>>stackNumber;
            cout<<endl<<"Enter element : ";
            cin>>element;
            s.push(element, noOfStacks, stackNumber);
            cout<<endl<<"Do you want to continue : (y/n) : ";
            cin>>ans;
            break;
        case 2:
            cout<<endl<<"Enter stack number to pop element from :";
            cin>>stackNumber;
            s.pop(noOfStacks, stackNumber);
            cout<<endl<<"Do you want to continue : (y/n) : ";
            cin>>ans;
            break;
        case 3:
            cout<<endl<<"Enter the stack number to display :";
            cin>>stackNumber;
            s.display(noOfStacks, stackNumber);
            cout<<endl<<"Do you want to continue : (y/n) : ";
            cin>>ans;
            break;
        default:
            cout<<endl<<"Wrong choice entered !"<<endl;
            break;
        }
    } 
}
