#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
public:
    Student (string, string, int);
    string get_name () const {return name;}
    string get_family () const {return family;}
    int get_facnum () const {return facnum;}
    int change_facnum(int fn1) {return facnum = fn1;}
    void print () const;
private:
    string name;
    string family;
    int facnum;
};

Student::Student (string n, string fn, int f){
    name = n;
    family = fn;
    facnum = f;
}

void Student::print() const{
    cout << get_name() << " "
        << get_family() << " " 
        << get_facnum() << endl;
}

void remove (vector<Student> &ss, int k){
    for(int i=0; i<ss.size(); i++){
        if (k == ss[i].get_facnum()){
            for(int j=i; j<ss.size() - 1; j++){
                ss[j] = ss[j+1];
                ss.pop_back();
            }
        }
    }
}

void add(vector <Student> &ss, const Student &st){
    ss.push_back(st);
}

int main () {
    vector <Student> s;
    string n,f;
    int fn;
    while (cin >> n >> f >> fn) s.push_back(Student (n,f,fn));
     
    s[0].change_facnum(11111);

    remove (s, 23000);
    add (s, Student("Ina", "Val", 22222));
    
    for(int i=0; i<s.size(); i++) s[i].print();

    return 0;
}

