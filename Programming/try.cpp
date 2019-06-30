#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){



    int arr1[2][2] = {{2, 4}, {3, 6}};

    set<int,int> a;
    a.insert(arr1);

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}