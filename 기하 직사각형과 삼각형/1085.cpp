#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Point
{
	int x;
	int y;
}Point;

class Rectangle
{
public:
	Rectangle(int width, int height);
	int DistanceToSide(const Point& p);

private:
	int x;
	int y;
	int width;
	int height;
};

Rectangle::Rectangle(int width, int height)
	: width(width), height(height)
{
	this->x = 0;
	this->y = 0;
}

int Rectangle::DistanceToSide(const Point& p)
{
	int xMin, yMin;

	xMin = min(abs(p.x - x), abs(p.x - (width + x)));
	yMin = min(abs(p.y - y), abs(p.y - (height + y)));
	
	return min(xMin, yMin);
}

int main()
{
	Point playerPos;
	int width, height;

	cin >> playerPos.x >> playerPos.y >> width >> height;
	Rectangle rect(width, height);

	int distanceToSide = rect.DistanceToSide(playerPos);
	cout << distanceToSide;
}