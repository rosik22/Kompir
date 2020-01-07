#include <iostream>
#include <set>
using namespace std;

set<int> set_unions(set<int> a, set<int> b)
{
  set<int>::iterator it_a;
  set<int>::iterator it_b;
  set<int>::iterator it_c;
  set<int> c;
    for(it_a = a.begin(); it_a!= a.end(); it_a++)
        c.insert(*it_a);
    for(it_b = b.begin(); it_b!= b.end(); it_b++)
        c.insert(*it_b);
return c;
}
set<int> intersection(set<int> a, set<int> b)
{
  set<int>::iterator it_a=a.begin();
  set<int>::iterator it_b=b.begin();
  set<int> c;

    while(it_a!=a.end()&&it_b!=b.end())
    {
        if(*it_a < *it_b) it_a++;
         else if(*it_b < *it_a ) it_b++;
        else{
            c.insert(*it_a);
            it_a++;
            it_b++;
            }
    }
    return c;
}

void print(set<int> a)
{
    set<int>::iterator it;
    for (it = a.begin(); it!= a.end(); it++)
        cout << *it << " ";
    cout<<endl;
}

int main()
{
    set<int> a;
    for(int i=1;i<=5;i++)
    a.insert(i);
    set<int> b;
    for(int i=6;i<=10;i++)
    b.insert(i);

    cout<<"Set A: "<<endl;
    print(a);
    cout<<"Set B: "<<endl;
    print(b);
    cout<<"set_unions(a,b): "<<endl;
    print(set_unions(a,b));

    a.clear();
    b.clear();

    a.insert(5);
    a.insert(2);
    a.insert(9);
    a.insert(1);

    b.insert(7);
    b.insert(5);
    b.insert(4);
    b.insert(2);

    cout<<"New set A: "<<endl;
    print(a);
    cout<<"New set B: "<<endl;
    print(b);
    cout<<"intersection(a,b): ";
    print(intersection(a,b));

    return 0;
}
