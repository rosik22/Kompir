#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
public:
    Triangle(int sideA, int sideB, int sideC);
    Triangle();
    int perimeter() {return a+b+c;}
    int area(int p) {return sqrt(p*(p-a)*(p-b)*(p-c));}
    int addToSmall();
    void extract() {a-=1; b-=1; c-=1;}
    void print();
    bool rightTrian();
private:
    int a,b,c;
};

Triangle::Triangle(int sideA, int sideB, int sideC){
    a = sideA;
    b = sideB;
    c = sideC;
}

Triangle::Triangle(){
    a = 1;
    b = 1;
    c = 1;
}

int Triangle :: addToSmall(){
    int tmp;
    (a<b) ? tmp=a : tmp=b;
    (tmp<c) ? tmp=tmp : tmp=c;
    return tmp + 1;
}

void Triangle::print(){
    cout<<"A side: "<<a<<endl
        <<"B side: "<<b<<endl
        <<"C side: "<<c<<endl;
}

bool Triangle::rightTrian(){
    int c1 = pow(c,2);
    if(c1 = pow(a,2)+pow(b,2)) return true;
    else return false;
}

int main() {
    Triangle triangle(5,3,4);
    int p = triangle.perimeter();
    cout<<"Perimeter = "<<p<<endl;
    int a = triangle.area(p);
    cout<<"Area = "<<a<<endl;
    triangle.print();
    triangle.extract();
    cout<<"New values: "<<endl;
    triangle.print();

    return 0;
}