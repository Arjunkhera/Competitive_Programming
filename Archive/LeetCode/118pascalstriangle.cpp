#include<iostream>
#include<vector>

using namespace std;

int binomialCoeff(int n, int k){
    int res = 1;
    if (k > n - k)
      k = n - k;

    for (int i = 0; i < k; ++i){
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

// taken from geeksforgeeks, just for a reference into binomialCoeff
void printPascal(int n){
    for (int line = 0; line < n; line++){
        for (int i = 0; i <= line; i++)
            printf("%d ",binomialCoeff(line, i));
        printf("\n");
    }
}

void efficientPascal(int n){

  for(int i = 1;i <= n;i++){
    int cur = 1;

    for(int j = 1;j <= i;j++){
      cout<<cur<<" ";
      cur = cur*(i-j)/j;
    }
    cout<<endl;
  }

}

vector<vector<int>> generate(int numRows) {

  vector< vector<int> > answer(numRows);

  if(numRows == 0)
    return answer;

  answer[0].push_back(1);
  if(numRows == 1)
    return answer;

  answer[1].push_back(1);
  answer[1].push_back(1);
  if(numRows == 2)
    return answer;

  for(int i = 2;i < numRows;i++){

    answer[i].push_back(answer[i-1][0]);
    int j = 0;
    while(j < answer[i-1].size()-1){
      answer[i].push_back(answer[i-1][j]+answer[i-1][j+1]);
      j++;
    }

    answer[i].push_back(answer[i-1][j]);
  }

  return answer;
}

int main(){

  int n;
  cin>>n;

  vector< vector<int> > answer = generate(n);

  for(int i=0;i<answer.size();i++){
    for(int j=0;j<answer[i].size();j++)
      cout<<answer[i][j]<<" ";
    cout<<endl;
  }

  efficientPascal(n);

  return 0;
}
