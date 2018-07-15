#include<iostream>
#include<vector>
#include<stack>

#define modulo 1000000007
typedef long long int li;
using namespace std;

// solution function
int solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
    if(n == 0 || n == 1) return 0;

    int answer = 0;
    int curx = A[0];
    int cury = B[0];
    int deltax,deltay;

    for(int i = 1;i < n;i++){
        deltax = abs(curx-A[i]);
        deltay = abs(cury-B[i]);
        answer += max(deltax,deltay);

        curx = A[i]; cury = B[i];
    }
    return answer;
}

// driver function
int main(){
  vector<int> arrx,arry;
  int temp;
  cin>>temp;
  while(temp != -1){ arrx.push_back(temp); cin>>temp; }

  cin>>temp;
  while(temp != -1){ arry.push_back(temp); cin>>temp; }

  cout<<solve(arrx,arry)<<endl;
  return 0;
}

/*
6 5 4 9 9 6 5 4 5 9 9 -1
*/
