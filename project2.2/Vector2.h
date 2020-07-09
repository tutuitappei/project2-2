#pragma once
template<class T> class Vector2Temple
{
public:
	Vector2Temple();
	Vector2Temple(T x , T y);
	~Vector2Temple();

	T x;
	T y;

	//�P�����Z�q
	Vector2Temple& operator += (const Vector2Temple& vec);
	Vector2Temple& operator -= (const Vector2Temple& vec);
	Vector2Temple& operator *= (T k);
	Vector2Temple& operator /= (T k);
	Vector2Temple operator + ()const;
	Vector2Temple operator - ()const;
	//������Z�q
	Vector2Temple& operator = (const Vector2Temple& vec);
	//��r���Z�q
	bool operator == (const Vector2Temple& vec) const;
	bool operator != (const Vector2Temple& vec) const;
	bool operator <  (const Vector2Temple& vec) const;
	bool operator <= (const Vector2Temple& vec) const;
	//�Y�������Z�q
	T& operator[](int no);
private:
};

//Vector2 + int
template<class T>
Vector2Temple<T> operator + (const Vector2Temple<T>& u, T v);
//Vector2 - int
template<class T>
Vector2Temple<T> operator - (const Vector2Temple<T>& u, T v);
//Vector2 * int
template<class T>
Vector2Temple<T> operator * (const Vector2Temple<T>& u, T v);
//int * Vector2
template<class T>
Vector2Temple<T> operator * (T v, const Vector2Temple<T>& u);
//Vector2 / int
template<class T>
Vector2Temple<T> operator / (const Vector2Temple<T>& u, T v);
//Vector2 % int
template<class T>
Vector2Temple<T> operator % (const Vector2Temple<T>& u, T v);
//Vector2 + Vector2
template<class T>
Vector2Temple<T> operator + (const Vector2Temple<T>& u, const Vector2Temple<T>& v);
//Vector2 - Vector2
template<class T>
Vector2Temple<T> operator - (const Vector2Temple<T>& u, const Vector2Temple<T>& v);


using Vector2 = Vector2Temple<int>;
using Vector2Dbl = Vector2Temple<double>;
using Vector2Flt = Vector2Temple<float>;

#include"details/Vector2.h"
