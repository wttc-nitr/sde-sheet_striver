#include "bits/stdc++.h"
using namespace std;
#define ll long long

/*
- Important note
use brackets like this -> (arr[i] & (1 << index)) == 0

arr[i] & (1 << index) == 0 -> this will give a different result.
*/

int getSetIndex (int x) {
    int temp = 1, index = -1;
    
    for (int i=0; (1 << i) <= x; i++) {
        if (x & (1 << i)) {
            index = i;
            break;
        }
    }    
    
    assert(index != -1);
    
    return index;
}
/*
if we take Xor of 1 to N and given array elements, we'll get Xor of the missing and repeating number.

Now, divide the numbers (1 to N and array elements) in two groups based on if any bit (let's say least-significant-bit) is set in Xor.

missing and the repeating will fall under different groups.

Now, the xor of one group will be the repeating number and of other group will be the missing number (

because, other numbers will fall two times in their respective groups) -> use pen-paper with a example -> [1, 2, 3, 4, 3]
*/

vector<int> repeatedNumber_Second_Approach(const vector<int> &arr) {
    int Xor = 0, N = arr.size();
    
    for (int i=0; i < N; i++) 
        Xor ^= (i+1) ^ arr[i];
    
    int index = getSetIndex(Xor); 
    
    int groupA = 0, groupB = 0;
    
    for (int i=0; i < N; i++) {
        if ((arr[i] & (1 << index)) == 0)
            groupA ^= arr[i];
        else groupB ^= arr[i];
        
        if (((i+1) & (1 << index)) == 0)
            groupA ^= (i+1);
        else groupB ^= (i+1);
    }
    
    int x = groupA, y = groupB;
    
    for (int i=0; i < N; i++) {
        if (x == arr[i]) {
            return {x, y};
        }
    }
    
    return {y, x};
}

/*
mathematical approach:
	let's say x is repeating and y is missing, then
	difference of Sum(1 to N) - Sum( array elements) =  y-x

	difference of Sum( of squares 1 to N) - Sum( of squares of array elements) = y^2 - x^2.

	Now, we've two equations and two variables -> solvable
*/

vector<int> repeatedNumber_First_approach(const vector<int> &arr) {
	int N = arr.size();
    long long Sn = 1LL * N * (N+1) / 2, Sq_n = 1LL * N * (N+1) * (2*N + 1) / 6;

    long long Sarr = 0, Sq_arr = 0;

    for (int i=0; i < N; i++) {
    	Sarr += arr[i];

    	Sq_arr += 1LL * arr[i] * arr[i];
    }

    long long a = Sn - Sarr, b = Sq_n - Sq_arr;

    long long x = (b - a * a) / (2 * a);

    return {(int)x, (int)(x + a)};
}

void solve(void) {
	vector<int> arr{1, 2, 3, 3, 5};
    auto v = repeatedNumber_Second_Approach(arr);

    cout << v[0] << ' ' << v[1];
}

int main(void) {
     ios::sync_with_stdio(0); cin.tie(0);
     
   	solve();

    return 0;
}