#include<iostream>
using namespace std;
class magicSquare{
    int **a, **b, **u;
public:   
    int **zeroMatrix(int size){
        a = new int *[size];
        b=a;
        for(int i=0;i<size;i++)
            a[i]=new int[size];
        for(int i=0;i<size;i++)
            for(int j=0;j<size;j++)
                *(*(a+i)+j)=0;
        return b;
    }
    int **magicSquareMatrix(int **d, int size){
        u=d;
        int i=0, j=(size-1)/2, key=2, k=0, l=(size-1)/2, c=0;
        *(*(d+i)+j)=1;
        i=size-1, j=(size-1)/2-1;
        while(key<=(size*size)){
            k-=1, l-=1;
            if(k<0){
                i=k;
                k=size-1;
                c++;
            }
            if(l<0){
                j=l;
                l=size-1;
                c++;
            }
            if(*(*(d+k)+l)==0){
                *(*(d+k)+l)=key;
            }
            else{
                if(c==2){
                    k=i;
                    l=j;
                }
                k+=2;
                l+=1;
                *(*(d+k)+l)=key;
            }
            c=0;
            key+=1;
        }
        return u;
    }
    void displayMatrix(int **d, int size){
        int sum=0;
        for(int i=0;i<size;i++)
            sum+=*(*(d+0)+i);
        cout<<endl<<"Magic square with "<<size<<" rows and "<<size<<" coloumns :"<<endl<<endl;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++)
            if(*(*(d+i)+j)>=10)
                cout<<*(*(d+i)+j)<<"   ";
            else{
                cout<<"0"<<*(*(d+i)+j)<<"   ";
            }
            cout<<endl<<endl;
        }
        cout<<endl<<"Unique sum of the magic square is : "<<sum;
    }
    void destroy(){
        delete a, b, u;
    }
};

int main(){
    int size;
    cout<<endl<<"Enter the size of n x n matrix : ";
    cin>>size;
    if(size%2==0){
        cout<<endl<<"Enter odd number!!";
        cin>>size;
    }
    magicSquare A;
    int **c=A.zeroMatrix(size);
    int **f=A.magicSquareMatrix(c, size);
    A.displayMatrix(f, size);
    A.destroy();
    return 0;
}