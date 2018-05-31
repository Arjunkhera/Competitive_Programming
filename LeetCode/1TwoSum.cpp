#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> values;
    vector<int> answer;
    map<int,int>::iterator j;
    
    for(auto i = nums.begin();i!=nums.end();i++){
       j = values.find(*i);
       if( j != values.end()){
           answer.push_back(j->second);
           answer.push_back(i-nums.begin());
           break;
       }
       values[target - *i] = i-nums.begin();
    }
    return answer;
}

int main(){

  vector<int> testing{2,7,11,15};
  vector<int> answer = twoSum(testing,9);

  for(auto i : answer)
    cout<<i<<" ";

  cout<<endl;
  return 0;
}
