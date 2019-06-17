#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Nucleon
{
public:
    virtual short int get_charge() { return charge; }
    virtual string get_orbital() { return orbital; }

protected:
    short int charge = 0;
    string orbital;
};

class Proton : public Nucleon
{
public:
    Proton() { charge = 1; }
};

class Neutron : public Nucleon
{
public:
    Neutron() { charge = 0; }
};

class Nucleus : public vector<Nucleon *>
{
public:
    Nucleus(short int z, short int n)
    {
        neutrons = n;
        protons = z;
        for (int i = 0; i < z; i++)
        {
            Proton *p = new Proton();
            push_back(p);
        }

        for (int i = 0; i < n; i++)
        {
            Neutron *n = new Neutron();
            push_back(n);
        }
    }

    short int get_A() const { return neutrons + protons; }

private:
    int neutrons, protons;
    string abbr;
};

int main()
{
    ifstream in_data;
    in_data.open("nucleus");

    string elem;
    short int nn, np;
    while (in_data >> elem >> np >> nn)
    {
        Nucleus nucleus(np, nn);
        cout << nucleus.get_A() << endl;
    }

    in_data.close();
}