#include<iostream>
#include<vector>

using namespace std;

vector<int> flip(string A){
    int bit,totalones = 0,temp = 0,maxdiff = 0;
    vector<int> answer(2,0),index(2,-1);

    for(int i = 0;i < A.size();i++){
        if(A[i] == 1) totalones++;

        if(A[i] == '1') bit = -1;
        else bit = 1;

        // answer stores the index of current subarray
        if(bit <= bit+temp){ answer[1] = i; temp = bit+temp; }
        else { answer[0] = i; answer[1] = i; temp = bit; }

        // check if we have initialized index or not
        if(temp == maxdiff && index[0] == -1){
          index[0] = answer[0];
          index[1] = answer[1];
        }
        else if(temp > maxdiff){ // update index if new maxdiff is larger
          maxdiff = temp;
          index[0] = answer[0];
          index[1] = answer[1];
        }
    }

    vector<int> useless;
    index[0]++; index[1]++;

    if(maxdiff <= 0) return useless;
    else return index;

}

int main(){
  string str;
  cin>>str;

  vector<int> answer = flip(str);
  for(auto i:answer) cout<<i<<" "; cout<<endl;

  return 0;
}
