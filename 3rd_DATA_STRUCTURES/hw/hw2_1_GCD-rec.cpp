#include <iostream>
using namespace std;

int answer;

void GCD (int a, int b){
    if(a%b > 0){
        cout<<"A: "<<a<<"; B: "<<b<<endl;
        GCD(b, a%b);
        cout<<"A: "<<a<<"; B: "<<b<<endl;

    }
    else
        answer = b;
}

int main(){
    GCD(84, 49);
    cout<<"The GCD is: "<<answer<<endl;
    return 0;
}