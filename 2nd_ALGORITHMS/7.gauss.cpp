#include <iostream>
using namespace std;

int main(){
    int Rows=3;
    int Cols=4;
    double a[Rows][Cols] = {{2.0,9.0,1.0,134.0}, {9.0,-3.0,8.0,12.0}, {2.0,9.0,5.0,-36.0}};

    for(int i=0; i<Rows; i++){
        double first_el = a[i][i];
        for(int j=i; j<Cols; j++){
            a[i][j] = a[i][j]/first_el;
        }
        for(int k=i+1; k<Rows; k++){
            double ff = a[k][i];
            for(int l=i; l<Cols; l++){
                a[k][l] = a[k][l] - ff*a[i][l];
            }
        }
    } 

    cout << endl;
    for(int i=0;i<3;i++){
        for(int j=0; j<4; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    double x3 = a[2][3];
    double x2 = a[1][3] + (-1*(a[1][2] * x3));
    double x1 = a[0][3] + (-1*(a[0][1] * x2 + a[0][2] * x3));

    cout<<"x1 = "<<x1<<endl
        <<"x2 = "<<x2<<endl
        <<"x3 = "<<x3<<endl;

    return 0;
}