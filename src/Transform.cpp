/**
 * @file	: Transform.cpp
 * @Author	: Sina Kusoglu/152120171039/sinakusoglu@gmail.com
 * @date	: Aralik, 2019
 */
#include "Transform.h"
#include <math.h>
#include<iostream>
using namespace std;
Eigen::Matrix3d rotationMatrix1;

Transform::Transform()
{
}
Transform::~Transform()
{
}
void Transform::setAngles(double angle1,double angle2,double angle3)
{
	using namespace Eigen;
	angles1(0) = angle1;
	angles1(1) = angle2;
	angles1(2) = angle3;
}

void Transform::setTrans(double transx,double transy,double transz) 
{
	using namespace Eigen;
	trans1(0) = transx;
	trans1(1) = transy;
	trans1(2) = transz;
}
double *Transform::getAngles()
{
	double *angles = new double[3];
	for (int i = 0; i < 3; i++)
	{
		angles[i] = angles1(i);
	}
	return angles;
}
double *Transform::getTrans()
{
	double *trans = new double[3];
	for (int i = 0; i < 3; i++)
	{
		trans[i] = trans1(i);
	}
	return trans;
}
void Transform::setRotation(double ang[])
{
	rotationMatrix1(0, 0) = cos(ang[2])*cos(ang[1]);
	rotationMatrix1(0, 1) = (cos(ang[2])*sin(ang[1])*sin(ang[0])) - (sin(ang[2])*cos(ang[0]));
	rotationMatrix1(0, 2) = (cos(ang[2])*sin(ang[1])*cos(ang[0])) + (sin(ang[2])*sin(ang[0]));
	rotationMatrix1(1, 0) = sin(ang[2])*cos(ang[1]);
	rotationMatrix1(1, 1) = (sin(ang[2])*sin(ang[1])*sin(ang[0])) + (cos(ang[2])*cos(ang[0]));
	rotationMatrix1(1, 2) = (sin(ang[2])*sin(ang[1])*cos(ang[0])) - (cos(ang[2])*sin(ang[0]));
	rotationMatrix1(2, 0) = -sin(ang[1]);
	rotationMatrix1(2, 1) = cos(ang[1])*sin(ang[0]);
	rotationMatrix1(2, 2) = cos(ang[1])*cos(ang[0]);

}

void Transform::setRotation(Eigen::Vector3d ang)
{
	rotationMatrix1(0, 0) = cos(ang(2))*cos(ang(1));
	rotationMatrix1(0, 1) = (cos(ang(2))*sin(ang(1))*sin(ang(0))) - (sin(ang(2))*cos(ang(0)));
	rotationMatrix1(0, 2) = (cos(ang(2))*sin(ang(1))*cos(ang(0))) + (sin(ang(2))*sin(ang(0)));
	rotationMatrix1(1, 0) = sin(ang(2))*cos(ang(1));
	rotationMatrix1(1, 1) = (sin(ang(2))*sin(ang(1))*sin(ang(0))) + (cos(ang(2))*cos(ang(0)));
	rotationMatrix1(1, 2) = (sin(ang(2))*sin(ang(1))*cos(ang(0))) - (cos(ang(2))*sin(ang(0)));
	rotationMatrix1(2, 0) = -sin(ang(1));
	rotationMatrix1(2, 1) = cos(ang(1))*sin(ang(0));
	rotationMatrix1(2, 2) = cos(ang(1))*cos(ang(0));
}

void Transform::setTranslation(double tr[])
{
	using namespace Eigen;
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			this->transMatrix1(x, y) = rotationMatrix1(x, y);
		}
	}
	this->transMatrix1(3, 0) = 0;
	this->transMatrix1(3, 1) = 0;
	this->transMatrix1(3, 2) = 0;
	this->transMatrix1(3, 3) = 1;
	this->transMatrix1(0, 3) = tr[0];
	this->transMatrix1(1, 3) = tr[1];
	this->transMatrix1(2, 3) = tr[2];
}
void Transform::setTranslation(Eigen::Vector3d tr)
{
	using namespace Eigen;
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			this->transMatrix1(x, y) = rotationMatrix1(x, y);
		}
	}
	this->transMatrix1(3, 0) = 0;
	this->transMatrix1(3, 1) = 0;
	this->transMatrix1(3, 2) = 0;
	this->transMatrix1(3, 3) = 1;
	this->transMatrix1(0, 3) = tr(0);
	this->transMatrix1(1, 3) = tr(1);
	this->transMatrix1(2, 3) = tr(2);
}
Point Transform::doTransform(Point p)
{
	Point transformedpoint;
	double point[3];
	point[0] = p.getPointx();
	point[1] = p.getPointy();
	point[2] = p.getPointz();
	using namespace Eigen;
	Vector4d pointA, pointB;
	pointB(0) = point[0];
	pointB(1) = point[1];
	pointB(2) = point[2];
	pointB(3) = 1;
	pointA = transMatrix1 * pointB;

	transformedpoint.setPointx(pointA(0));
	transformedpoint.setPointy(pointA(1));
	transformedpoint.setPointz(pointA(2));
	return transformedpoint;
}
list<Point> Transform::doTransform(list<Point> lp)
{
	list<Point> transformedList;
	list<Point>::iterator iter;
	for (iter = lp.begin(); iter != lp.end(); iter++)
	{
		transformedList.push_back(doTransform(*iter));
	}
	return transformedList;
}

PointCloud Transform::doTransform(PointCloud pc)
{
	PointCloud transformedpc;
	{
		transformedpc.setPoints(&doTransform((pc.getPoints())));
	}

	return transformedpc;
}