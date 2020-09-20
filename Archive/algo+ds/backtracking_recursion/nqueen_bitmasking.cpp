#include<iostream>
#include<bitset>

using namespace std;

int ans = 0,DONE;

void solve(int rowMask,int ld,int rd,int i,int *board,const int n){

    if(rowMask==DONE){
      ans++;

    for(int i=0;i<n;i++)
      cout<<bitset<8>(board[i])<<"\n";

    cout<<"------------------\n";
    return;
    }

    int safe = DONE&(~(rowMask|ld|rd));
    while(safe){
        //p denotes the column
        int p = safe &(-safe);

        //Place the queen
        board[i] = board[i]|p;

        safe = safe - p;
        solve(rowMask|p, (ld|p)<<1, (rd|p)>>1,i+1,board,n);

        //Remove the queen - Backtrack
        board[i] = 0;
    }
}

int main()
{
    int n;
    cin>>n;
    int *board = new int[n];
    DONE = ((1<<n) - 1);
    solve(0,0,0,0,board,n);
    cout<<"Total count is : "<<ans<<endl;
}
