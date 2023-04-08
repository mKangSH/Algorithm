#include "pch.h"
#include "Player.h"
#include "Board.h"
#include <stack>

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;
	//RightHand();
	//BFS();
	AStar();
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
	{
		_board->GenerateMap();
		Init(_board);
		return;
	}

	_sumTick += deltaTick;
	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;

		_pos = _path[_pathIndex];
		_pathIndex++;
	}
}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);
	return (tileType == TileType::EMPTY);
}

void Player::RightHand()
{
	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);

	Pos dest = _board->GetExitPos();

	Pos goAhead[4] =
	{
		Pos {-1, 0},
		Pos {0, -1},
		Pos {1, 0},
		Pos {0, 1},
	};

	while (pos != dest)
	{
		int32 newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;

		if (CanGo(pos + goAhead[newDir]))
		{
			_dir = newDir;
			pos += goAhead[_dir];

			_path.push_back(pos);
		}

		else if (CanGo(pos + goAhead[_dir]))
		{
			pos += goAhead[_dir];
			_path.push_back(pos);
		}

		else
		{
			_dir = (_dir + 1) % DIR_COUNT;
		}
	}

	stack<Pos> s;

	for (int i = 0; i < _path.size() - 1; i++)
	{
		if (s.empty() == false && s.top() == _path[i + 1])
		{
			s.pop();
		}

		else
		{
			s.push(_path[i]);
		}
	}

	if (_path.empty() == false)
	{
		s.push(_path.back());
	}

	vector<Pos> path;
	path.reserve(s.size() + 1);
	while (s.empty() == false)
	{
		path.push_back(s.top());
		s.pop();
	}

	std::reverse(path.begin(), path.end());

	_path = path;
}

void Player::BFS()
{
	Pos pos = _pos;
	Pos dest = _board->GetExitPos();

	Pos goAhead[4] =
	{
		Pos {-1, 0},
		Pos {0, -1},
		Pos {1, 0},
		Pos {0, 1},
	};

	const int32 size = _board->GetSize();
	vector<vector<bool>> discovered(size, vector<bool>(size, false));

	// vector<vector<Pos>> parent;
	map<Pos, Pos> parent;

	queue<Pos> q;
	q.push(pos);
	discovered[pos.y][pos.x] = true;
	parent[pos] = pos;

	while (q.empty() == false)
	{
		pos = q.front();
		q.pop();

		if (pos == dest)
		{
			break;
		}

		for (int32 dir = 0; dir < 4; dir++)
		{
			Pos nextPos = pos + goAhead[dir];
			if (CanGo(nextPos) == false)
			{
				continue;
			}

			if (discovered[nextPos.y][nextPos.x])
			{
				continue;
			}

			q.push(nextPos);
			discovered[nextPos.y][nextPos.x] = true;
			parent[nextPos] = pos;
		}
	}

	_path.clear();

	pos = dest;
	while (true)
	{
		_path.push_back(pos);

		if (pos == parent[pos])
		{
			break;
		}

		pos = parent[pos];
	}

	std::reverse(_path.begin(), _path.end());
}

struct PQNode
{
	bool operator<(const PQNode& other) const { return f < other.f; }
	bool operator>(const PQNode& other) const { return f > other.f; }

	int32	f; // f = g + h
	int32	g;
	Pos		pos;
};

void Player::AStar()
{
	//
	// Final = G + H
	// Final : �������� ����
	// G : ���������� �ش� ��ǥ���� �̵��ϴµ� ��� ��� (�������� ����)
	// H(heuristic) : ���������� �󸶳� ������� (�������� ����)

	Pos start = _pos;
	Pos dest = _board->GetExitPos();

	enum
	{
		DIR_COUNT = 8,
	};

	Pos goAhead[] =
	{
		Pos {-1, 0},	// UP
		Pos {0, -1},	// LEFT
		Pos {1, 0},		// DOWN
		Pos {0, 1},		// RIGHT
		Pos {-1, -1},	// UP_LEFT
		Pos {1, -1},	// DOWN_LEFT
		Pos {1, 1},		// DOWN_RIGHT
		Pos {-1, 1},	// UP_RIGHT
	};

	int cost[] =
	{
		10, // UP
		10,	// LEFT
		10,	// DOWN
		10,	// RIGHT
		14,	// UP_LEFT
		14,	// DOWN_LEFT
		14,	// DOWN_RIGHT
		14	// UP_RIGHT
	};

	const int32 size = _board->GetSize();

	// ClosedList
	// closed[y][x] -> (y, x)�� �湮 �ߴ��� ����
	vector<vector<bool>> closed(size, vector<bool>(size, false));

	// best[y][x] -> (y, x)�� ���� ���� ���� ���
	vector<vector<int32>> best(size, vector<int32>(size, INT32_MAX));

	// �θ� ���� �뵵
	map<Pos, Pos> parent;

	// OpenList
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> pq;

	// TODO:
	// 1) ����(�߰�) �ý��� ����
	// - �̹� �� ���� ��θ� ã�Ҵٸ� ��ŵ
	// 2) �ڴʰ� �� ���� ��ΰ� �߰ߵ� �� ���� -> ���� ó�� �ʼ�
	// - openList���� ã�Ƽ� ����
	// - pq���� pop�� ���Ŀ� ����

	// Initial value
	{
		int32 g = 0;
		int32 h = 10 * (abs(dest.y - start.y) + abs(dest.x - start.x));
		pq.push(PQNode{ g + h, g, start });
		best[start.y][start.x] = g + h;
		parent[start] = start;
	}

	while (pq.empty() == false)
	{
		// ���� ���� �ĺ� ã��
		PQNode node = pq.top();
		pq.pop();

		if (closed[node.pos.y][node.pos.x])
		{
			continue;
		}

		// �湮
		closed[node.pos.y][node.pos.x] = true;

		if (node.pos == dest)
		{
			break;
		}

		for (int32 dir = 0; dir < DIR_COUNT; dir++)
		{
			Pos nextPos = node.pos + goAhead[dir];

			if (CanGo(nextPos) == false)
			{
				continue;
			}

			if (closed[nextPos.y][nextPos.x])
			{
				continue;
			}

			int32 g = node.g + cost[dir];
			int32 h = 10 * (abs(dest.y - nextPos.y) + abs(dest.x - nextPos.x));

			if (best[nextPos.y][nextPos.x] <= g + h)
			{
				continue;
			}

			best[nextPos.y][nextPos.x] = g + h;
			pq.push(PQNode{ g + h, g, nextPos });
			parent[nextPos] = node.pos;
		}
	}

	// �Ž��� �ö󰡴� �ڵ�
	Pos pos = dest;

	_path.clear();
	_pathIndex = 0;

	while (true)
	{
		_path.push_back(pos);

		if (pos == parent[pos])
		{
			break;
		}

		pos = parent[pos];
	}

	std::reverse(_path.begin(), _path.end());
}
