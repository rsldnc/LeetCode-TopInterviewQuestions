int minPathSum(int** grid, int gridSize, int* gridColSize)
{
    int** dp = (int**)malloc(gridSize * sizeof(int*));
    for (int i = 0; i < gridSize; ++i)
        dp[i] = (int*)malloc(gridColSize[i] * sizeof(int));
        
    dp[0][0] = grid[0][0];

    for (int i = 1; i < gridSize; ++i)
        dp[i][0] = dp[i - 1][0] + grid[i][0];

    for (int j = 1; j < gridColSize[0]; ++j)
        dp[0][j] = dp[0][j - 1] + grid[0][j];

    for (int i = 1; i < gridSize; ++i)
    {
        for (int j = 1; j < gridColSize[0]; ++j)
        {
            if (dp[i - 1][j] < dp[i][j - 1])
                dp[i][j] = dp[i - 1][j] + grid[i][j];
            else
                dp[i][j] = dp[i][j - 1] + grid[i][j];
        }
    }

    int result = dp[gridSize - 1][gridColSize[0] - 1];

    for (int i = 0; i < gridSize; ++i)
        free(dp[i]);
    free(dp);

    return result;
}