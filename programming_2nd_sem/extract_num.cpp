#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string filename;
    cout<<"Enter the filename: ";
    cin>>filename;

    ifstream infile;
    infile.open(filename.c_str());
    if (infile.fail()) cout<<"Error";

    int sum = 0;
    while(!infile.eof()){
        char ch;
        infile.get(ch);
        if ('0' <= ch && ch <= '9'){
            infile.unget();
            int n;
            infile >> n;
            sum += n;
        }
    }
    infile.close();

    cout<<"The sum is "<<sum;
    return 0;
}