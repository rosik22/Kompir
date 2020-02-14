#include <iostream>
using namespace std;

void qsort(int A[], int li, int di){
    int e = A[di];
    int j=li, k=di, buf;

    do{
        while(A[j]<e) j++;
        cout<<"j"<<j<<endl;
        while(A[k]>e) k--;
        cout<<"k"<<k<<endl;
        if(j<=k){
            buf = A[k];
            A[k] = A[j];
            A[j] = buf;
            j++; k--;
        }
    }
    while(j<=k);
    cout<<"k is"<<k<<endl;
    if(k>li) qsort(A,li,k);
    if(j<di) qsort(A,j,di);
}

int main(){
    int A[5] = {10,8,7,4,6};
    qsort(A,0,4);
    return 0;
}