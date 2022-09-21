#pragma once
#include<iostream>

using namespace std;

template<class T>
class Matrix
{
	T** mas;
	int str;
	int stolb;

public:
	Matrix();
	Matrix(int st, int stolb);
	//----
	Matrix(const Matrix<T>& obj);
	~Matrix();
	Matrix<T>& operator=(const Matrix<T>& obj);
	//-----
	void Random();
	void Print();
	//-----
	int getStr() const;
	int getStolb() const;
	T** getMas() const;
	//-----
	Matrix<T> operator+(int i);
	bool operator>(Matrix<T> obj);
	bool operator<(Matrix<T> obj);
};

template<class T>
Matrix<T>::Matrix()
{
	mas = nullptr;
	str = stolb = 0;
}

template<class T>
Matrix<T>::Matrix(int st, int stol)
{
	str = st;
	stolb = stol;
	mas = new T * [str];
	for (int i = 0; i < str; i++)
	{
		mas[i] = new T[stolb];
	}
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& obj)
{
	str = obj.str;
	stolb = obj.stolb;
	mas = new T * [str];
	for (int i = 0; i < str; i++)
	{
		mas[i] = new T[stolb];
	}
	// copy
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			mas[i][j] = obj.mas[i][j];
		}
	}
}
template<class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < str; i++)
	{
		delete[] mas[i];
	}
	delete[] mas;
}

template<class T>
void Matrix<T>::Random()
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			mas[i][j] = rand() % 100 * 1.6;
		}
	}
}

template<class T>
void Matrix<T>::Print()
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			cout << mas[i][j] << "\t";
		}
		cout << endl << endl;
	}
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& obj)
{
	if (this == &obj)
	{
		return *this;
	}
	if (mas != nullptr)
	{
		this->~Matrix();
	}

	//copy
	str = obj.str;
	stolb = obj.stolb;
	mas = new T * [str];
	for (int i = 0; i < str; i++)
	{
		mas[i] = new T[stolb];
	}
	// copy
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stolb; j++)
		{
			mas[i][j] = obj.mas[i][j];
		}
	}
	return *this;
}

template<class T>
int Matrix<T>::getStr() const
{
	return str;
}

template<class T>
int Matrix<T>::getStolb() const
{
	return stolb;
}

template<class T>
T** Matrix<T>::getMas() const
{
	return mas;
}

template<class T>
Matrix<T> Matrix<T>::operator+(int i)
{
	Matrix<T> temp = *this;

	for (int x = 0; x < temp.getStr(); x++)
		for (int y = 0; y < temp.getStolb(); y++)
			temp.getMas()[x][y] += i;

	return temp;
}

template<class T>
bool Matrix<T>::operator>(Matrix<T> obj)
{
	for (int i = 0; i < obj.getStr(); i++)
		for (int j = 0; j < obj.getStolb(); j++)
			if (!(this->getMas()[i][j] > obj.getMas()[i][j]))
				return false;

	return true;
}

template<class T>
inline bool Matrix<T>::operator<(Matrix<T> obj)
{
	for (int i = 0; i < obj.getStr(); i++)
		for (int j = 0; j < obj.getStolb(); j++)
			if (!(this->getMas()[i][j] < obj.getMas()[i][j]))
				return false;

	return true;
}

template<class T>
ostream& operator<< (ostream& out, const Matrix<T>& obj)
{
	for (int i = 0; i < obj.getStr(); i++)
	{
		for (int j = 0; j < obj.getStolb(); j++)
			out << obj.getMas()[i][j] << "\t";

		out << endl << endl;
	}

	return out;
}

template<class T>
Matrix<T> operator+ (int i, Matrix<T> obj)
{
	Matrix<T> temp = obj + i;
	return temp;
}