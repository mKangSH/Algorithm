#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

template<typename T, typename Container = vector<T>, typename Predicate = less<T>>
class PriorityQueue
{
public:
	void push(const T& data)
	{
		_heap.push_back(data);
		
		int now = _heap.size() - 1;

		while(now > 0)
		{
			int next = (now / 2) - ((now + 1) % 2);
			
			if (_predicate(_heap[now], _heap[next]))
			{
				break;
			}

			swap(_heap[now], _heap[next]);
			now = next;

		}
	}

	void pop()
	{
		_heap[0] = _heap.back();
		_heap.pop_back();

		int index = 0;

		while (true)
		{
			int left = 2 * index + 1;
			int right = 2 * index + 2;
			
			if (left >= _heap.size())
			{
				break;
			}

			int next = index;
			if (_predicate(_heap[next], _heap[left]))
			{
				next = left;
			}

			if (right < _heap.size() && _predicate(_heap[next], _heap[right]))
			{
				next = right;
			}

			if (next == index)
			{
				break;
			}
			
			swap(_heap[index], _heap[next]);
			index = next;
		}
	}

	T& top()
	{
		return _heap[0];
	}

	bool empty()
	{
		return _heap.empty();
	}

private:
	Container _heap = {};
	Predicate _predicate = {};
};

int main()
{
	// priority_queue<int, vector<int>, greater<int>> pq;
	
	PriorityQueue<int, vector<int>, greater<int>> pq;

	pq.push(100);
	pq.push(300);
	pq.push(200);
	pq.push(500);
	pq.push(400);

	while (pq.empty() == false)
	{
		int value = pq.top();
		pq.pop();

		cout << value << endl;
	}
}

/*
using namespace std;

using NodeRef = shared_ptr<struct Node>;

struct Node
{
	Node() {}
	Node(const string& data) : data(data) { }

	string			data;
	vector<NodeRef>	children;
};

NodeRef CreateTree()
{
	NodeRef root = make_shared<Node>("R1 개발실");
	{
		NodeRef node = make_shared<Node>("디자인팀");
		root->children.push_back(node);
		{
			NodeRef leaf = make_shared<Node>("전투");
			node->children.push_back(leaf);
			{
				NodeRef finalLeaf = make_shared<Node>("애니메이션");
				leaf->children.push_back(finalLeaf);
			}
		}

		{
			NodeRef leaf = make_shared<Node>("경제");
			node->children.push_back(leaf);
		}

		{
			NodeRef leaf = make_shared<Node>("스토리");
			node->children.push_back(leaf);
		}
	}

	{
		NodeRef node = make_shared<Node>("프로그래밍팀");
		root->children.push_back(node);
		{
			NodeRef leaf = make_shared<Node>("서버");
			node->children.push_back(leaf);
		}

		{
			NodeRef leaf = make_shared<Node>("클라이언트");
			node->children.push_back(leaf);
		}

		{
			NodeRef leaf = make_shared<Node>("엔진");
			node->children.push_back(leaf);
		}
	}

	{
		NodeRef node = make_shared<Node>("아트팀");
		root->children.push_back(node);
		{
			NodeRef leaf = make_shared<Node>("배경");
			node->children.push_back(leaf);
		}

		{
			NodeRef leaf = make_shared<Node>("캐릭터");
			node->children.push_back(leaf);
		}
	}

	return root;
}

void PrintTree(NodeRef root, int depth)
{
	for (int i = 0; i < depth; i++)
	{
		cout << " ";
	}

	cout << root->data << endl;

	for (NodeRef& child : root->children)
	{
		PrintTree(child, depth + 1);
	}
}

int GetHeight(NodeRef root)
{
	int height = 1;

	for (NodeRef& child : root->children)
	{
		height = max(height, GetHeight(child) + 1);
	}

	return height;
}

int main()
{
	NodeRef root = CreateTree();
	PrintTree(root, 0);

	cout << "Tree Height: " << GetHeight(root) << endl;
}
*/
