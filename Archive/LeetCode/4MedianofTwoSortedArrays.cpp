#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

double solve(vector<int> &arr,vector<int> &barr){

  if(arr.empty() && barr.empty())
    return 0;

  double answer = 0.0;
  int i = 0;
  int j = 0;
  int cur = 0;
  int stop = ceil(static_cast<double>(arr.size()+barr.size())/2);

  int whicharray = 0;
  bool flag;
  if((arr.size()+barr.size())%2)
    flag = false;
  else
    flag = true;

  while(i < arr.size() && j < barr.size()){

    if(arr[i] <= barr[j]){
      cur++;
      i++;
      whicharray = 1;
    }
    else {
      cur++;
      j++;
      whicharray = 2;
    }

    if(cur == stop)
      break;
  }

  if(cur != stop && i < arr.size()){
    cout<<"Exited at 1"<<endl;
    i += stop-cur;
    answer = arr[i-1];
    if(flag)
      answer = static_cast<double>(answer+arr[i])/2.0;
    return answer;
  }

  if(cur != stop && j < barr.size()){
    cout<<"Exited at 2"<<endl;
    j += stop-cur;
    answer = barr[j-1];
    if(flag)
      answer = static_cast<double>(answer+barr[j])/2.0;
    return answer;
  }

  if(whicharray == 1){
    cout<<"Exited at 3"<<endl;
    answer = arr[i-1];
    if(flag){
      if(i != arr.size()){
        answer += static_cast<double>(arr[i] < barr[j])?arr[i]:barr[j];
        answer /= 2.0;
      }
      else answer = static_cast<double>(answer+barr[j])/2.0;
    }
  }
  else {
    cout<<"Exited at 4"<<endl;
    answer = barr[j-1];
    if(flag){
      if(j != barr.size()){
        answer += static_cast<double>(arr[i] > barr[j])?barr[j]:arr[i];
        answer /= 2.0;
      }
      else answer = static_cast<double>(answer+arr[i])/2.0;
    }
  }

  return answer;
}

int main(){

  vector<int> arr;
  vector<int> barr;
  int temp;

  cin>>temp;
  while(temp != -1){
    arr.push_back(temp);
    cin>>temp;
  }
  cout<<endl;

  cin>>temp;
  while(temp != -1){
    barr.push_back(temp);
    cin>>temp;
  }

  cout<<solve(arr,barr)<<endl;

  return 0;
}
