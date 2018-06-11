#include<iostream>
#include<string>
#include<vector>

using namespace std;

string intToRoman(int num){

  string answer = "";
  vector<string> units = {"I","II","III","IV","V","VI","VII","VIII","IX"};
  vector<string> fives = {"V","L","D"};
  vector<string> tens = {"X","C","M"};

  int level = 0;
  int digit = num%10;
  num = num/10;

  // for units digit
  if(digit)
    answer = units[digit-1] + answer;

  // for the remaining digits
  while(num){
    digit = num%10;

    if(digit == 9)
      answer = tens[level] + tens[level+1] + answer;
    else if(digit == 4)
      answer = tens[level] + fives[level+1] + answer;
    else if(digit == 5)
      answer = fives[level+1] + answer;
    else {
      for(int i = 0;i < (digit%5);i++)
        answer = tens[level] + answer;
      if(digit/5)
        answer = fives[level+1] + answer;
    }

    level += 1;
    num /= 10;
  }

  return answer;
}

int main(){

  int n;
  cin>>n;

  string answer = intToRoman(n);
  cout<<answer<<endl;

  return 0;
}
