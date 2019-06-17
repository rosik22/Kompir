#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    set <int, int> arr;
    for(int i=0; i<5; i++){
        for(int j=5; j<10; j++){
            arr.insert(i,j);
        }
    }

    set<int,int> :: iterator it, it1;
    for(it = arr.begin(); it!= arr.end(); it++){
        for(it1 = arr.begin(); it1 != arr.end(); it1++){
            cout<<*it<<" "<<*it1;
        }
        cout<<endl;
    }


    int arr1[2][2] = {{2, 4}, {3, 6}};
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}