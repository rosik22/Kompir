#include <iostream>
using namespace std;

int binary_search(int arr[], int beg, int end, int k){
    int mid = (beg+end)/2;
    if(k==arr[mid]){
        cout<<"found at index: "<<mid<<endl;
        return 0;
    }
    if(k<arr[mid])
        binary_search(arr,beg,mid-1,k);
    else if(k>arr[mid])
        binary_search(arr,mid+1,end,k);
    return 0;
}

int main(){
    int k = 13;
    int size = 10;
    int arr[size] = {1,1,3,5,6,7,9,10,13,15};
    binary_search(arr,0,size-1,k);
    return 0;
}