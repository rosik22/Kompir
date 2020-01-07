#include <iostream>
using namespace std;

void moveTower(int n, char from, char to, char mid){
    if(n>1){
        moveTower(n-1,from,mid,to);
        cout<<"Местим диск от "<<from<<" на "<<to<<endl;
        moveTower(n-1,mid,to,from);
    }
    else
        cout<<"Местим диск от "<<from<<" на "<<to<<endl;
}

int main(){
    moveTower(4,'K','A','R');
    return 0;
}