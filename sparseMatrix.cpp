
//sparse matrix
//a matrix which has population of 70 to 80% zeroes
//program finds an easy but not efficient way to store the same

#include<iostream>
using namespace std;

class sparseMatrix{
    int row, coloumn, x;
    int **display;
    int **format;
    int **transposed;
    int **b;
    int **a;
    public:

//display user input matrix

        void dispNormalMatrix(int **perform, int r, int c){
            cout<<endl<<"The matrix you entered: "<<endl;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    cout<<" "<<*(*(perform+i)+j)<<" ";
                }
                cout<<endl;
            }
        }

//displaying the transposed matrix

        void dispTransMatrix(int **perform, int c, int r, int cou){
            cout<<endl<<"Displaying transposed matrix: "<<endl;
            display=new int*[c];
            for(int i=0;i<c;i++){
                display[i]=new int[r];
            }
            for(int i=0;i<c;i++)
                for(int j=0;j<r;j++)
                    *(*(display+i)+j)=0;
            for(int i=0;i<cou;i++)
                *(*(display+ *(*(perform+i)+0)) + *(*(perform+i)+1))=*(*(perform+i)+2);
            for(int i=0;i<c;i++){
                for(int j=0;j<r;j++)
                    cout<<" "<<*(*(display+i)+j)<<" ";
                cout<<endl;
            }
        }

//formatting the matrix to easy way storage

        int **formatMatrix(int **perform, int r, int c, int nonZero){
            int ro=0;
            format=new int*[nonZero];
            for(int i=0;i<nonZero;i++){
                format[i]=new int[3];
            }
            x=nonZero;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(*(*(perform+i)+j)!=0){
                        *(*(format+ro)+0)=i;
                        *(*(format+ro)+1)=j;
                        *(*(format+ro)+2)=*(*(perform+i)+j);
                        ro+=1;
                    }
                }
            }
            dispNormalMatrix(format,nonZero,3);
            return format;
        }

//transposing the matrix using formatted matrix

        int **transposeMatrix(int **perform, int r, int c){
            transposed=new int*[r];
            for (int i=0;i<r;i++){
                transposed[i]=new int[3];
            }
            int q=0;
            for(int i=0;i<c;i++){
                for(int p=0;p<r;p++){
                    if(*(*(perform+p)+1)==i){
                        *(*(transposed+q)+0)=i;
                        *(*(transposed+q)+1)=*(*(perform+p)+0);
                        *(*(transposed+q)+2)=*(*(perform+p)+2);
                        q+=1;
                    }
                }
            }
            return transposed;
        }

//counting the non zero elements

        int countNonZero(int **perform, int r, int c){
            int count=0;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(*(*(perform+i)+j)!=0)
                        count++;
                }
            }
            return count;
        }

//returning the number of rows

        int retRows(){
            return row;
        }

//returning the number of coloumns

        int retCol(){
            return coloumn;
        }

//taking the input from the user

        int **inputMatrix(){
            cout<<"Enter size of 2d array: "<<endl<<"Row: ";
            cin>>row;
            cout<<"Coloumn: ";
            cin>>coloumn;
            a=new int*[row];
            b=a;
            for(int i=0;i<row;i++){
                a[i]=new int[coloumn];
            }
            cout<<"Enter the elements: "<<endl;
            for(int i=0;i<row;i++){
                for(int j=0;j<coloumn;j++){
                    cin>>*(*(a+i)+j);
                }
            }
            return b;
        }

//destroying the pointers

        void destroy(){
            delete format, transposed, a, b, display; 
        }
};


int main(){
    sparseMatrix A;
    int **input=A.inputMatrix();
    int count=A.countNonZero(input,A.retRows(),A.retCol()), row=A.retRows(), col=A.retCol();
    A.dispNormalMatrix(input,A.retRows(),A.retCol());
    A.dispTransMatrix(A.transposeMatrix(A.formatMatrix(input,row,col,count),count,col),col,row,count);
    A.destroy();
}
