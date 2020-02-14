#include <iostream>
#include <vector>
using namespace std;

class Car {
public:
    Car(string c) {brand = c;} 
    string getBrand() {return brand;}
private:
    string brand;
};

class Person {
public:
    Person(string n, string fn, int fac, Car* c) {
        name = n;
        family = fn;
        facnum = fac;
        car = c;
    }
    string getName() const {return name;}
    string getFamily() const {return family;}
    Car* get_car() const {return car;}
    Car* set_car(Car* ); 
    void print(); 
private:
    string name;
    string family;
    int facnum;
    Car* car;
};

void Person::print(){
    cout << name << " " << family << " " << facnum;
    if (car != NULL) cout << " " << car->getBrand();
    cout << endl;
}

void print(vector<Person*> p){
    for(int i=0; i<p.size(); i++) p[i]->print();
}

Car* Person::set_car(Car *pc){
    Car* car_old = car;
    car = pc;
    return car_old;
}

int main(){
    vector <Person*> all;
    string n,f,c;
    int fn;
    while (cin>>n>>f>>fn>>c){
        Car *cc = NULL;
        cc = new Car (c);
        Person *stt = new Person(n,f,fn,cc);
        all.push_back(stt);
    }
    Car *pc = new Car ("Toyota");
    Car *pc_old = all[0]->set_car(pc);
    delete pc_old;
    print(all);

    return 0;
}