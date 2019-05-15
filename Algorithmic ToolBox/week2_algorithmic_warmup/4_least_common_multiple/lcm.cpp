#include <iostream>


void swap(long long &a, long long &b){
  int c = a;
  a = b;
  b = c;
}

int gcd_naive(int a, int b) {
  long long num1 =0;
  long long num2 =0;
  long long c = 1;

  if(a > b){
    num1 = a;
    num2 = b;
  }else{
    num1 = b;
    num2 = a;
  }

  while(num1!=0 && num2!=0){
    num1 = num1%num2;
    swap(num1,num2);
    if(num1 == 0)
      c = num2;
    if(num2 ==0 )
      c = num1;

    if(num1 < num2){
      c =1;
      break;
    }
}

return c;
}


long long lcm_naive(long long a, long long b) {
  long long hcf = gcd_naive(a,b);
  long long lcm = a * b / hcf;
  return lcm;
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
