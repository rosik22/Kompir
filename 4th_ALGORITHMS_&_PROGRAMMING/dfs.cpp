#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,v,used[101];

void dfs(int k, vector<int> a[])
{
  printf("%d ",k);
  for(int i=0; i<a[k].size(); i++)
  {
    if(used[a[k][i]]) continue;
    used[a[k][i]]=1;
    dfs(a[k][i], a);
  }
}

int main()
{
  vector<int>a[10];
  scanf("%d %d",&n,&v); /* Брой върхове на графа и   връх, от който да обхождаме*/
  int b,c;
  while(b!=0 || c!=0)
  {
    scanf("%d %d",&b,&c);
    a[b].push_back(c);
    a[c].push_back(b);
  }
  for (int i=0; i<n; i++)   sort(a[i].begin(),a[i].end());
  used[v]=1;
  for(auto e: a){
      for(auto s: e){
          cout<<s<<" ";
      }
      cout<<endl;
  }
  dfs(v,a);
  return 0;
}