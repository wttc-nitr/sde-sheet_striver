/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
*/
#include "bits/stdc++.h"
using namespace std;

void maxSubArray(vector<int>& arr) {
    int sum = 0, best = -1e6, start = 0, end = 0;

    for (int i=0; i < arr.size(); i++) {
        // sum = max(sum + arr[i], arr[i]);
        if (sum + arr[i] < arr[i]) {
            start = i;
            sum = arr[i];
        }
        else sum = sum + arr[i];

        // best = max(best, sum);

        if (best < sum) {
            end = i;
            best = sum;
        }
    }

    cout << best << '\n';
    for (int i=start; i <= end; i++)
    	cout << arr[i] << ' ';
}

void solve(void) {
    vector<int> arr {-2,1,-3,4,-1,2,1,-5,4};

    maxSubArray(arr);
}

int main(void) {
     ios::sync_with_stdio(0); cin.tie(0);
    
    solve();

    return 0;
}