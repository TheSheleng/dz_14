#include "Point.h"

Point::Point() : Point(0, 0) {}

Point::Point(int x, int y)
{
	set(x, y);
}

void Point::set(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Point::set(int i)
{
	set(i, i);
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

Point& Point::operator=(int i)
{
	set(i);
	return *this;
}

Point& Point::operator+=(int i)
{
	x += i;
	y += i;

	return *this;
}

bool Point::operator>(const Point& point)
{
	if (x > point.getX() && y > point.getY()) 
		return true;
	else return false;
}

bool Point::operator<(const Point& point)
{
	if (x < point.getX() && y < point.getY()) return true;
	else return false;
}

ostream& operator<< (ostream& out, const Point& point)
{
	return out << point.getX() << ":" << point.getY();
}
