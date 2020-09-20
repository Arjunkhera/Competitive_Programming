#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

string countAndSay(int n) {

  string answer;
  if(n == 0)
    return answer;
  if(n == 1)
    return answer + "1";

  int freq;
  int num;
  queue<int> arr;
  arr.push(1);
  arr.push(0);

  while(n > 1){
    num = arr.front();
    arr.pop();

    if(num == 0){
      n--;
      if(n == 1)
        break;
      arr.push(0);
      continue;
    }

    freq = 1;
    while(num == arr.front()){
      freq++;
      arr.pop();
    }
    arr.push(freq);
    arr.push(num);
  }

  int temp;
  while(!arr.empty()){
    temp = arr.front();
    answer = answer + to_string(temp);
    arr.pop();
  }

  return answer;
}

int main(){

  int n;
  cin>>n;

  cout<<countAndSay(n)<<endl;

  return 0;
}
