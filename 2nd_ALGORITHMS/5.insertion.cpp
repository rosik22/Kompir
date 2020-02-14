#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)  
{  
    int Buf, j;  
    for (int i = 1; i < n; i++) 
    {  
        Buf = arr[i]; 
        j = i - 1;  

        while (j >= 0 && arr[j] > Buf) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;
        }  
        arr[j + 1] = Buf;  
    }  
}  

int main(){
    int arr[] = { 12, 11, 13, 5, 6 };  
    int n = 5;  
  
    insertionSort(arr, n);  
    
    for (int i = 0; i < n; i++){
        cout << arr[i] << " "; 
    }
    cout<<endl;
  
    return 0;  
}  