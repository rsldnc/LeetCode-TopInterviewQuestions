int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

bool isInterleave(char* s1, char* s2, char* s3)
{
    int len1 = ft_strlen(s1);
    int len2 = ft_strlen(s2);
    int len3 = ft_strlen(s3);

    if (len1 + len2 != len3)
        return false;

    bool dp[len1 + 1][len2 + 1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = true;

    for (int i = 1; i <= len1; i++)
        dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];

    for (int j = 1; j <= len2; j++)
        dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || 
                (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }

    return dp[len1][len2];
}
