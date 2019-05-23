#include <algorithm>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

long long max_dot_product(vector<long long> a, vector<long long> b) {
  long long result = 0;
   sort(a.begin(), a.end(), greater <>());
   sort(b.begin(), b.end(), greater <>());

   for (int i = 0; i < a.size() ; i++) {
     result += a[i] * b[i];
   }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<long long> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
