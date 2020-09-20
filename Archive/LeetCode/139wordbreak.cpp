#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

const int arrsize = 26;

struct trie{
    struct trie *children[arrsize];
    bool theend;
    trie(){
      theend = false;
      for(int i = 0; i < arrsize; i++)
        children[i] = nullptr;
    }
};

void insert(struct trie *root, string key){
    struct trie *cur = root;

    for(int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if (!cur->children[index])
            cur->children[index] = new trie;
        cur = cur->children[index];
    }

    cur->theend = true;
}

bool search(struct trie *root, string key){
    struct trie *cur = root;

    for (int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if (!cur->children[index])
            return false;

        cur = cur->children[index];
    }

    return (cur != nullptr && cur->theend);
}

bool recursive(string str, trie *root){
    int size = str.size();

    if (size == 0)
      return true;

    for (int i=1; i<=size; i++)
        if (search(root, str.substr(0, i)) && recursive(str.substr(i, size-i), root))
            return true;
    return false;
}

bool dpsecondtype(string s, unordered_set<string> &dict){

  // empty dictionary
  if(dict.size() == 0)
    return false;

  vector<bool> dp(s.size()+1,false);
  dp[0]=true;

  for(int i = 1;i <= s.size();i++){
    for(int j = i-1;j >= 0;j--){
      if(dp[j]){
        string word = s.substr(j,i-j);
        if(dict.find(word) != dict.end()){
            dp[i]=true;
            break; //next i
        }
      }
    }
  }

  return dp[s.size()];
}

// O(n^3)
bool dp(string str, vector<string>& wordDict){

  if(str.empty())
    return true;

  string temp;
  int n = str.size();
  vector<int> arr(n+1,0);

  for(int i = 1;i <= n;i++){
    if(arr[i] == 0)
      if(find(wordDict.begin(),wordDict.end(),str.substr(0,i)) != wordDict.end())
        arr[i] = 1;

    if(arr[i]){
      if(i == n)
        return true;

      for(int j = i+1;j <= n;j++){
        if(arr[j] == 0)
          if(find(wordDict.begin(),wordDict.end(),str.substr(j,j-i)) != wordDict.end())
            arr[j] = 1;
        if(j == n && arr[j] == 1)
          return true;
      }
    }
  }

  return false;
}

bool wordBreak(string s, vector<string>& wordDict){

  struct trie* root = new trie;
  for(int i = 0;i < wordDict.size();i++)
    insert(root,wordDict[i]);

  return recursive(s,root);
  //return dp(s,wordDict);
}

int main(){

  string str;
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
