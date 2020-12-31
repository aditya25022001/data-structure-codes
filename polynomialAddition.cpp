//Algorithm for simplr two polynomial addition
//using class 
//using pointers

#include<iostream>
using namespace std;

class polynomial{
    
    int size;
    int finalSize;
    int *a,*b, *p, *q, *r, *l1, *l2, *u;
    
    public:
        
//taking user input of the polynomial
        
        int *inputPolynomial(){
            cout<<endl<<"Enter number of terms in polynomial: ";
            cin>>size;
            int s1=2*size+1;
            a=b=new int[s1];
            *a=size;
            a+=1;
            cout<<endl<<"Enter elements of polynomial as degree then coefficient: ";
            for(int i=1;i<s1;i++){
                cin>>*a;
                a+=1;
            }
            return b;
        }

//adding polynomials

        int *addPolynomial(int *C, int *D){
            p=&C[1], q=&D[1], l1=&C[2*(*C)], l2=&D[2*(*D)];
            int c=0;
            r=new int[*C+*D-1];
            u=r;
            r+=1;
            while(p<l1 && q<l2){
                if(*p==*q){
                    *(r+1)=*(p+1) + (*(q+1));
                    if(*(r+1)!=0){
                        *r=*p;
                        r+=2;
                    }
                    p+=2,q+=2;
                    c++;
          
                      
                }
                if(*p<*q){
                    *(r+1)=*(q+1);
                    *r=*q;
                    r+=2,q+=2;
                    c++;

                }
                if(*p>*q){
                    *(r+1)=*(p+1);
                    *r=*p;
                    r+=2,p+=2;
                    c++;

                }
            }
            while(p<=l1){
                *(r+1)=*(p+1);
                *r=*p;
                r+=2,p+=2;
                c++;
            }
            while(q<=l2){
                *(r+1)=*(q+1);
                *r=*q;
                r+=2,q+=2;
                c++;
            }
            *u=c;
            return u;
        }

//displaying the polynomials added and input ones.

        void displayPolynomial(int *S, int choice){
            int x=*S;
            if(choice==1){
                cout<<endl<<"Number of terms in polynomial A : "<<*S<<endl;
                cout<<endl<<"Displaying polynomial A : ";
                S+=1;
                for(int j=1;j<=x;j++){
                    if(*S==1){
                        if(*(S+3)<0){
                            cout<<*(S+1)<<"x ";
                        }
                        else{
                            cout<<*(S+1)<<"x + ";
                        }
                    }
                    if(*S==0)
                        cout<<*(S+1);
                    if(*S!=0 && *S!=1){
                        if(*(S+3)<0){
                            cout<<*(S+1)<<"x^"<<*S<<" ";
                        }
                        else{
                            cout<<*(S+1)<<"x^"<<*S<<" + ";
                        }
                    }
                    S+=2;
                }
                cout<<endl;
            }
            if(choice==2){
                cout<<endl<<"Number of terms in polynomial B : "<<*S<<endl;
                cout<<endl<<"Displaying polynomial B : ";
                S+=1;
                for(int j=1;j<=x;j++){
                    if(*S==1){
                        if(*(S+3)<0){
                            cout<<*(S+1)<<"x ";
                        }
                        else{
                            cout<<*(S+1)<<"x + ";
                        }
                    }
                    if(*S==0)
                        cout<<*(S+1);
                    if(*S!=0 && *S!=1){
                        if(*(S+3)<0){
                            cout<<*(S+1)<<"x^"<<*S<<" ";
                        }
                        else{
                            cout<<*(S+1)<<"x^"<<*S<<" + ";
                        }
                    }
                    S+=2;
                }
                cout<<endl;
            }
            if(choice==3){
                cout<<endl<<"Number of terms in resultant polynomial : "<<*S<<endl;
                cout<<endl<<"Displaying resultant polynomial : ";
                S+=1;
                for(int j=1;j<=x;j++){
                    if(*S==1){
                        if(*(S+3)<0){
                            cout<<*(S+1)<<"x ";
                        }
                        else{
                            cout<<*(S+1)<<"x + ";
                        }
                    }
                    if(*S==0)
                        cout<<*(S+1);
                    if(*S!=0 && *S!=1){
                        if(*(S+3)<0){
                            cout<<*(S+1)<<"x^"<<*S<<" ";
                        }
                        else{
                            cout<<*(S+1)<<"x^"<<*S<<" + ";
                        }
                    }
                    S+=2;
                }
                cout<<endl;
            }
        }

//destroying the pointers

        void destroy(){
            delete a, b, p, q, l1, l2, u, r;
        }
};
int main(){
    polynomial A;
    polynomial B;
    int *a = A.inputPolynomial();
    int *b = B.inputPolynomial();
    A.displayPolynomial(a, 1);
    B.displayPolynomial(b, 2);
    int *c = A.addPolynomial(a, b);
    A.displayPolynomial(c, 3);
    A.destroy();
    B.destroy();
    return 0;
}