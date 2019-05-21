#include <iostream>

int get_change(int m) {
  int tens = 0;
  int fives =0;
  int ones = 0;
  int remainingValue = m;

  tens = remainingValue/10;
  remainingValue -= tens*10;

  fives = remainingValue/5;
  remainingValue -= fives*5;
  ones = remainingValue;

  int n = tens + fives + ones;

  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
