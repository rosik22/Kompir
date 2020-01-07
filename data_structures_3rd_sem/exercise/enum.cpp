#include <iostream>
using namespace std;

struct type{
    enum d{right = '1.6', left = 'l'};
}X;

int main(){
    type k;
    type *m = &k;

    char a = type::d::right;
    char b = k.left;
    char s = m->left;
    cout<<a<<" "<<b<<" "<<s;

}
