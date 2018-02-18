#include <iostream>
#include <vector>

int catalan(int n){
  long long int numerator = 1;
  long long int denominator = 1;

  for(long long int i=1;i<=n;i++)
    denominator *= i;

  for(long long int i=n+2;i<=2*n;i++)
    numerator *= i;

  return (numerator/denominator);
}

// solution function
int numTrees(int n){

  int* arr = new int[n+1];
  // base cases
  arr[0]=1;
  arr[1]=1;

  // bottom up dp
  int temp;
  for(int i=2;i<=n;i++){
    temp = 0;
    for(int k=0;k<(i/2);k++){
      temp += 2*(arr[k]*arr[i-k-1]);
    }
    if((i-1)%2 == 0)
      temp += arr[i/2]*arr[i/2];
    arr[i] = temp;
  }

  return arr[n];
}

int main(){

  int n,c;
  std::cin>>n;

  c = catalan(n);
  n = numTrees(n);
  std::cout<<"The answer is :"<<n<<"\n";
  std::cout<<"The answer is :"<<c<<"\n";

  return 0;
}
