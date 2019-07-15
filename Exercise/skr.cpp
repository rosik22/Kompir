#include <iostream>
using namespace std;

int gcd(unsigned a, unsigned b){
    if (a==0) return b;
    else gcd(b%a, a);
}

int fgcd(int a[], int b){
    int result = a[0];
    for(int i=1; i<b; i++){
        result = gcd(a[i], result);
    }
}

int main(){
    int a[] = {9,15,27};

    cout<< fgcd(a,3)<<endl;
}