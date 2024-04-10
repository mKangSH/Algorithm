#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum BoardType
{
	Black,
	White,

	Count
};

void Initialize(vector<vector<BoardType>> &board)
{
	string boardArgs;
	for (size_t i = 0; i < board.size(); i++)
	{
		cin >> boardArgs;
		for (size_t j = 0; j < board[i].size(); j++)
		{
			if (boardArgs[j] == 'B')
			{
				board[i][j] = BoardType::Black;
			}
			else
			{
				board[i][j] = BoardType::White;
			}
		}
	}
}

void ChangeState(BoardType& type)
{
	switch (type)
	{
	case BoardType::Black:
		type = BoardType::White;
		break;

	case BoardType::White:
		type = BoardType::Black;
		break;
	}
}

int CalculateRefillCountInBoard(vector<vector<BoardType>> board, int startRow, int startCol)
{
	const int subTileCount = 8;
	int minCount = subTileCount * subTileCount;

	for (int n = 0; n < BoardType::Count; n++)
	{
		BoardType startType = static_cast<BoardType>(n);

		int changeCount = 0;
		for (int y = startRow; y < startRow + subTileCount; y++)
		{
			for (int x = startCol; x < startCol + subTileCount; x++)
			{
				if (startType != board[y][x])
				{
					changeCount++;
				}
				ChangeState(startType);
			}
			ChangeState(startType);
		}

		minCount = min(minCount, changeCount);
	}

	return minCount;
}

int main()
{
	int rows, cols;
	cin >> rows >> cols;

	vector<vector<BoardType>> board(rows, vector<BoardType>(cols));
	Initialize(board);

	int minCount = rows * cols;
	for (int y = 0; y < rows - 8 + 1; y++)
	{
		for (int x = 0; x < cols - 8 + 1; x++)
		{
			minCount = min(minCount, CalculateRefillCountInBoard(board, y, x));
		}
	}

	cout << minCount;
}