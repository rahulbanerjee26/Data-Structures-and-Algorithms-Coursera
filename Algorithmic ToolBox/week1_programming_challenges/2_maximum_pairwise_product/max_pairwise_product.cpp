#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long MaxPairwiseProduct(const std::vector<int>& numbers) {

    std::vector<int> v = numbers;

    long long result = -1;
    long long num1 = 1;
    long long num2 = 1;

    const auto it = max_element(v.begin(),v.end());

    num1 = *it;

    v.erase(it);

    if(v.size() != 0){
      auto it1 = max_element(v.begin(),v.end());
      num2 = *it1;
    }

    result = num1*num2;

    return result;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
