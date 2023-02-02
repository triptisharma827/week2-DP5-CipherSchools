#include <bits/stdc++.h>
using namespace std;
int memo[1005][1005];
int knapSack(int C, int wt[], int val[], int n)
{
    if (n == 0 || C == 0)
        return 0;

    if (memo[C][n] != -1)
        return memo[C][n];

    if (wt[n - 1] > C) // We can’t include the nth item
    {
        return memo[C][n] = knapSack(C, wt, val, n - 1);
    }

    int op1 = val[n - 1] + knapSack(C - wt[n - 1], wt, val, n - 1); // Include nth item (at n-1 index)
    int op2 = knapSack(C, wt, val, n - 1);// Don’t Include

    return memo[C][n] = max(op1, op2);
}
int main()
{
    memset(memo, -1, sizeof memo);

    int val[] = {10, 20, 10, 20};
    int wt[] = {2, 1, 2, 2};
    int C = 3;
    int n = sizeof(val) / sizeof(val[0]);

    cout << knapSack(C, wt, val, n) << endl;
    return 0;
}