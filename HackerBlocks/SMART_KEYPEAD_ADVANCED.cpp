#include<iostream>
#include<string>

using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

void calculate(char *str,char *temp,int index,int last){

  if(str[index] == '\0'){
    temp[last] = '\0';
    string pattern(temp);
    size_t pos;
    for(int i=0;i<11;i++){
      pos = searchIn[i].find(pattern);

      if(pos != string::npos)
        cout<<searchIn[i]<<"\n";
    }
    return;
  }

  int num = str[index] - '0';
  for(int i=0;i<table[num].length();i++){
      temp[last] = table[num][i];
      calculate(str,temp,index+1,last+1);
  }

}

int main(){
  char str[30],temp[30];
  scanf("%s",str);
  calculate(str,temp,0,0);

  return 0;
}
