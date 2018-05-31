#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findDuplicate_sorting(vector<int>& nums) {

  if(nums.empty())
    return 0;

  vector<int> arr(nums);
  sort(arr.begin(),arr.end());

  for(int i = 0;i < arr.size()-1 ;i++)
    if(arr[i] == arr[i+1])
      return arr[i];
}

int findDuplicate(vector<int>& nums) {
  // using cycle detection

  if(nums.empty())
    return 0;

  int slow = nums[0];
  int fast = nums[0];

  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  }while(slow != fast);

  int p1 = nums[0];
  int p2 = fast;

  while(p1 != p2){
    p1 = nums[p1];
    p2 = nums[p2];
  }

  return p1;
}


int main(){

  vector<int> arr;
  int temp;

  cin>>temp;
  while(temp != -1){
    arr.push_back(temp);
    cin>>temp;
  }

  cout<<findDuplicate(arr)<<endl;

  return 0;
}

/*
if(nums.empty())
        return 0;

    int nn = nums.size()-1;
    int n = sqrt(nn);

    int range = nn/n+1;
    vector<int> arr(range,0);
    vector<int> sums(range,0);

    for(int k=0;k<range-1;k++){
        int tempsum = 0;
        for(int j = k*n; j < (k+1)*n ;j++)
            tempsum += j;
        sums[k] = tempsum;
        //cout<<sums[k]<<endl;
    }

    for(int k = (range-1)*n; k<=nn;k++){
        sums[range-1] += k;
    }
    //cout<<sums[range-1]<<endl;


    int temp;

    //cout<<"--------\n";
    for(int i=0;i<nums.size();i++){

        temp = nums[i]/n;
        arr[temp] += nums[i];
        //cout<<temp<<"--"<<arr[temp]<<endl;

        if(arr[temp] > sums[temp]){
            //cout<<"range is "<<temp<<endl;
            return arr[temp] - sums[temp];
        }

    }
    return -1;
*/
