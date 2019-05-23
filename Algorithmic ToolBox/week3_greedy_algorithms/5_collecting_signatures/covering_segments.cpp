#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
  int start, end;
};

bool myfunc(Segment a, Segment b){
  return a.start < b.start;
}

bool inRange(int start, int end, int point){
  if(point >=start && point <=end)
    return true;
  return false;
}

vector<int> optimal_points(vector<Segment> &segments) {
  sort(segments.begin(), segments.end(),myfunc);
  vector <int> points;
  int currIndex = 0;
  int prevIndex = 0;

  while(currIndex < segments.size()){
    int minStart = segments[currIndex].start;
    int maxEnd = segments[currIndex].end;
    while(currIndex<segments.size() && inRange(minStart,maxEnd,segments[currIndex+1].start)){
      currIndex++;
      if(currIndex != segments.size() ){
        if(segments[currIndex].start > minStart)
          minStart = segments[currIndex].start;
        if(segments[currIndex].end < maxEnd)
          maxEnd = segments[currIndex].end;
      }
    }

   if(currIndex == segments.size())
    currIndex--;

    points.push_back(segments[currIndex].start);

    currIndex++;
  }

  return points;


}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
