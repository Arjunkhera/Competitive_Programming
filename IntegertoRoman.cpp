#include<iostream>

using namespace std;

string intToRoman(int num){
  string arrfive[] = {"V","L","D","0"};
  string arrten[] = {"I","X","C","M"};
  int temp,digit;
  int level=0;
  string answer = "";

  while(num){
    digit = num%10;

    if(digit == 0){
       level++;
       num /= 10;
       continue;
    }
    else if(digit == 9)
      answer = arrten[level]+arrten[level+1]+answer;
    else if(digit == 5)
      answer = arrfive[level]+answer;
    else if(digit == 4)
      answer = arrten[level]+arrfive[level]+answer;
    else {
      temp = digit%5;
      while(temp){
        answer = arrten[level]+answer;
        temp--;
      }
      if(digit>5)
        answer = arrfive[level]+answer;
    }
    level++;
    num /= 10;
  }
  return answer;
}

int main(){
  int n;
  //cin>>n;

  //cout<<intToRoman(n)<<endl;

  for(int i=1;i<=15;i++)
    cout<<intToRoman(i)<<endl;

  return 0;
}
