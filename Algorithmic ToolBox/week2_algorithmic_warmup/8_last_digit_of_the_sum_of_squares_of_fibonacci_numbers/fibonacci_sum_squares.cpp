#include <iostream>
#include <vector>
#include <math.h>

int get_period (long long m, std::vector<long long> &remainders){
  long long a = 0;
  long long b = 1;
  long long c = a + b;
  long long i = 2;

  remainders.push_back(a);
  remainders.push_back(b);

  while(m >=2){
      c = (a+b)%m;
      a = b;
      b = c;
      remainders.push_back(c);
      if(a==0 && b==1)
        return i - 1;
      i++;
  }
}

long long fibo_fast (long long n, long long m) {
  std::vector<long long> remainders;
  long long period = get_period(m, remainders);
  long long index = n % period;
  return remainders[index];
}


int fibonacci_sum_squares_naive(long long n) {
  long long fn = fibo_fast(n  , 10);
  long long fn1 = fibo_fast(n + 1, 10);
  long long ans = fn*fn1;
  return ans%10;
}

int main() {
    long long n;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
