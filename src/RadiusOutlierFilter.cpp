/**
* RadiusOutlierFilter.cpp
*/
#include "RadiusOutlierFilter.h"
#include "DepthCamera.h"
#include <iostream>
#include <list>
#include <iterator>
using namespace std;
RadiusOutlierFilter::RadiusOutlierFilter()
{
	radius = 0;
}
RadiusOutlierFilter::~RadiusOutlierFilter(void)
{
}
/*!
* \param radius: bir double yaricap degeri.
*/
void RadiusOutlierFilter::setRadiusOutlierFilter(double radius)
{
	this->radius = radius;
}
double RadiusOutlierFilter::getRadiusOutlierFilter()
{
	return radius;
}
/*!
* \param PointCloud: bir PointCloud nesnesi.
*/
void RadiusOutlierFilter::filter(PointCloud & pc)
{
	list<Point> P, T;
	list<Point>::iterator iter1, iter2;
	Point st;
	P = pc.getPoints();
	int i = 0, j = 0;
	for (iter1 = P.begin(); iter1 != P.end(); iter1++)
	{
		for (iter2 = P.begin(); iter2 != P.end(); iter2++)
		{
			if ((*iter1).distance(*iter2) < getRadiusOutlierFilter() && iter1 != iter2)
			{
				T.push_back(*iter1);
				break;
			}
		}
	}
	pc.setPoints(&T);
}