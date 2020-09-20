#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

struct Point {
 int x; int y;
 Point() : x(0), y(0) {}
 Point(int a, int b) : x(a), y(b) {}
};

int gcd(int a, int b){
    while (b){
      int temp = b;
      b = a % b;
      a = temp;
    }
  return a;
}

 // solution function
int maxPoints(vector<Point>& points){
  int answer = 0;
  if(points.empty()) return 0; if(points.size() == 1) return 1;

  double slope,den,num;int n = points.size(),same = 1; map<double,int> dict;
  for(int i = 0;i < n;i++){
    for(int j = i+1;j < n;j++){
      den = points[j].x-points[i].x;
      num = points[j].y-points[i].y;
      if(den == 0 && num == 0) { same++; continue; }
      else if(den == 0) slope = points[i].x;
      else if (num == 0) slope = points[i].y;
      else {
        float hcf = gcd(den,num);
        den /= hcf; num /= hcf;     
        slope = num/den;
      }
      if(dict.find(slope) != dict.end()) dict[slope]++; else dict[slope] = 1;
    }
    for(auto k:dict) answer = max(answer,k.second+same);
    if(dict.empty() && same > 1) answer = max(answer,same);
    dict.clear();
    same = 1;
  }

  return answer;
}

int main(){

  int n;
  cin>>n;
  vector<Point> arr(n);
  for(int i = 0;i < n;i++) cin>>arr[i].x>>arr[i].y;

  cout<<maxPoints(arr)<<endl;
  return 0;
}
