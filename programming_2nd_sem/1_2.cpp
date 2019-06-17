#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int main(int argc, char const *argv[]){
    string inputsPath = argv[2];

    string arg1 = argv[1];
    int num = std::atoi (arg1.c_str());

    ifstream data(inputsPath);

    string line;
    int i = 0;
    vector<string> vec;

    while(i<num){
        data>>line;
        vec.push_back(line);
        i++;
    }

    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<endl;
    }

    data.close();

    return 0;
}