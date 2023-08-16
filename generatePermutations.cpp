#include "bits/stdc++.h"
using namespace std;

#define vi vector<int>

// DFS approach -> think in terms of DFS (with diagram)

void Permutation (vector<int> const& arr, vector<int> temp, vector<vector<int>> &ans, vector<bool> &vis) {
    int N = arr.size();
    
    if (temp.size() == N) {
        ans.push_back(temp);
        
        return;
    }
    
    // if there're duplicates or you want to generate lexicographically
    // int lastChosen = INT_MAX; 
    
    for (int i=0; i < N; i++) {
        if (vis[i])
            continue;
        
        // if there're duplicates or you want to generate lexicographically
        // if (lastChosen == arr[i])
        //     continue;
        
        // lastChosen = arr[i];
        
        temp.push_back(arr[i]);
        vis[i] = true;
        
        Permutation(arr, temp, ans, vis);
        
        temp.pop_back();
        vis[i] = false;
    }
}

void solve(void) {
	vector<int> arr {3, 2, 1};

	sort(arr.begin(), arr.end());

	vector<vi> ans;
	vector<bool> vis(arr.size());

    Permutation(arr, {}, ans, vis);

    for (auto vec : ans) {
    	for (auto i : vec)
    		cout << i << ' ';

    	cout << '\n';
    }
}

int main(void) {
     ios::sync_with_stdio(0); cin.tie(0);
     
    int test_cases = 1; 
    while (test_cases-- > 0) {
   	    solve();
    }

    return 0;
}