#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long num;
    cin>>num;

    long long arr[num];
    for(long long i=0; i<num; i++){
        cin>>arr[i];
    }
    if (num == 1){
        cout<<1<<endl<<1<<endl;
    }
    else if(num > 1){
        long long k = 0;
        for(long long i=1; i<num; i++){
            if(arr[i]<arr[i-1]) k++;
        }
        k++;
        long long check = num/2;

        cout<<k<<endl;
        if(k < check) cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}