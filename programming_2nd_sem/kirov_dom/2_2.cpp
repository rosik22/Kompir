//catfiles

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{

if(argc<=1)
{
    cout<<"Usage: "<<argv[0]<<" file1 file2 ... output file"<<endl;
    return -1;
}

string line;
ifstream fin;
ofstream fout;
string filename=argv[(argc-1)];

fout.open(filename);
if(fout.fail())
{
    cout<<"Error opening file "<<filename<<endl;
    return -1;
}

for(int i=1;i<=argc-1;i++)
{
 fin.open(argv[i]);
 if(fin.fail())
 {
    cout<<"Error opening file "<<argv[i]<<endl;
    return -1;
 }

    while(getline(fin,line))
    {
        fout<<line<<'\n';
    }
 fin.close();

}
fout.close();
return 0;
}
