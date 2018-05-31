#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<numeric>  // for accumulate
#include<algorithm>

using namespace std;

// ------- a general template for containers --------------
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
// --------------------------------------------------------

// Non Manipulating Algorithms
void commonoperations(vi &arr){

  cout<<"Maximum element : "<<*max_element(all(arr))<<endl;
  cout<<"Minimum element : "<<*min_element(all(arr))<<endl;

  cout<<"The sum of elements is : "<<accumulate(all(arr),0)<<endl;
  sort(all(arr));
  reverse(all(arr));

  // display the contents
  tr(arr,i){
    cout<<*i<<" ";
  }
  cout<<endl;

  if(find(all(arr),9) != arr.end())
    cout<<"Element found"<<endl;

  cout<<"9 occurred "<<count(all(arr),9)<<" times"<<endl;

}

void binarysearch(vi &arr){

  // put the array back in ascending order
  reverse(all(arr));

  if(binary_search(all(arr),5))
    cout<<"Element present"<<endl;
  cout<<*(lower_bound(all(arr),5))<<endl;

}

// traversing permutations of an array
void permutation(){

  int arr[] = {1,2,3};
  vector<int> checkingout(arr,arr+3);

  do{

    for(auto i : checkingout)
      cout<<i<<" ";
    cout<<endl;

  }while(next_permutation(all(checkingout)));

  //
}

int main(){

  int temp;
  vi arr;

  // construct a vector
  srand((unsigned)time(0));
  for(int i = 0;i < 10; i++){
    temp = (rand()%10)+1;
    arr.pb(temp);
  }

  // display the contents
  tr(arr,i){
    cout<<*i<<" ";
  }
  cout<<endl;

  arr.push_back(5);
  // non Manipulating methods
  commonoperations(arr);

  // binary search types
  binarysearch(arr);

  return 0;
}
