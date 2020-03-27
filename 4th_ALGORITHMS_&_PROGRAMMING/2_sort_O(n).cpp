#include <iostream>
using namespace std;

int main(){
    int arr[10] = {30,15,20,5,45,50,35,10,25,40};
    int min = arr[0],max = arr[0];
    for(int i=1; i<10; i++){
        if(arr[i]>max){
            max = arr[i];
        }
        else if(arr[i]<min){
            min = arr[i];
        }
    }
    int d = (max-min)/9;
    for(int i=0; i<10; i++){
        arr[i] = min+d*i;
    }
    for(int i=0; i<10; i++) cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}