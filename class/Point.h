#pragma once
#include<iostream>

using namespace std;

class Point
{
	int x;
	int y;

public:
	Point();
	Point(int x, int y);

	void set(int x, int y);
	void set(int i);
	int getX() const;
	int getY() const;

	Point& operator= (int i);
	Point& operator+= (int i);
	bool operator> (const Point& point);
	bool operator< (const Point& point);

	friend ostream& operator<< (ostream& out, const Point& point);
};
