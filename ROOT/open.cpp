#include <iostream>
#include <string.h>

class People{
    public:
        void ReadPeople(const char *, const char* );
        void PrintPeople() const;
    private:
        char* name;
        char* egn;
};

void People::ReadPeople(const char *str, const char *num){
    name = new char[strlen(str) + 1];
    strcpy(name, str);
    egn = new char[11];
    strcpy(egn, num);
}

void People::PrintPeople() const{
    std::cout<<"name: "<<name<<std::endl;
    std::cout<<"egn: "<<egn<<std::endl;
}

class Student: People{
    public:
        void ReadStudent(const char*,const char*,int, double);
        void PrintStudent() const;
    private:
        int facnum;
        double usp;
};

void Student::ReadStudent(const char *str, const char *num, int fac, double u){
    ReadPeople(str, num);
    facnum = fac;
    usp = u;
}

void Student::PrintStudent() const{
    PrintPeople();
    std::cout<<"facnum: "<<facnum<<std::endl;
    std::cout<<"uspeh: "<<usp<<std::endl;
}

int main(){
    Student stud;
    stud.ReadStudent("Ivan Petrov", "0930498324", 43235, 5.49);
    stud.PrintStudent();
    int hodor;
    hodor = 5;
    std::cout << hodor << std::endl;

    return 0;
}