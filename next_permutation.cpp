#include "bits/stdc++.h"
using namespace std;

/*
	arr = [1, 2, 5, 4, 3];
	
	permutations are sorted lexicographically, if we rearrange 5, 4, 3 howsoever, we won't get larger lexicographical arrangement.
	So, we need to choose first-left element of 5 , so that we can get a larger lexicographical arrangement.

	if we choose 2, then 2, 5, 4, 3 can have larger lexicographical arrangements. But we want just the next larger.
	
	what could be the next lexico-larger arrangement of 2,5,4,3 -> 3,_,_,_ -> now we have 5,4,2 -> we want the next larger ->

	-> what's min rearrangement of 5, 4, 2 -> it's 2,4,5

	So, next lexico-larger arrangement of 2,5,4,3 is 3,2,4,5
	and so Next Permutation of 1,2,5,4,3 is 1, 3,2,4,5.
*/

void nextPermutation(vector<int>& nums) {
    int N = nums.size();
    
    int k = -1;
    
    for (int i=N-1; i >= 1; i--) {
        if (nums[i] > nums[i-1]) {
            k = i-1;
            break;
        }
    }
    
    if (k == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }
    
    int l = -1;
    
    for (int i=N-1; i > k; i--) {
        if (nums[i] > nums[k]) {
            l = i;
            break;
        }    
    }
    
    swap(nums[k], nums[l]);
    
    reverse(nums.begin() + k + 1, nums.end());
}

void solve(void) {
    vector<int> arr{1, 2, 5, 4, 3};

    nextPermutation(arr);

    for (auto i : arr) cout << i << ' ';
}

int main(void) {
     ios::sync_with_stdio(0); cin.tie(0);
     
    solve();

    return 0;
}