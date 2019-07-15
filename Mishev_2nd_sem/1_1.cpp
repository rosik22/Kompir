#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Baryon{
protected:
    const char* quarks;
public:
    virtual char* get_composition() = 0;
};

class Proton: public Baryon{
protected:
    int num1,num2;
public:
    Proton(int n1, int n2) {
        quarks = "uud";
        num1 = n1;
        num2 = n2;
    }
    virtual char* get_composition(){
        cout<<"u - "<<num1+num1+num2<<endl;
    }
};

class Neutron: public Baryon{
protected:
    int num1,num2;
public:
    Neutron(int n1, int n2) {
        quarks = "udd";
        num1 = n1;
        num2 = n2;
    }
    virtual char* get_composition() {
        cout<<"d - "<<num1+num2+num2<<endl;
    }
};

int main(){
    ifstream in_data;
    in_data.open("Baryon.txt");

    string letter;
    int num1, num2;

    in_data>>letter>>num1;
    in_data>>letter>>num2;

    vector <Baryon*> bar;

    Proton *p = new Proton(num1,num2);
    bar.push_back(p);

    Neutron *n = new Neutron(num1,num2);
    bar.push_back(n);

    for(int i=0; i<bar.size(); i++){
        bar[i]->get_composition();
    }

    return 0;
}