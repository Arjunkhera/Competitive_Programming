#include <iostream>

using namespace std;

int main(){

  int delta=365;
  int total=365;
  float p=1;
  float prob;
  int answer=0;

  cin>>prob;
  prob = 1-prob;

  if(prob==0)
    answer = 366;
  else {
    while(p>=prob)
    {
        p=p*(delta/(1.0*total));
        delta--;
        answer++;
    }
  }
  cout<<answer;
  return 0;
}
