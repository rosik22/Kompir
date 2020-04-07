#include <iostream>   
using namespace std; 

void heapify(int arr[], int n, int i) 
{ 
    int largest = i;
    int l = 3*i + 1; 
    int m = 3*i + 2;
    int r = 3*i + 3;
  
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
    
    if (m < n && arr[m] > arr[largest]) 
        largest = m;
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
   
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 

        heapify(arr, n, largest); 
    } 
} 

void heapSort(int arr[], int n) 
{ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    for (int i=n-1; i>0; i--) 
    { 
        swap(arr[0], arr[i]); 
  
        heapify(arr, i, 0); 
    } 
} 

void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 

int main() 
{ 
    int arr[] = {
        12, 11, 13, 5, 6, 
        7, 15, 3, 8, 14}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    
    heapSort(arr, n); 
  
    cout << "Sorted array is \n"; 
    printArray(arr, n); 
}
