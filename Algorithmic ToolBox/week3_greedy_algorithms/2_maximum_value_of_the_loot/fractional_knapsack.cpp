#include <iostream>
#include <vector>
#include <map>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double totalValue = 0.0;
  //LET 'UNIT' BE VALUE/weight
  map <double,int> units;
  double remaingWeight = capacity;

  for (int i = 0 ; i<weights.size(); ++i ) {
     units.insert( pair<double,int> (values[i]*1.0/weights[i] , weights[i]));
  }

  for(auto it = units.rbegin(); it!=units.rend(); ++it){
    double value = 0.0;
    if(it->second <= remaingWeight){
      value = it->first * it->second;
      remaingWeight -= it->second;
      totalValue += value;
    }else{
      value = remaingWeight*it->first;
      totalValue += value;
      break;
    }
  }
  return totalValue;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
