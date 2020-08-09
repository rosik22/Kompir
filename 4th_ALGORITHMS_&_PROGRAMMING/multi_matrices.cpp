#include <iostream>
using namespace std;

int main(){
    int n,k,m;
    cout<<"n: ";
    cin>>n;
    cout<<"k: ";
    cin>>k;
    cout<<"m: ";
    cin>>m;
    int temp;
    int A[n][k],B[k][m],C[n][m];
    cout<<"Enter A: "<<endl;
    for(int i=0; i<n; i++){
        cout<<"row "<<i<<": ";
        for(int j=0; j<k; j++){
            cin>>temp;
            A[i][j] = temp;
        }
    }
    cout<<"Enter B: "<<endl;
    for(int i=0; i<k; i++){
        cout<<"row "<<i<<": ";
        for(int j=0; j<m; j++){
            cin>>temp;
            B[i][j] = temp;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            C[i][j] = 0;
            for(int p=0; p<k; p++){
                C[i][j] += A[i][p]*B[p][j]; 
            }
        }
    }

    cout<<"C: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}