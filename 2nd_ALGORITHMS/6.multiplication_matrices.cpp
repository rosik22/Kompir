#include <iostream>
using namespace std;

int main()
{
    int A[3][4], B[4][2], C[3][2] = {0};
    int n = 3, q = 2, m = 4;

    cout<<"Enter A: "<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
           cin>> A[i][j]; 
        }
    }

    cout<<"Enter B: "<<endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<2; j++){
           cin>> B[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<q; j++){
            for(int k=0; k<m; k++){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    cout<<endl<<"C:"<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}