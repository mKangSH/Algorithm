#include <iostream>
#include <vector>
using namespace std;

typedef struct Point
{
	int x;
	int y;
};

void FillTilesWithRect(vector<vector<bool>>& tiles, Point startPoint)
{
	for (int y = startPoint.y - 1; y < startPoint.y + 9; y++)
	{
		for (int x = startPoint.x - 1; x < startPoint.x + 9; x++)
		{
			tiles[y][x] = true;
		}
	}
}

int main()
{
	vector<vector<bool>> tiles(100, vector<bool>(100, false));

	int fillCount;
	cin >> fillCount;

	for (int i = 0; i < fillCount; i++)
	{
		Point rectPoint;
		cin >> rectPoint.x >> rectPoint.y;
		FillTilesWithRect(tiles, rectPoint);
	}

	int totalArea = 0;
	for (int y = 0; y < tiles.size(); y++)
	{
		for (int x = 0; x < tiles.size(); x++)
		{
			if (tiles[y][x])
			{
				totalArea++;
			}
		}
	}

	cout << totalArea;

	return 0;
}