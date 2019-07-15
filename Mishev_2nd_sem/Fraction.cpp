#include <iostream>

class Fraction{
public:
    Fraction(int a, int b) : n(a),d(b) {}
    friend Fraction operator+ (const Fraction& left, const Fraction& right);
    friend std::ostream& operator<< (std::ostream& , const Fraction&);
    friend std::istream& operator>> (std::istream& istr, Fraction& f);
private:
    int n, d;
};

Fraction operator+ (const Fraction& left, const Fraction& right){
    return Fraction (left.n*right.d + right.n*left.d,
                     left.d * right.d);
}

std::ostream& operator<< (std::ostream& ostr, const Fraction& f){
    ostr << f.n << "/" << f.d<<" ";
    return ostr;
}

std::istream& operator>> (std::istream& istr, Fraction& f){
    int a,b;
    char c;
    istr >> a >> c >> b;
    f = Fraction(a,b); 
    return istr;
}

int main(){
    Fraction a(1,2), b(3,2);
    Fraction c = a + b;
    std::cout << c << std::endl;
    std::cin >> a;
    std::cout << a;
    return 0;
}
