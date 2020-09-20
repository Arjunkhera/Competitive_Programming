#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool compare(string a,string b){

  string ab = a+b;
  string ba = b+a;

  return ab.compare(ba)>0?1:0;

}

string largestNumber(vector<int>& nums) {

  if(nums.empty())
    return 0;

  vector<string> arr;
  string str;

  for(int i=0;i<nums.size();i++){
    str = to_string(nums[i]);
    arr.push_back(str);
  }

  sort(arr.begin(),arr.end(),compare);

  string answer = "";
  for(int i=0;i<arr.size();i++)
    answer += arr[i];

  if(answer[0] == '0')
    return "0";

  return answer;
}

int main(){
  vector<int> arr;
  int temp;

  cin>>temp;
  while(temp != -1){
    arr.push_back(temp);
    cin>>temp;
  }

  cout<<largestNumber(arr)<<endl;

  return 0;
}
