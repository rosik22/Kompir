#include <iostream>
using namespace std;

int sum(int * arr, size_t sz){
  	return (sz>0)? arr[sz-1] + sum(arr, sz-1):0;
}

int non_zero(int * arr, size_t sz){
  	if(sz>0) return (arr[sz-1]) ? 1+non_zero(arr, sz-1) : non_zero(arr, sz-1);
  	return 0;
}

void fill(int* arr, size_t sz){
    if(sz>1) fill(arr,sz-1);
    cout<<"enter arr["<<sz-1<<"]: ";
    cin>>arr[sz-1];
}

int main(){
    int arr[5] = {1,0,3,4,7};
    
    int sum_1 = sum(arr,5);
    cout<<sum_1<<endl;

    int non_z = non_zero(arr, 5);
    cout<<non_z<<endl;

    fill(arr, 5);

    for(int i=0; i<5; i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}
