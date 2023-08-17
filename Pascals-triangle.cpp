#include "bits/stdc++.h"
using namespace std;

/*
	this solution is just implementation-based.
	See notes for other variations and info.
*/

vector<int> createNextVector(vector<int> const&preV) {
    int N = preV.size();
    
    vector<int> newV(N+1);
    
    newV[0] = newV[N] = 1;
    
    for (int i=1; i < N; i++)
        newV[i] = preV[i-1] + preV[i];
    
    return newV;
}

vector<vector<int>> generate(int numRows) {
    vector< vector<int> > ans(numRows);
    
    ans[0] = {1};
    
    // row0, row1, row2 , .... , row(numRows-1)
    for (int row = 1; row < numRows; row++) {
        auto newV = createNextVector(ans[row-1]);
        
        ans[row].swap(newV);
    }
    
    return ans;
}
    
void solve(void) {
    
}

int main(void) {
     ios::sync_with_stdio(0); cin.tie(0);
     
    solve();

    return 0;
}