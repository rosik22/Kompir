#include <iostream>
#include <vector>
#include <time.h>
#include <sys/types.h>
using namespace std;

int binarySearch(int a[], int Buf, int low, int high) 
{ 
    if (high <= low) 
        return (Buf > a[low])?  (low + 1): low; 
  
    int mid = (low + high)/2; 
  
    if(Buf == a[mid]) 
        return mid+1; 
  
    if(Buf > a[mid]) 
        return binarySearch(a, Buf, mid+1, high); 
    return binarySearch(a, Buf, low, mid-1); 
} 

void insertionSort(int arr[], int n)  
{  
    int Buf, j, check;  
    for (int i = 1; i < n; i++) 
    {  
        Buf = arr[i]; 
        j = i - 1;  

        check = binarySearch(arr, Buf, 0, j); 

        while (j >= check) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = Buf;
    }  
}  

int main(){
    time_t  t0, t1;

    t0 = time(NULL);
    clock_t begin = clock();

    int arr[] = { 12, 11, 13, 5, 6 }; 
    int n = 5;  
  
    insertionSort(arr, n);  
    clock_t end = clock();

    t1 = time(NULL);

    double answer = double (end - begin)/CLOCKS_PER_SEC;

    cout << "Elapsed wall clock time: " << ((long) (t1 - t0)) << endl;
    cout << "Elapsed wall clock time :" << answer << endl;
    return 0;  
}  