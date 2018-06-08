#include<iostrea>
#include<vector>
#include<string>

bool wordBreak(string s, vector<string>& wordDict) {

  
}

int main(){

  string str,word;
  cin>>str;

  int n;
  cin>>n;
  vector<string> dictionary(n);
  for(int i = 0;i < n;i++)
    cin>>dictionary[i];

  if(wordBreak(str,dictionary))
    cout<<"Match"<<endl;
  else cout<<"Mismatch"<<endl;

  return 0;
}
