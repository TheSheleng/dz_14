#include "Matrix.h"
#include "Point.h"

#include <iostream>

using namespace std;

int main()
{
	Matrix<Point> a(5, 5);
	a.Random();
	//a.Print();

	cout << a << endl;

	Matrix<Point> sum = a + 3;

	cout << endl << endl;
	cout << sum << endl;

	Matrix<Point> sum2 = 3 + sum;

	cout << endl << endl;
	cout << sum2 << endl;

	if (sum > sum2)
	{
		cout << "sum > sum2\n";
	}
}