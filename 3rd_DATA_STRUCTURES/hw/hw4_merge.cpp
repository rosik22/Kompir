#include <iostream>
//#include <algorithm>
using namespace std;

void merge(int a[], int from, int mid, int to){
    int i,j,k, buf[40];
    i = from;
    k = from;
    j = mid+1;

    while (i <= mid && j <= to){
        if(a[i] < a[j]){
            buf[k] = a[i];
            k++;
            i++; 
        }
        else{
            buf[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid){
        buf[k] = a[i];
        k++;
        i++;
    }
    while (j<= to){
        buf[k] = a[j];
        k++;
        j++;
    }

    for(i = from; i < k; i++){
        a[i] = buf[i];
    }
}

void merge_sort(int a[], int from, int to){
    if (from == to) return;
    int mid = (from+to)/2;
    merge_sort(a, from, mid);
    merge_sort(a, mid+1, to);
    cout<<"сливам масив от "<<from<<" до "<<mid<<" и масив от "<<mid+1<<" до "<<to<<endl;
    merge(a,from,mid,to);
}

int main(){
    int arr[10] = {1,5,8,2,3,9,4,5,7,2};
    merge_sort(arr, 0, 9);
    
    cout<< "резултат: ";
    for(int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}