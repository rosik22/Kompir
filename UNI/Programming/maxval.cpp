#include <iostream>
#include <string>
#include <fstream>
using namespace std;

double read_data(ifstream& in){
    double highest;
    double next;
    if(in>>next) highest = next;
    else return 0;

    while(in>>next) if(next>highest) highest = next;
    
    return highest;
}

int main(){
    string filename;
    cout<<"Enter the filename: ";
    cin>>filename;

    ifstream infile;
    infile.open(filename.c_str());

    if(infile.fail()){
        cout<<"Input failed";
        return 1;
    }

    double max = read_data(infile);
    cout<<"Max value is: "<<max;

    infile.close();
    return 0;
}