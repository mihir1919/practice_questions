for(int i=0;i<v.size();i++)
    {
        dp[i]=1;
        int m=0;
        for(int j=0;j<i;j++)
        {
            if(v[i]>v[j])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }   
        }
    }
    return dp[v.size()];