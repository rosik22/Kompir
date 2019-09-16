#include <iostream>
#include <fstream>
#include <string>
using namespace std;

double get_max(ifstream& o){
    double high;
    double next;
    if (o >> next) high = next;

    while(o >> next){
        if (next > high) high = next;
    }

    return high;
}

int main(){
    string name;
    cout<<"Enter the file name: ";
    cin>>name;

    ifstream data;
    data.open(name.c_str());

    double max = get_max(data);
    cout << "Biggest value: "<< max<<endl;

    return 0;
}