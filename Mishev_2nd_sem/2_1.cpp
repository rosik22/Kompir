#include <iostream>
#include <vector>
using namespace std;

/* от задачата разбирам да се направи клас,
който създава двумерен масив или вектор,
чиито стойности са числа от различен тип. 
Тъй като С++ не позволява да се създават такива структури,
които да пазят стойности от различен тип, създадох Matrix обект
от тип double, тъй като този тип допуска и integer числа
и напълних вектора с integer и double стойности;
*/

template<typename T>
class Matrix{
protected:
    vector<vector<T>> matrix;

public:
    Matrix() {
        matrix = {{1, 2, 3.1}, {1, 4.3, 2} , {1.0, 5.7, 2}};
    }

    void print(){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Matrix<double> matrix1;
    matrix1.print();

    return 0;
}