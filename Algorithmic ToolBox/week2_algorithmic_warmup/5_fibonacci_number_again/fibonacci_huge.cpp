#include <iostream>
#include <vector>


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


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << fibo_fast(n, m) << '\n';
}
