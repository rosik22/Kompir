#include <iostream>
using namespace std;

int main(){
    int num, pow;
    cout<<"Enter number and power: ";
    cin>>num>>pow;

    int sum, n = 1, q = num;

    while(n < pow){
        int a = 0;
        sum = 0;
        while(a < q){
            sum = sum + num;
            a++;
        }
        q = sum;
        n++;
    }

    cout<<sum;
    return 0;
}
