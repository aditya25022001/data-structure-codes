#include<iostream>
using namespace std;
int polynomialA[30];
int sizeA;
int polynomialB[30];
int sizeB;
int polynomialC[60];
int c=0;
int x;
void inputPolynomial(){
    cout<<"Enter no of terms in polynomial A : ";
    cin>>x;
    sizeA=2*x;
    cout<<endl<<"Enter no of terms in polynomial B : ";
    cin>>x;
    sizeB=2*x;
    cout<<endl<<"Enter polynomials as degree then coefficient : ";
    cout<<endl<<"A : ";
    for(int i=0;i<sizeA;++i)
        cin>>polynomialA[i];
    cout<<endl<<"B : ";
    for(int i=0;i<sizeB;++i)
        cin>>polynomialB[i];
}
void addPolynomial(){   
    int a=0, b=0;
    while(a<sizeA && b<sizeB){
        if(polynomialA[a]==polynomialB[b]){
            polynomialC[c]=polynomialA[a];
            polynomialC[c+1]=polynomialA[a+1]+polynomialB[b+1];
            c+=2;
            a+=2;
            b+=2;
        }
        if(polynomialA[a]>polynomialB[b]){
            polynomialC[c]=polynomialA[a];
            polynomialC[c+1]=polynomialA[a+1];
            c+=2;
            a+=2;
        }
        if(polynomialA[a]<polynomialB[b]){
            polynomialC[c]=polynomialB[b];
            polynomialC[c+1]=polynomialB[b+1];
            c+=2;
            b+=2;
        }
    }
    while(a<sizeA){
        polynomialC[c]=polynomialA[a];
        polynomialC[c+1]=polynomialA[a+1];
        a+=2;
        c+=2;
    }
    while(b<sizeB){
        polynomialC[c]=polynomialB[b];
        polynomialC[c+1]=polynomialB[b+1];
        b+=2;
        c+=2;           
    }
}
void displayPolynomials(){
    cout<<"("<<polynomialC[1]<<"x^"<<polynomialC[0]<<")";
    for(int i=3;i<c+1;i+=2)
            cout<<"+("<<polynomialC[i]<<"x^"<<polynomialC[i-1]<<")";
}
int main(){
    inputPolynomial();
    addPolynomial();
    displayPolynomials();
    return 0;
}
