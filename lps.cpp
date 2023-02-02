#include <bits/stdc++.h>
using namespace std;
int f(string s)
{
    int n = s.length();
    bool dp[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = false;

    int ans = 1;

    for (int i = 0; i < n; i++)
        dp[i][i] = true;

    for (int length = 2; length <= n; length++)
    {
        for (int i = 0; i <= n - length; i++)
        {
            int j = i + length - 1;
            if (length == 2) 
            {
                if (s[i] == s[j])
                    dp[i][j] = true;
            }
            else
            {   
                
                if (s[i] == s[j] && dp[i + 1][j - 1])
                    dp[i][j] = true;
            }

            if (dp[i][j])
                ans = max(ans, length);
        }
    }

    return ans;
}
int main()
{
    string s;
    cin >> s;

    cout << f(s) << endl;
    return 0;
}