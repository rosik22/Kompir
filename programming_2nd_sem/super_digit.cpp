#include <iostream>
using namespace std;

int sum_digits(int n){
  int res = 0;
  while (n){
	res += n%10;
    cout<<n%10<<endl;
	n /=10;
    cout<<"n: "<<n<<endl;
  }
  return res;
}

int super_digit(int n){
  if (n < 10) return n;
  int sum = sum_digits(n);
  super_digit(sum);
}


int main(){
    int k = super_digit(23);
    cout<<k<<endl;
    return 0;
}