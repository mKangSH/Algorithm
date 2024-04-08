#include <iostream>
using namespace std;

class Rectangle
{
public:
	Rectangle(int height, int width);
	int Size() { return width * height; }

private:
	int width;
	int height;
};

Rectangle::Rectangle(int height, int width)
	: width(width), height(height)
{

}

int main()
{
	int height, width;

	cin >> height >> width;

	Rectangle rect(height, width);
	cout << rect.Size();
}