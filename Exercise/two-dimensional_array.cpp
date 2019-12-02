#include <iostream>
using namespace std;

int main(){
    int a = 5, b = 4;
    int c[a][b];

    int k = 10;
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            *(*(c+i)+j) = k;
            k++;
        }
    }

    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}