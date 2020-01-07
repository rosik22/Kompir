#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;


class Worker
{
public:
Worker(string nam,double sal)
{
    salary=sal;
    name=nam;
}

virtual void compute_pay(int hours)=0;
string get_name(){return name;}
double get_sal(){return salary;}

private:
string name;
double salary;
};

class HourlyWorker : public Worker
{
public:
HourlyWorker(string nam,double s) : Worker(nam,s){}
virtual void compute_pay(int hours)
 {
    double addHours = 0;
    if(hours>40)
     {
        addHours = hours-40;
        cout<<fixed<<setprecision(2)<<((40*10)+(addHours*15));
     }
       else
        {
          cout<<fixed<<setprecision(2)<<hours*10+addHours;
        }
 }
};

class SalariedWorker : public Worker
{
public:
SalariedWorker(string nam,double s) : Worker(nam,s){}
virtual void compute_pay(int hours)
  {
    double remainder=0;
    hours=40;
    cout<<fixed<<setprecision(2)<<hours*10+remainder;
  }
};


int main()
{
vector<Worker*> w;
ifstream in;
in.open("input.txt");
int num;
vector<string> name;
string cp_name;
vector<string> pos;
string cp_pos;
vector<int> salaries;
int cp_salaries;

in>>num;
for(int i=0;i<num;i++)
{
    in>>cp_name;
    in>>cp_pos;
    name.push_back(cp_name);
    pos.push_back(cp_pos);
}
for(int i=0;i<num;i++)
{
    in>>cp_salaries;
    if(pos[i]=="sal")
     {
        w.push_back(new SalariedWorker(name[i],cp_salaries));
     }
    if(pos[i]=="hou")
     {
        w.push_back(new HourlyWorker(name[i],cp_salaries));
     }
}

for(int i=0;i<w.size();i++)
{
 cout<<w[i]->get_name();
 cout<<"\t";
 w[i]->compute_pay(w[i]->get_sal());
 cout<<endl;
}

    return 0;
}
