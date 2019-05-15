#include <iostream>
#include <vector>
using std::vector;

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


int fibonacci_sum_naive(long long n) {
    int digit = fibo_fast(n + 2 , 10);

    if(digit == 0)
        return 9;
    return digit - 1;
}


long long get_fibonacci_partial_sum_naive(long long from, long long to) {
  long long from_digit = fibonacci_sum_naive(from-1);
  long long to_digit = fibonacci_sum_naive (to);

  if(to_digit >= from_digit){
    return to_digit - from_digit;
  }
  return 10 + to_digit - from_digit;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
