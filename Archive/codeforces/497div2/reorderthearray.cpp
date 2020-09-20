#include<iostream>
#include<vector>
#include<map>

typedef long int li;
using namespace std;

int main(){
  li cur,n,answer = 0,temp = 0;
  cin>>n;

  map<li,int> counts;
  for(li i = 0;i < n;i++) {
    cin>>temp;
    if(counts.find(temp) == counts.end()) counts[temp] = 1;
    else counts[temp]++;
  }

  auto i = counts.begin();
  cur = i->second; i++;
  while(i != counts.end()){
    if(cur < i->second){
      answer += cur;
      cur = i->second;
    }
    else {
      answer += i->second;
      cur = i->second + (cur-i->second);
    }
    i++;
  }
  cout<<answer;
  return 0;
}

/*
7
10 1 1 1 5 5 3
------------------
5
1 1 1 1 1
*/
