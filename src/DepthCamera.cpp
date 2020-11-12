/**
* DepthCamera.cpp
*/
#include "DepthCamera.h"
#include "Point.h"
#include "PointCloud.h"
#include <fstream>
#include <iostream>
#include <string>
#include "PointCloudGenerator.h"
#include "PassThroughFilter.h"
#include "RadiusOutlierFilter.h"
#include "Transform.h"
using namespace std;
DepthCamera::DepthCamera()
{
}
DepthCamera::~DepthCamera()
{
}
/*!
* \param radius: bir string dosya ismi.
*/
void DepthCamera::setfileName(string fileName) {
	this->fileName = fileName;
}
string DepthCamera::getfileName() {
	return fileName;
}
PointCloud DepthCamera::capture() {
	ifstream dataFile;
	list<Point> A;
	PointCloud PC;
	dataFile.open(this->getfileName(), ios::in);
	if (!dataFile)
	{
		cout << "Dosya Acilmadi.";
	}
	else
	{	
		double x, y, z;
		Point m;
		while (!dataFile.eof())
		{
			dataFile >> x;
			m.setPointx(x);
			dataFile >> y;
			m.setPointy(y);
			dataFile >> z;
			m.setPointz(z);
			A.push_back(m);
		}
		dataFile.close();
		PC.setPoints(&A);
	}
	return PC;
}

PointCloud DepthCamera::captureFor()
{

	PointCloud PC;
	PC = this->capture();
	PassThroughFilter PTF;
	RadiusOutlierFilter ROF;
	FilterPipe fp;
	Transform T;
	ROF.setRadiusOutlierFilter(25);

	fp.addFilter(&ROF);
	fp.addFilter(&PTF);
	if (this->getfileName() == "camera1.txt") {

		PTF.setUpperLimitX(400);
		PTF.setLowerLimitX(0);
		PTF.setUpperLimitY(400);
		PTF.setLowerLimitY(0);
		PTF.setUpperLimitZ(45);
		PTF.setLowerLimitZ(-45);
		fp.filterOut(PC);
		T.setAngles(0, 0, -90);
		T.setTrans(100, 500, 50);
		T.setRotation(T.getAngles());
		T.setTranslation(T.getTrans());

	}
	else
	{
		PTF.setUpperLimitX(500);
		PTF.setLowerLimitX(0);
		PTF.setUpperLimitY(500);
		PTF.setLowerLimitY(0);
		PTF.setUpperLimitZ(45);
		PTF.setLowerLimitZ(-45);
		fp.filterOut(PC);
		T.setAngles(0, 0, 90);
		T.setTrans(550, 150, 50);
		T.setRotation(T.getAngles());
		T.setTranslation(T.getTrans());
	}
	PC = T.doTransform(PC);
	return PC;
}
