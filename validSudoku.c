bool isValidSudoku(char **board, int boardSize, int *boardColSize)
{
	int rows_board[9][9] = {0};
	int cols_board[9][9] = {0};
	int blocks[3][3][9] = {0};
	
	int i = 0;
	char c;
	while (i < boardSize)
	{
		int j = 0;
		while (j < boardColSize[i])
		{
			c = board[i][j];
			if (c != '.')
			{
				if (rows_board[i][c - 49] == 0)
					rows_board[i][c - 49] = 1;
				else
					return false;
					
				if (cols_board[j][c - 49] == 0)
					cols_board[j][c - 49] = 1;
				else
					return false;
					
				int block_row = i / 3;
				int block_col = j / 3;
				if (blocks[block_row][block_col][c - 49] == 0)
					blocks[block_row][block_col][c - 49] = 1;
				else
					return false;
			}
			j++;
		}
		i++;
	}
	return true;
}
