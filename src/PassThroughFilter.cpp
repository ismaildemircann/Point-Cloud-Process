/**
 * @file	: PassThroughFilter.cpp
 * @Author	: Onur Akkepenek (akkepenek38@gmail.com)
 * @date	: Aralik, 2019
 */
#include"PassThroughFilter.h"
#include<iostream>
#include"PointCloud.h"
#include"DepthCamera.h"
#include<list>
#include<iterator>
using namespace std;

PassThroughFilter::PassThroughFilter()
{
	upperLimitX = 0;
	lowerLimitX = 0;
	upperLimitY = 0;
	lowerLimitY = 0;
	upperLimitZ = 0;
	lowerLimitZ = 0;
}
PassThroughFilter::~PassThroughFilter()
{
}

void PassThroughFilter::setUpperLimitX(double upperLimitX)
{
	this->upperLimitX = upperLimitX;
}
double PassThroughFilter::getUpperLimitX()
{
	return upperLimitX;
}
void PassThroughFilter::setLowerLimitX(double LowerLimitX)
{
	this->lowerLimitX = LowerLimitX;
}
double PassThroughFilter::getLowerLimitX()
{
	return lowerLimitX;
}
void PassThroughFilter::setUpperLimitY(double upperLimitY)
{
	this->upperLimitY = upperLimitY;
}
double PassThroughFilter::getUpperLimitY()
{
	return upperLimitY;
}
void PassThroughFilter::setLowerLimitY(double LowerLimitY)
{
	this->lowerLimitY = LowerLimitY;
}
double PassThroughFilter::getLowerLimitY()
{
	return lowerLimitY;
}
void PassThroughFilter::setUpperLimitZ(double upperLimitZ)
{
	this->upperLimitZ = upperLimitZ;
}
double PassThroughFilter::getUpperLimitZ()
{
	return upperLimitZ;
}
void PassThroughFilter::setLowerLimitZ(double LowerLimitZ)
{
	this->lowerLimitZ = LowerLimitZ;
}
double PassThroughFilter::getLowerLimitZ()
{
	return lowerLimitZ;
}

void PassThroughFilter::filter(PointCloud& pc) {
	int counter = 0;
	list<Point> str1, str2;
	Point st;
	list<Point>::iterator iter1;
	str1 = pc.getPoints();

	for (iter1 = str1.begin(); iter1 != str1.end(); iter1++)
	{

		if (((*iter1).getPointx() <= getUpperLimitX() && (*iter1).getPointx() >= getLowerLimitX()) &&
			(((*iter1).getPointy() <= getUpperLimitY() && (*iter1).getPointy() >= getLowerLimitY())) &&
			((*iter1).getPointz() <= getUpperLimitZ() && (*iter1).getPointz() >= getLowerLimitZ()))
		{
			str2.push_back(*iter1);
			counter++;
		}
	}
	pc.setPoints(&str2);
	pc.setPointNumber(counter);
}