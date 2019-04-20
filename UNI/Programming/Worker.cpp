#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Worker{
public:
    string getName() {return name;}
    string getType() {return type;}
    void read(ifstream & in) {in>>name>>type;}
    virtual int compute_pay(int );
protected:
    string name;
    string type;
};

class HourlyWorker : public Worker{
    virtual int compute_pay(int h_hours);
private:
    int h_hours;
};

class SalariedWorker : public Worker{
    virtual int compute_pay(int p) {return 400.00;}
private:
    int s_hours;
};

int main(){
    vector <int> hours {30,40,20,50,40,45,50};
    vector <Worker> workers;
    Worker *worker;
    
    ifstream in_data;
    in_data.open("workers.txt");
    int n;
    in_data>>n;
    for(int i=0; i<n; i++){
        Worker *worker = new Worker();
        worker->read(in_data);
        workers.push_back(*worker);
    }

    for(int i=0; i<workers.size(); i++){
        int res;
        int p = hours[i];
        if(workers[i].getType() == "sal") {
            SalariedWorker salwork;
            res=salwork.compute_pay(p);
            }
    }

    return 0;
}