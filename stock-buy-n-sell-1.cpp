#include "bits/stdc++.h"
using namespace std;

int maxProfit(vector<int>& prices) {
    // i, j => i < j && arr[j] - arr[i] is max
    
    // if at current element, what should be subtracted to get max difference?
    // -> the minimum till now
    
    int mini = prices[0], n = prices.size(), ans = 0;
    
    for (int i=0; i < n; i++) {
        ans = max(ans, prices[i] - mini);
        
        mini = min(mini, prices[i]);
    }
    
    return ans;
}

void solve(void) {
    vector<int> prices{7,1,5,3,6,4};

	cout << maxProfit(prices);
}

int main(void) {
     ios::sync_with_stdio(0); cin.tie(0);
     
    solve();

    return 0;
}