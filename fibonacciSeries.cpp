#include<iostream>
using namespace std;
int main(){
    int c=0;
    int size=0;
    int init3=0;
    cout<<"enter size: ";
    cin>>size;
    int init1=0, init2=1;
    cout<<init1<<" "<<init2<<" ";
    for(int i=2;i<size;i++){
        c++;
        init3=init1+init2;
        cout<<init3<<" ";
        init1=init2;
        init2=init3;
    }
    c++;
    cout<<endl<<c;
}