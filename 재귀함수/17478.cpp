#include <iostream>
using namespace std;

int cnt = 0;
string head;

void recursive(int n)
{
	head = "";
	for (int i = 0; i < cnt; ++i)
	{
		head += "____";
	}

	if (n == 0)
	{
		cout << head << "\"����Լ��� ������?\"\n";
		cout << head << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		cout << head << "��� �亯�Ͽ���.\n";
	}

	else
	{
		++cnt;
		cout << head << "\"����Լ��� ������?\"\n";
		cout << head << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		cout << head << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		cout << head << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
		recursive(n - 1);

		head = "";
		for (int i = 0; i < cnt - 1; ++i)
		{
			head += "____";
		}
		cout << head << "��� �亯�Ͽ���.\n";

		--cnt;
	}
}

int main()
{
	int N;
	cin >> N;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";

	recursive(N);

	return 0;
}