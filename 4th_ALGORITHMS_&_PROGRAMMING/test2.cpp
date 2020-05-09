#include <iostream>
using namespace std;

//method that sorts an array using selection sort,
//by sorting the first half in ascending order
// and the second half in descending order;
void halfSelectionSort(int A[], int n){
    int min, max, flag;
	for (int i = 0; i < n-1; i++){
		min = A[i];
        max = A[i];
		flag = i;
		if(i<n/2){
            for (int j = i + 1; j < n; j++){   
			    if (A[j]<min){
				    min = A[j];
				    flag = j;
		        }
		    }
		    A[flag] = A[i];
		    A[i] = min;
        }
        else{
            for(int k = i + 1; k < n; k++){
                if (A[k]>max){
                    max = A[k];
                    flag = k;
                }
            }
            A[flag] = A[i];
            A[i] = max;
        }
	}
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    halfSelectionSort(A,n);
    return 0;
}