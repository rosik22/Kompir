#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "ccc_empl.h"

using namespace std;

void merge(vector<Employee*>& a, int from, int mid, int to)
{  int n = to - from + 1;
   vector<Employee*> b(n);
   int i1 = from;
   int i2 = mid + 1;
   int j = 0;

   while (i1 <= mid && i2 <= to)
   {  if (a[i1]->get_salary() < a[i2]->get_salary())
      {  b[j] = a[i1];
         i1++;
      }
      else
      {  b[j] = a[i2];
         i2++;
      }
      j++;
   }

   while (i1 <= mid)
   {  b[j] = a[i1];
      i1++;
      j++;
   }
   while (i2 <= to)
   {  b[j] = a[i2];
      i2++;
      j++;
   }
   for (j = 0; j < n; j++) a[from + j] = b[j];
}

void merge_sort(vector<Employee*>& a, int from, int to)
{  if (from == to) return;
   int mid = (from + to) / 2;
   /* sort the first and the second half */
   merge_sort(a, from, mid);
   merge_sort(a, mid + 1, to);
   merge(a, from, mid, to);
}

void print(vector<Employee*> a)
{  for (int i = 0; i < a.size(); i++)
      cout << a[i]->get_name()<<" "<<a[i]->get_salary()<<" \n";
   cout << "\n";
}

int main()
{
   vector<Employee*> v;

   v.push_back(new Employee("Nino, Ninar", 67000.00));
   v.push_back(new Employee("Tester, Tina", 50000.00));
   v.push_back(new Employee("Hacker, Harry", 45000.00));
   v.push_back(new Employee("Hacker2, Harry2", 95000.00));

   print(v);
   merge_sort(v, 0, v.size() - 1);
   print(v);
   return 0;
}
