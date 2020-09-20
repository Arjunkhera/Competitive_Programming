#include<iostream>
#include<vector>

using namespace std;

vector<int> repeatedNumber(const vector<int> &A) {
    vector<int> answer;
    if(A.empty()) return answer;

    long int n = A.size();
    int X1 = A[0];

    for(int i = 1;i < n;i++) X1 = X1^A[i];

    for(int j = 1; j <= n;j++) X1 = X1^j;

    int rightmostsetbit = X1 & ~(X1-1),numberA = 0,numberB = 0;

    for(int i = 0; i < n;i++)
        if(A[i] & rightmostsetbit) numberA = numberA^A[i];
        else numberB = numberB^A[i];

    for(int i = 1;i <= n;i++)
        if(i & rightmostsetbit) numberA = numberA^i;
        else numberB = numberB^i;

    bool flag = false;
    for(int i=0;i<n;i++) if(A[i] == numberA){ flag = true; break; }

    if(flag){ answer.push_back(numberA); answer.push_back(numberB); }
    else { answer.push_back(numberB); answer.push_back(numberA); }

    return answer;
}

int main(){
  vector<int> arr;
  int temp; cin>>temp;
  while(temp != -1){ arr.push_back(temp); cin>>temp; }

  vector<int> answer = repeatedNumber(arr);
  for(auto i:answer) cout<<i<<" ";
  cout<<endl;

  return 0;
}
