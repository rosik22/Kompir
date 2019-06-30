#include <iostream>
using namespace std;

class Group{
public:
    Group(int n);
    Group  operator +(const Group &other)const ;
};

Group::Group(int n){

}

int main(){

    return 0;
}