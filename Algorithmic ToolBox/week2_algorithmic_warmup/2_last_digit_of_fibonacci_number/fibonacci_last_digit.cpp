#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
  if(n == 0)
    return 0;
  if(n==1)
    return 1;

  long long a=0;
  long long b=1;
  long long c = a + b;

  for (int i = 2; i < n ; i++){
    a = b;
    b = c;
    c = (a + b) % 10; ;
  }

  return c;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }
