/*****************************************************************************
经典的动态规划法，设置大小为dp[n][m]的二维数组，数组中的元素dp[i][j]代表以A[i]
和B[j]为结尾的字符之前最大的连续子序列长度，当遍历完成后取数组的中的最大值即为
我们需要的结果。时间复杂度为O（m*n）,空间复杂度为O（m*n）
******************************************************************************/
class LongestSubstring {
public:
    int findLongest(string A, int n, string B, int m)
    {
        // write code here
        if(n==0 || m == 0)
            return 0;
        vector<vector<int> > dp(n, vector<int>(m,0));
        for(int i = 0; i < n ; ++i)
        {
            if(A[i]==B[0])
                dp[i][0] = 1;
        }
        for(int j = 0; j < m; ++j)
        {
            if(B[j] == A[0])
                dp[0][j] = 1;
        }
        for(int i = 1; i < n; ++i)
            for(int j = 1; j < m; ++j)
        {
            if(A[i]==B[j])
                dp[i][j] = dp[i-1][j-1] + 1;
        }
        int cnt = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
        {
            if(dp[i][j]>cnt)
                cnt = dp[i][j];
        }
        return cnt;
    }
};
/*****************************************************************************
优化的动态规划法，时间复杂度为O（m*n）,空间复杂度为O（1）；
由上边的做法可以看出，连续的公共序列表现在dp[][]数组上是每一条右斜线，所以我们
以每条右斜线开始遍历每次只保存前一个用到的dp[i-1][j-1],并在每条斜线遍历完后，通过
全局的变量记录目前为止最大的公共序列长度。
******************************************************************************/
class LongestSubstring {
public:
    int findLongest(string A, int n, string B, int m) 
    {
        // write code here
        int m_Num = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
        {
            int k = i;
            int l = j;
            int maxlen = 0;
            while(k < n && l < m && A[k] == B[l])
            {
                k++;
                l++;
                maxlen++;
            }
            if(maxlen > m_Num)
                m_Num = maxlen;
        }
        return m_Num;
    }
};
