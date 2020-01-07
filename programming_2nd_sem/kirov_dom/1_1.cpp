#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Person{
public:
Person(string n,int a):name(n), age(a) {}

string get_name() const
{
    return name;
}

int get_age() const
{
    return age;
}

void increaseAge()
{
    age++;
}

private:
    string name;
    int age;

};

class Car{
public:
Car(string m, Person* o, Person* d)
{
    model=m;
    owner=o;
    driver=d;
}

string get_model() const
{
    return model;
}

void get_owner()
{
    cout<<owner->get_name()<<" "<<owner->get_age();
}

void get_driver()
{
    cout<<driver->get_name()<<" "<<driver->get_age();
}

private:
string model;
Person* owner;
Person* driver;
};


void print_all(vector<Car*> &cars)
{
    for(int i=0;i<cars.size();i++)
    {
            cout<<cars[i]->get_model()<<endl;
            cout<<"Owner: ";
            cars[i]->get_owner();
            cout<<endl;
            cout<<"Driver: ";
            cars[i]->get_driver();
            cout<<endl;
    }
}

int main()
{
 vector<Person*> p;
 string name;
 int age,br;

 vector<Car*> c;
 string model;
 string driver,owner;

 ifstream in;
 string file_name="input.txt";
 in.open(file_name.c_str());

 in>>br;

 for(int i=0;i<br;i++)
 {
    in>>name>>age;
    Person* pr=new Person(name,age);
    p.push_back(pr);
 }
  in>>br;

  int m=0;
  int j=0;

 for(int i=0;i<br;i++)
 {
    in>>model>>owner>>driver;

    for(; m<p.size();m++)
     {
        if(owner == p[m]->get_name()) break;
     }
    for(; j<p.size();j++)
     {
        if(driver == p[j]->get_name()) break;
     }
    Car* cr= new Car (model,p[m],p[j]);
    c.push_back(cr);
}

in.close();

for(int i=0; i<p.size(); i++)
 {
    p[i]->increaseAge();
 }

 print_all(c);

    return 0;
}
