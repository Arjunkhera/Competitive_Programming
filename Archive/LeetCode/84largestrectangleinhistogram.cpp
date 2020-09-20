#include<iostream>
#include<vector>
#include<climits>
#include<stack>

using namespace std;

// solution function : two loops
int largestRectangleArea(vector<int>& heights){
  if(heights.empty()) return 0;

  int temparea,l,r,i,n = heights.size(),answer = 0; pair<int,int> temp;
  vector<int> left(n,-1),right(n,-1); stack<pair<int,int>> stk;

  stk.push(make_pair(heights[0],0));
  for(i = 1;i < n;i++){ temp = stk.top();
    if(heights[i] < temp.first)
      while(heights[i] < temp.first){ right[temp.second] = i-1; stk.pop(); if(stk.empty()) break; temp = stk.top();}
    stk.push(make_pair(heights[i],i));
  }
  temp = stk.top(); right[temp.second] = temp.second; stk.pop();
  while(!stk.empty()){ right[stk.top().second] = temp.second; stk.pop(); }

  stk.push(make_pair(heights[n-1],n-1));
  for(i = n-2;i >= 0;i--){ temp = stk.top();
    if(heights[i] < temp.first)
      while(heights[i] < temp.first){ left[temp.second] = i+1; stk.pop(); if(stk.empty()) break; temp = stk.top(); }
    stk.push(make_pair(heights[i],i));
  }
  temp = stk.top(); left[temp.second] = temp.second; stk.pop();
  while(!stk.empty()){ left[stk.top().second] = temp.second; stk.pop(); }

  // for(auto k:left) cout<<k<<" "; cout<<endl;
  // for(auto k:right) cout<<k<<" "; cout<<endl;

  for(i = 0;i < n; i++){
    l = left[i] ; r = right[i]; temparea = heights[i]*(1 + (r-i) + (i-l)) ;
    answer = max(answer,temparea);
  }
  return answer;
}

// with some optimizations : two loops
int largestRectangleArea2(vector<int>& heights){
  if(heights.empty()) return 0;

  int i,n = heights.size(),answer = 0; pair<int,int> temp,index;
  vector<int> area(heights); stack<pair<int,int>> stk;

  stk.push(make_pair(heights[0],0));
  for(i = 1;i < n;i++){ temp = stk.top();
    if(heights[i] < temp.first)
      while(heights[i] < temp.first){ area[temp.second] += (i-1-temp.second)*temp.first; stk.pop(); if(stk.empty()) break; temp = stk.top();}
    stk.push(make_pair(heights[i],i));
  }
  temp = stk.top(); stk.pop();
  while(!stk.empty()){ index = stk.top(); area[index.second] += index.first*(temp.second-index.second); stk.pop(); }

  stk.push(make_pair(heights[n-1],n-1));
  for(i = n-2;i >= 0;i--){ temp = stk.top();
    if(heights[i] < temp.first)
      while(heights[i] < temp.first){ area[temp.second] += (temp.second-i-1)*temp.first; stk.pop(); if(stk.empty()) break; temp = stk.top(); }
    stk.push(make_pair(heights[i],i));
  }
  temp = stk.top(); stk.pop();
  while(!stk.empty()){ index = stk.top(); area[index.second] += index.first*(index.second-temp.second); stk.pop(); }

  for(auto k:area) answer = max(answer,k);
  return answer;
}

// single loop : best solution from discussion
int largestRectangleArea3(vector<int>& heights){
  if(heights.empty()) return 0;

  int answer = 0;
  heights.push_back(0);
  vector<int> index;

  for(int i = 0; i < heights.size(); i++){
    while(index.size() > 0 && heights[index.back()] > heights[i]){
      int h = heights[index.back()];
      index.pop_back();

      int sidx = index.size() > 0 ? index.back() : -1;
      if(h * (i-sidx-1) > answer) answer = h * (i-sidx-1);
    }
    index.push_back(i);
  }
  return answer;
}

int main(){
  int temp;
  cin>>temp;
  vector<int> arr;
  while(temp != -1) { arr.push_back(temp); cin>>temp; }

  cout<<largestRectangleArea3(arr)<<endl;
  return 0;
}
