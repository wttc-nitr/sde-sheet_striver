#include "bits/stdc++.h"
using namespace std;

/*
    somewhat better solution is:
    use two auxillary arrays to store the location of zeroes (one for rows and other for column);
    SC -> O(N);

    Below solution is O(1) space.
*/

void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    
    int col0 = 1;
    
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            if (matrix[i][j] == 0) {
                if (j == 0)
                    col0 = 0;
                else matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    
    for (int j=1; j < m; j++) {
        if (matrix[0][j] == 0) {
            for (int i=1; i < n; i++)
                matrix[i][j] = 0;
        }
    }
    
    for (int i=0; i < n; i++) {
        if (matrix[i][0] == 0) {
            for (int j=1; j < m; j++)
                matrix[i][j] = 0;
        }
    }
    
    if (col0 == 0) {
        for (int i=0; i < n; i++)
            matrix[i][0] = 0;
    }
}

void solve(void) {
    
}

int main(void) {
     ios::sync_with_stdio(0); cin.tie(0);
     
    solve();

    return 0;
}