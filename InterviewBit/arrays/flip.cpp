vector<int> Solution::flip(string A) {

    int totalones = 0;
    int temp = 0;
    int maxdiff = 0;
    int bit;
    vector<int> answer(2,0);
    vector<int> index(2,-1);

    for(int i = 0;i < A.size();i++){

        if(A[i] == 1)
            totalones++;

        if(A[i] == '1')
            bit = -1;
        else bit = 1;

        if(bit <= bit+temp){
            answer[1] = i;
            temp = bit+temp;
        }
        else {
            answer[0] = i;
            answer[1] = i;
            temp = bit;
        }

        if(temp == maxdiff && index[0] == -1){
            index[0] = answer[0];
            index[1] = answer[1];
        }
        else if(temp > maxdiff){
            maxdiff = temp;
            index[0] = answer[0];
            index[1] = answer[1];
        }

        //cout<<temp<<"--"<<answer[0]<<"--"<<answer[1]<<endl;

    }

    vector<int> useless;
    index[0]++;
    index[1]++;

    if(maxdiff <= 0)
        return useless;
    else return index;

}
