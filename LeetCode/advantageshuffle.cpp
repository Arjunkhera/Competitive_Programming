#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<algorithm>

typedef long int li;
using namespace std;

bool mycomp(pair<int,int> &a,pair<int,int> &b){
  if(a.first < b.first) return false;
  return true;
}

vector<int> advantageCount(vector<int>& A, vector<int>& B) {
  int n = A.size();
  vector<int> answer(n,-1);

  vector<pair<int,int>> newB;
  for(int i = 0;i < n;i++) newB.emplace_back(B[i],i);
  sort(newB.begin(),newB.end(),mycomp);

  vector<int> newA(A);
  sort(newA.begin(),newA.end(),greater<int>());

  vector<int> useless;
  for(int i = n-1,j = n-1;i >= 0;i--){
    if(newB[j].first < newA[i]) { answer[newB[j].second] = newA[i]; j--;}
    else useless.push_back(newA[i]);
  }

  for(int i = 0,j = 0;i < n && j < useless.size();i++) if(answer[i] == -1) { answer[i] = useless[j]; j++; }
  return answer;
}

int main(){
  int temp;

  vector<int> a,b;
  cin>>temp;
  while(temp != -1){
    a.push_back(temp);
    cin>>temp;
  }

  cin>>temp;
  while(temp != -1){
    b.push_back(temp);
    cin>>temp;
  }

  vector<int> answer = advantageCount(a,b);
  for(auto i:answer) cout<<i<<" ";
  cout<<endl;

  return 0;
}

/*
2 7 11 15 -1
1 10 4 11 -1
------------
12 24 8 32 -1
13 25 32 11 -1
*/

/*
vector<int> advantageCount(vector<int>& A, vector<int>& B) {
  vector<int> answer(A.size());

  vector<pair<int,int>> oldB;
  for(int i = 0;i < B.size();i++) oldB.push_back(make_pair(B[i],i));
  sort(A.begin(),A.end(),greater<int>());
  vector<int> oldA(A);
  sort(oldB.begin(),oldB.end(),mycomp);

  int whichrotation = 0,temp = 0,maxans = 0,rotations = 0,n = A.size();
  while(rotations < n){
    temp = 0;
    for(int i = 0; i < n;i++) if(A[i] > oldB[i].first) temp++;
    if(temp > maxans){ maxans = temp; whichrotation = rotations; }

    temp = A[n-1];
    for(int i = n-1;i > 0;i--) A[i] = A[i-1];
    A[0] = temp;
    rotations++;
  }
  cout<<"max : "<<maxans<<" whichrotation : "<<whichrotation<<endl;

  int d = n - whichrotation;
  reverse(oldA.begin(),oldA.begin()+d);
  reverse(oldA.begin()+d+1,oldA.end());
  reverse(oldA.begin(),oldA.end());

  // for(auto k:oldA) cout<<k<<":"; cout<<endl;

  for(int i = 0;i < n;i++)  answer[oldB[i].second] = oldA[i];
  return answer;
}
*/
