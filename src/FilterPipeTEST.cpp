/**
 * @file	:FilterPipeTEST.cpp
 * @brief	: bu fonksiyon FilterPipe sinifinin dogru calisip calismadigini kontrol eder.
 */
#include"Point.h"
#include"PointCloud.h"
#include"DepthCamera.h"
#include"PassThroughFilter.h"
#include"PointCloudRecorder.h"
#include"RadiusOutlierFilter.h"
#include<iostream>
#include<list>
using namespace std;
int main() {
	int size1, size2;
	PointCloud PC1, PC2, PC3;
	DepthCamera DC;
	PassThroughFilter PTF;
	RadiusOutlierFilter ROF;
	PointCloudRecorder PCR;
	string str1 = "camera1.txt", str2 = "camera2.txt";

	DC.setfileName(str1);
	PC1 = DC.capture();
	DC.setfileName(str2);
	PC2 = DC.capture();
	ROF.setRadiusOutlierFilter(25);

	FilterPipe fp;
	fp.addFilter(&ROF);
	fp.addFilter(&PTF);


	PTF.setUpperLimitX(400);
	PTF.setLowerLimitX(0);
	PTF.setUpperLimitY(400);
	PTF.setLowerLimitY(0);
	PTF.setUpperLimitZ(45);
	PTF.setLowerLimitZ(-45);

	fp.filterOut(PC1);

	PTF.setUpperLimitX(500);
	PTF.setLowerLimitX(0);
	PTF.setUpperLimitY(500);
	PTF.setLowerLimitY(0);
	PTF.setUpperLimitZ(45);
	PTF.setLowerLimitZ(-45);

	fp.filterOut(PC2);


	list<Point> P1, P2;
	P1 = PC1.getPoints();
	P2 = PC2.getPoints();

	PC3 = PC1 + PC2;

	PCR.setfileName("cikti.txt");
	PCR.save(PC3);

	system("pause");
}