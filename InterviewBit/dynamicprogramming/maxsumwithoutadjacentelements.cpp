int Solution::adjacent(vector<vector<int> > &A) {

    int including = max(A[0][0],A[1][0]);
    int excluding = 0;
    int temp;

    for(int i = 1;i < A[0].size();i++){

        temp = max(including,excluding);
        including = excluding + max(A[0][i],A[1][i]);
        excluding = temp;
    }

    return max(including,excluding);
}
