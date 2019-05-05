#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Baryon {
public:
    virtual string get_composition() = 0; 
protected:
    string quarks;
};

class Proton : public Baryon {
public:
    Proton () {quarks = "uud";}
    virtual string get_composition() {}
};

class Neutron : public Baryon {
public:
    Neutron() {quarks = "udd";}
    virtual string get_composition() ;
};

int main(){
    vector <Baryon*> nucleus;

    int n;
    fstream read;
    read.open("input.txt");
    read>>n;

    cout<<n;

    Baryon* b = new Proton();
    Baryon* p = new Neutron();


    return 0;
}