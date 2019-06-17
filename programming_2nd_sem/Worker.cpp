#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

class Worker{
public:
    Worker() = default;
    Worker(string n, string t);
    string getName() {return name;}
    string getType() {return type;}
    void read(ifstream & in) {in>>name>>type;}
    virtual int compute_pay(int ) {return 1;}
protected:
    string name;
    string type;
};

Worker::Worker(string n, string t){
    name = n;
    type = t;
}

class HourlyWorker : public Worker{
public:
    HourlyWorker() = default;
    HourlyWorker(string n1, string t1) : Worker(n1, t1) {}
    virtual int compute_pay(int k);
};

class SalariedWorker : public Worker{
public:
    SalariedWorker() = default;
    SalariedWorker(string n2, string t2) : Worker(n2, t2) {}
    virtual int compute_pay(int p) {return 400.00;}
};

int HourlyWorker::compute_pay(int k){
    int t = 0;
    if (k <= 40) t = k*10;
    else {
        int s = k-40;
        t = (40 + s*1.5)*10;
    }
    return t;
}

void fill(vector <pair <string, int>> &result, vector <Worker> workers, vector <int> hours){
        
        int res;
    for(int i=0; i<workers.size(); i++){
        int p = hours[i];
        if(workers[i].getType() == "sal") {
            SalariedWorker salwork; 
            res=salwork.compute_pay(p);
            result[i].first = workers[i].getName();
            result[i].second = res;
            }
        else {
            HourlyWorker hwork;
            res = hwork.compute_pay(p);
            result[i].first = workers[i].getName();
            result[i].second = res;
        }
    } 
}

void print(vector <pair<string, int>> result){
         for(int i=0; i<result.size(); i++){
        cout<<setw(5)<<result[i].first<<setw(5)<<result[i].second<<endl;
    }
}

int main(){
    vector <int> hours {30,40,20,50,40,45,50};
    vector <Worker> workers;
    Worker worker;

    ifstream in_data;
    in_data.open("workers.txt");
    int n;
    in_data>>n;
    for(int i=0; i<n; i++){
        worker.read(in_data);
        workers.push_back(worker);
    }
    vector <pair<string,int>> result (workers.size());

    fill(result, workers, hours);
    print(result);

    return 0;
}