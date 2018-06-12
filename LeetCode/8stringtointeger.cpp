#include<iostream>
#include<vector>
#include<string>
#include<climits>

using namespace std;

// from interviewbit : if long int is not allowed
int atoi(const string &str) {
            int sign = 1, base = 0, i = 0;
            while (str[i] == ' ') { i++; }
            if (str[i] == '-' || str[i] == '+') {
                sign = (str[i++] == '-') ? -1 : 1;
            }
            while (str[i] >= '0' && str[i] <= '9') {
                if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                    if (sign == 1) return INT_MAX;
                    else return INT_MIN;
                }
                base  = 10 * base + (str[i++] - '0');
            }
            return base * sign;
}

// from discussion : compact solution
int fromdiscussion(string str){

  const int length = str.size();
  int64_t res = 0;
  int i = 0, flag = 1;
  i = str.find_first_not_of(' ');
  if(str[i] == '-' || str[i] == '+')
    flag = (str[i++] == '-') ? -1 : 1;
  while(i < length && str[i] >= '0' && str[i] <='9'){
    res = res * 10 + str[i++] - '0';
    if(flag * res <= INT_MIN)
      return INT_MIN;
    if(flag * res >= INT_MAX)
      return INT_MAX;
  }

  return flag*res;
}

int myAtoi(string str){
  if(str.empty())
    return 0;

  long long int answer = 0;
  int length = 0,sign = 1,i = 0;
  // remove leading whitespaces
  while(str[i] == ' ')
    i++;
  // check for any other characters
  if(str[i] != '-' && str[i] != '+' && (str[i] < 48 || str[i] > 57))
    return 0;
  // accept a sign symbol if present
  if(str[i] == '-'){
    sign = -1;
    i++;
  }
  else if(str[i] == '+')
    i++;
  // remove leading zeros
  while(str[i] == 48)
    i++;
  // accept the numbers
  while(str[i] >= 48 && str[i] <= 57 ){
    length++;
    answer = 10*answer + (str[i]-48);
    i++;
    // to prevent overflow
    if(length > 10){
      if(sign > 0)
        return INT_MAX;
      else return INT_MIN;
    }
  }
  // assign the correct sign to the number
  if(sign < 0)
    answer = answer*sign;
  // for case of overflow or underflow
  if(answer < INT_MIN)
    return INT_MIN;
  if(answer > INT_MAX)
    return INT_MAX;
  // for case of +-+ etc, answer will remain zero
  return answer;
}

int main(){
  string str;
  getline(cin,str);

  cout<<myAtoi(str)<<endl;
  cout<<fromdiscussion(str)<<endl;

  return 0;
}
