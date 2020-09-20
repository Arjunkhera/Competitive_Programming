#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

// solution functions
bool lemonadeChange(vector<int>& bills){
  if(bills.empty()) return true;

  int change = 0,fives = 0,tens = 0,twenty = 0;
  for(int i = 0;i < bills.size();i++){
    if(bills[i] == 5) { fives++; continue; }
    if(bills[i] == 10){ tens++; if(!fives) return false; fives--; continue;}
    if(bills[i] == 20){
      twenty++;
      if(!fives) return false;
      if(tens) { tens--; fives --; } else if(fives < 3) return false; else fives -= 3;
    }
    //cout<<i<<"--"<<change<<"--"<<bills[i]<<"\n";
  }
  return true;
}

int main(){
  int n,temp;
  cin>>n;
  vector<int> arr(n,0);
  for(int i = 0;i < n;i++) cin>>arr[i];

  if(lemonadeChange(arr)) cout<<"Cool\n"; else cout<<"Oh no\n";

  return 0;
}
