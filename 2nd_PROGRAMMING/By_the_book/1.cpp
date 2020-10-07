#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int * print(int a[]){
    a[0] = 5;
    return a;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    int *k = print(a);
    cout<<k[1];
    return 0;
}