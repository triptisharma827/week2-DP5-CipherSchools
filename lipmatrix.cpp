#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m==0) return 0;
        int n = matrix[0].size();
        int max_len = -1;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i = 0;i<m;i++)
            for(int j = 0;j<n;j++)
                max_len = max(max_len,dfs(i,j,matrix,dp));

        return max_len;  
    }
    int dfs(int i,int j,vector<vector<int>>& matrix, vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
        int m = matrix.size();
        int n = matrix[0].size();
        int length = 1;
        for(auto dir:dirs)
        {
            int nextI = i+dir.first;
            int nextJ = j+dir.second;
            if(nextI<0 || nextI>=m || nextJ<0 || nextJ>=n) continue;
            if(matrix[nextI][nextJ] > matrix[i][j])
                length = max(length,1+dfs(nextI,nextJ,matrix,dp));
        }
        dp[i][j] = length;
        return dp[i][j];
        
    }
};