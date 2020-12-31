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

//display
        void display1(int **perform, int r, int c, int non){
            display=new int*[r];
            for(int i=0;i<r;i++)
                display[i]=new int[c];
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    *(*(display+i)+j)=0;
            for(int i=0;i<non;i++)
                *(*(display+ *(*(perform+i)+0)) + *(*(perform+i)+1))=*(*(perform+i)+2);
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++)
                    cout<<" "<<*(*(display+i)+j)<<" ";
                cout<<endl;
            }
        }

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
            return format;
        }

//convert into 1 d array
        int **convtArray(int **perform, int r, int c){
            int x=r*c;
            int *oneD=new int[x];
            int *a=oneD;
            int *b=oneD;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    *oneD=*(*(perform+i)+j);
                    oneD+=1;
                }
            } 
            return colMaj(a,r,c);
        }

//saving in column major format
        int **colMaj(int *perform, int r, int c){
            int **covtd = new int*[r];
            for(int i=0;i<r;i++)
                covtd[i]=new int[c];
            for(int i=0;i<c;i++){
                for(int j=0;j<r;j++){
                    *(*(covtd+j)+i)=*perform;
                    perform+=1;
                }
            }
            return covtd;
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
    int row=A.retRows(), col=A.retCol();
    int non=A.countNonZero(input,row,col);
    int **first=A.formatMatrix(input,row,col,non);
    int **second1=A.convtArray(input,row,col);
    int non1=A.countNonZero(second1,row,col);
    int **second=A.formatMatrix(second1,row,col,non1);
    cout<<endl<<endl;
    A.display1(first,row,col,non);
    cout<<endl<<endl;
    A.display1(second,row,col,non1);
}
