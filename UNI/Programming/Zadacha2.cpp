#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv[]){
    string get; 
    int num; 
    cout<<"Enter the txt file name and the number of lines"<<endl;
    cin>>get;
    cin>>num;

    fstream readFile;
    readFile.open(get);
    


    return 0;
}