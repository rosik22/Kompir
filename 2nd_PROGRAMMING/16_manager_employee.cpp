#include <iostream>
using namespace std;

class Employee{
    string name;
    double salary;
public:    
    Employee(string n, double sal);
    void set_salary(double n_sal);
    string get_name();
    double get_salary();
    void print();
};

class Manager : public Employee{
    string department;
public:
    Manager(string n, double sal, string dep);
    string get_department();
    void print();
};

int main(){
    Employee John("John", 1200);
    John.set_salary(1300);
    John.print();

    Manager Dave("Dave", 3400, "hui");
    Dave.set_salary(3500);
    //cout<<Dave.get_department()<<endl;
    Dave.print();
}

Employee::Employee(string n, double sal){
    name = n;
    salary = sal;
}

void Employee::set_salary(double n_sal){
    salary = n_sal;
}

string Employee::get_name(){
    return name;
}

double Employee::get_salary(){
    return salary;
}

void Employee::print(){
    cout<<get_name()<<" "<<salary<<endl;
}

Manager::Manager(string n, double sal, string dep) : Employee(n, sal){
    department = dep;
}

string Manager::get_department(){
    return department;
}

void Manager::print(){
    Employee::print();
    cout<<get_department()<<endl;
}