#include <iostream>
using namespace std;

class Money{
public:
    Money (int a, int b): leva(a), stotinki(b) {}
    Money operator+ (const Money& m) {
        return Money(leva + m.leva + (stotinki + m.stotinki)/100 , (stotinki + m.stotinki)%100);
    }
    friend ostream& operator<< (ostream& ostr, Money& m) {
        ostr<< m.leva << "." << m.stotinki;
    }
    friend istream& operator>> (istream& istr, Money& m) {
        int l,s;
        char dot;
        istr>>l>>dot>>s;
        m = Money(l,s);
        return istr;
    }
private:
    int leva, stotinki;
};

int main(){
    Money a(3,20), b(2,90);
    Money c = a + b;
    cout << c <<endl;
    return 0;
}
