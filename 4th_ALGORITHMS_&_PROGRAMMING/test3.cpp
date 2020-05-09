#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0; i<n; i++){
        cin>>A[i];
    }

    //finds the max and min element
    int min=A[0], max=A[0];
    for(int i=0; i<n; i++){
        if(A[i]<min) min=A[i];
        else if(A[i]>max) max = A[i];
    }

    //find the difference of max and min;
    //if the difference is lower than min, it's set to min
    //if the difference is higher than max, it's set to max;
    int mid = max-min;
    if(mid<min){
        mid = min;   
    }
    else if(mid>max){
        mid = max;
    }

    //finds the indexes of the numbers which are
    //approximately equal to the mid value;
    vector<int> positions;
    int check;
    for(int i=0; i<n; i++){
        check = pow(A[i]-mid,2);
        if(check == 0) positions.push_back(i);
    }

    for(auto v:positions){
        cout<<v<<" ";
    }
}