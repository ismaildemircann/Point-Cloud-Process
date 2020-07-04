/**
* @file		: PointCloud.cpp
* @Author	: Ismail Demircan /152120171029/ismaildemircann98@gmail.com
* @date		: December 2019
*/
#include "PointCloud.h"
#include <iostream>
#include <list>
#include <iterator>

PointCloud::PointCloud()
{
	pointNumber = 0;
}
/*!
* \param pointNumber: kac adet nokta oldugunu iceren degisken.
*/
void PointCloud::setPointNumber(int pointNumber)
{
	this->pointNumber = pointNumber;
}
int PointCloud::getPointNumber()
{
	return pointNumber;
}
/*!
* \param p: Nokta bulutuna atanacak nokta degiskeni.
*/
void PointCloud::setPoints(list<Point> * p) {

	this->points = *p;
}
list<Point> PointCloud::getPoints() {
	return points;
}
/*!
* \param &A: PointCloud tipinde toplanacak bir nokta bulutu degiskeni.
*/
PointCloud PointCloud::operator+(PointCloud& A)
{
	list<Point> K1, K2, tmp;
	list<Point>::iterator iter1, iter2;
	PointCloud C;
	K1 = this->getPoints();
	K2 = A.getPoints();
	int j = 0;
	iter1 = K1.begin();
	iter2 = K2.begin();
	int a = K1.size();
	for (int i = 0; i < K1.size()+K2.size(); i++) {
		if (i < K1.size())
		{
			tmp.push_back(*iter1++);
		}
		else
		{
			tmp.push_back(*iter2++);
		}
	}
	C.setPointNumber(K1.size() + K2.size());
	C.setPoints(&tmp);
	return C;
}
/*!
* \param pcA: PointCloud tipinde atanacak degerleri iceren nokta bulutu.
*/
void PointCloud::operator=(PointCloud* Pc)
{
	list<Point>::iterator iter;
	for (iter = Pc->points.begin(); iter != Pc->points.end(); iter++)
	{
		this->points.push_back(*iter);
	}
}
PointCloud::~PointCloud()
{
}