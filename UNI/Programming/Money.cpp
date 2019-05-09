#include <iostream>
using namespace std;

class Money{
public:
    Money (int a, int b): first(a), second(b) {}
    Money operator+ (const Money& right) {
        return Money (first + right.first + (second + right.second)/100,
                        (second + right.second) % 100 );
    }
    friend ostream& operator<< (ostream& ostr, Money& m) {
        ostr<< m.first << "." << m.second;
    }
private:
    int first, second;
};

int main(){
    Money a(3,20), b(2,90);
    Money c = a + b;
    cout << c <<endl;
    return 0;
}