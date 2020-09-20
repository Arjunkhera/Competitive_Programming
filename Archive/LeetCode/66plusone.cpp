#include<iostream>
#include<vector>

using namespace std;

// works for leading zeros also
vector<int> plusOne(vector<int>& digits){

  vector<int> answer;
  if(digits.empty())
    return answer;

  int carry = 1;
  int n = digits.size();
  int i = n-1;

  // find the first non zero digit
  int j = 0;
  for(;j<n;j++)
    if(digits[j] != 0)
      break;

  while(i >= j){
    digits[i] = digits[i]+carry;
    carry = digits[i]/10;
    digits[i] = digits[i]%10;

    i--;
  }

  if(carry)
    if(i < 0)
      answer.push_back(carry);
    else {
      digits[i] = carry;
      i--;
    }

  i++;
  for(;i<n;i++)
    answer.push_back(digits[i]);

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

  vector<int> answer = plusOne(arr);

  for(auto i:answer)
    cout<<i<<" ";
  cout<<endl;

  return 0;
}
