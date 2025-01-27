class Solution {
public:

    int dest(vector<vector<int>>& a, int m, int n, int i, int j) {
        if (i >= m || j >= n)
            return 0;
        if (i == m-1 && j == n-1)
            return 1;
        if (a[i][j] > 0)
            return a[i][j];
            
        return a[i][j] = dest(a, m, n, i+1, j) + dest(a, m, n, i, j+1);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> a(m, vector<int>(n, 0));
        return dest(a, m, n, 0, 0);
    }
};