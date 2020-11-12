#include<iostream>
#include"PassThroughFilter.h"
#include <string>
#include "DepthCamera.h"
#include <iterator>
#include <list>
using namespace std;

int main() {
	PassThroughFilter PTF;
	DepthCamera DC1, DC2;
	PointCloud PC1, PC2;
	string str1 = "camera1.txt", str2 = "camera2.txt";
	DC1.setfileName(str1);
	PC1 = DC1.capture();
	DC2.setfileName(str2);
	PC2 = DC2.capture();

	PTF.setUpperLimitX(400);
	PTF.setLowerLimitX(0);
	PTF.setUpperLimitY(400);
	PTF.setLowerLimitY(0);
	PTF.setUpperLimitZ(45);
	PTF.setLowerLimitZ(-45);
	PTF.filter(PC1);

	//Point* Point1 = new Point[PC1.getPointNumber()];
	list<Point> Point1, Point2;
	list<Point>::iterator iter1, iter2;
	Point1 = PC1.getPoints();
	cout << endl;
	iter1 = Point1.begin();
	cout << "Camera1:" << endl << endl;
	for (iter1 = Point1.begin(); iter1 != Point1.end(); iter1++)
		cout << (*iter1).getPointx() << " " << (*iter1).getPointy() << " " << (*iter1).getPointz() << endl;
	
	cout << "******************************************" << endl;
	PC2 = DC2.capture();

	PTF.setUpperLimitX(500);
	PTF.setLowerLimitX(0);
	PTF.setUpperLimitY(500);
	PTF.setLowerLimitY(0);
	PTF.setUpperLimitZ(45);
	PTF.setLowerLimitZ(-45);
	PTF.filter(PC2);

	//Point* Point2 = new Point[PC2.getPointNumber()];
	Point2 = PC2.getPoints();
	cout << endl;
	iter2 = Point2.begin();
	cout << "Camera2:" << endl << endl;
	for (iter2 = Point2.begin(); iter2 != Point2.end(); iter2++)
		cout << (*iter2).getPointx() << " " << (*iter2).getPointy() << " " << (*iter2).getPointz() << endl;

	system("pause");
}