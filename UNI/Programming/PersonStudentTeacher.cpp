#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Person{
public:
    virtual void read(ifstream& ) = 0;
    virtual void write(ofstream& ) = 0;
    virtual string getName() = 0;
    virtual string getInfo() = 0;
protected:
    string name;
    string fname;
};

class Student : public Person{
public:
    virtual void read(ifstream& in){in>>name>>fname>>facnum;}
    virtual void write(ofstream& out) {out<<name<<" "<<fname<<" "<<facnum<<endl;}
    virtual string getName() {return name;}
    virtual string getInfo() {return name+fname+facnum;}
private:
    string facnum;
};

class Teacher : public Person{
public:
    virtual void read(ifstream& in){in>>name>>fname>>course;}
    virtual void write(ofstream& out) {out<<name<<" "<<fname<<" "<<course<<endl;}
    virtual string getName() {return name;}
    virtual string getInfo() {return name+fname+course;}
private:
    string course;
};

int main(){
    vector <Person*> persons;

    ifstream in_data;
    in_data.open("student.txt");
    int n;
    in_data>>n;
    for(int i=0; i<n; i++){
        Student* student = new Student();
        student->read(in_data);
        cout<<student->getInfo()<<endl;
        persons.push_back(student);
    }
    in_data.close();

    in_data.open("teacher.txt");
    in_data>>n;
    for(int i=0; i<n; i++){
        Teacher* teacher = new Teacher();
        teacher->read(in_data);
        cout<<teacher->getInfo()<<endl;
        persons.push_back(teacher);
    }
    in_data.close();

    ofstream out_data;
    out_data.open("person.txt");
    for(int i=0; i<persons.size(); i++){
        Person* person = persons[i];
        if(person->getName()[0] == 'J')
            person->write(out_data);
    }
    out_data.close();

    return 0;
}