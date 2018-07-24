#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<int> maxset(vector<int> &arr){

    vector<int> answer;
    if(arr.empty()) return answer;

    long int maxsum = 0,length = 0,start = -1,temp = INT_MIN,templength = 0,st = 0,i = 0;

    while(i < arr.size()){
        if(arr[i] < 0){ temp = INT_MIN; i++; continue; }

        if(arr[i] > temp+arr[i]){ temp = arr[i]; st = i; templength = 1; }
        else { temp = arr[i]+temp; templength++; }

        if(temp > maxsum){ maxsum = temp; start = st; length = templength; }
        else if(temp == maxsum){ if(templength > length){ start = st; length = templength; } }
        i++;
    }

    for(long int j = start;j<start+length;j++) answer.push_back(arr[j]);

    return answer;
}

int main(){
  vector<int> arr;
  int temp; cin>>temp;
  while(temp != -1){ arr.push_back(temp); cin>>temp; }

  vector<int> answer = maxset(arr);
  for(auto i:answer) cout<<i<<" ";
  cout<<endl;

  return 0;
}
