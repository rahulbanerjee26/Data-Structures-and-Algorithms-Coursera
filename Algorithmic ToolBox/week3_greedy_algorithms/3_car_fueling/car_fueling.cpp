#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
  int currPos = 0;
  int lastPos = 0;
  bool reached = false;
  int refills =0;

 //insert starting position and ending position
  stops.push_back (0);
  stops.push_back(dist);
  sort(stops.begin(),stops.end());

  while (currPos < stops.size() - 1) {
    lastPos = currPos;

    while(currPos < stops.size() - 1 && stops[currPos + 1] - stops[lastPos] <= tank){
      currPos++;
    }
    //mext stop is farther than the distance the car can travel on a full tank
    if(currPos == lastPos && stops[currPos] != dist){
      return -1;
    }

    if(currPos <= stops.size())
    refills++;
  }

  return refills - 1;
}



int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
