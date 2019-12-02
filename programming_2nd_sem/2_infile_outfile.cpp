#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
takes all the numbers from the input file and puts them in the output file;
meanwhile it outputs the letters that got skipped;
*/
int main(){
    string infile;
    cout<<"Enter infile: ";
    cin>> infile;

    ifstream openfile;
    openfile.open(infile.c_str());

    string outfile;
    cout<<"Enter outfile: ";
    cin>> outfile;

    ofstream exitfile;
    exitfile.open(outfile.c_str());

    while(!openfile.eof()){
        char ch;
        openfile >> ch;
        if ('0'<= ch && ch<= '9'){
            openfile.unget();
            int n;
            openfile >> n;
            exitfile << n << " ";
        }
        else cout << ch << " ";
    }
    openfile.close();
    exitfile.close();

    return 0;
}