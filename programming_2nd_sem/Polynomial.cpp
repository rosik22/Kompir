#include <iostream>
#include <cmath>
using namespace  std;

template<typename T, typename T1>
class Polynomial{
    T* coeffs;
    int order;
public:
    Polynomial(T* _coeffs, int _order) {
        order = _order;
        coeffs = new T[order+1];
        for(int i=0; i<=order; i++){
            coeffs[i] = _coeffs[i];
        }
    }
    ~Polynomial(){
        delete[] coeffs;
    }
    T1 evaluate(T1 x){
        T1 sum = 0;
        for(int i=0; i<=order; i++){
            sum+= coeffs[i] * pow(x, order - i);
        }
        return sum;
    }
    int get_order() {return order;}
};

int main(){
    int a[] = {1,3,2};
    Polynomial<int, float> P(a, 2);
    cout<<P.evaluate(2)<<endl;

    return 0;
}
