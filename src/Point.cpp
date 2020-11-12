/**
 * @file	: Point.cpp
 * @Author	: Onur Akkepenek (akkepenek38@gmail.com)
 * @date	: Aralik, 2019
 */
#include "Point.h"
#include <math.h>
Point::~Point()
{
}
void Point::setPointx(double x)
{
	this->x = x;
}
void Point::setPointy(double y)
{
	this->y = y;
}
void Point::setPointz(double z)
{
	this->z = z;
}
double const Point::getPointx()
{
	return x;
}
double const Point::getPointy()
{
	return y;
}
double const Point::getPointz()
{
	return z;
}
bool Point::operator==(const Point& A)const
{
	if (this->x == A.x && this->y == A.y && this->z == A.z)
		return true;
	else
		return false;
}
double const Point::distance(const Point& A)
{
	double distance;
	distance = sqrt(pow((A.x - this->x), 2) + pow((A.y - this->y), 2) + pow((A.z - this->z), 2));
	return distance;
}
