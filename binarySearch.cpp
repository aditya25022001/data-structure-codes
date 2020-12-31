#include<iostream>
using namespace std;

//   1==>increasing order     2==>decreasing order

//searching the desired element

int binarySearch(int A[], int size, int item, int direction){
    int mid, lower, upper;
    if(direction==1){
        lower=0, upper=size;
        while(lower<=upper){
            mid=(lower+upper)/2;
            if(A[mid]==item){
                return mid;
            }
            else{
                if(A[mid]<item)
                    lower=mid+1;
                if(A[mid]>item)
                    upper=mid-1;
            }
        }
        return -1;
    }
    if(direction==2){
        lower=size, upper=0;
        while(lower>=upper){
            mid=(lower+upper)/2;
            if(A[mid]==item){
                return mid;
            }
            else{
                if(A[mid]<item)
                    lower=mid-1;
                if(A[mid]>item)
                    upper=mid+1;
            }
        }
        return -1;
    }
}

//sorting the array according to the user

int *sortArray(int A[], int size, int dir){
    int temp=0;
    if(dir==1){
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                if(A[i]>A[j]){
                    temp=A[j];
                    A[j]=A[i];
                    A[i]=temp;
                }
            }
        }
    }
    if(dir==2){
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                if(A[i]<A[j]){
                    temp=A[j];
                    A[j]=A[i];
                    A[i]=temp;
                }
            }
        }
    }
    return A;
}

int main(){
    int size=0, item=0, dir=0;
    cout<<endl<<"Enter size of the array : ";
    cin>>size;
    int array[size];
    cout<<endl<<"Enter the elements : ";
    for(int i=0;i<size;i++)
        cin>>array[i];
    cout<<endl<<"sort increasing (1) or decreasing (2) ?";
    cin>>dir;
    cout<<endl<<"Enter the element to search : ";
    cin>>item;
    int ans=binarySearch(sortArray(array, size, dir), size, item, dir);
    if(ans==-1)
        cout<<endl<<"Oops!, the element is not present in the given array.";
    else{
        cout<<endl<<"The element is present at "<<ans<<" index i.e. "<<ans+1<<" position.";
    }
}