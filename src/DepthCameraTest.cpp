/**
 * DepthCameraTest.cpp
 * @brief Bu test fonkisyonu DepthCamera Classýný calistirir ve kontrol eder.
 */
#include <iostream>
#include "DepthCamera.h"
#include "Point.h"
#include "PointCloud.h"
#include "RadiusOutlierFilter.h"
#include <string>
using namespace std;
int main() {
	DepthCamera CAM;
	PointCloud PC1, PC2;
	
	CAM.setfileName("camera1.txt");
	PC1 = CAM.capture();
	list<Point> A, B;
	list<Point>::iterator iter1 ,iter2;
	A = PC1.getPoints();
	iter1 = A.begin();
	cout << "Camera1:" << endl << endl;
	for (iter1 = A.begin(); iter1 != A.end(); iter1++)
		cout << (*iter1).getPointx() << " " << (*iter1).getPointy() << " " << (*iter1).getPointz() << endl;

	CAM.setfileName("camera2.txt");
	PC2 = CAM.capture();
	B = PC1.getPoints();
	iter1 = B.begin();
	cout << "Camera2:" << endl << endl;
	for (iter1 = B.begin(); iter1 != B.end(); iter1++)
		cout << (*iter1).getPointx() << " " << (*iter1).getPointy() << " " << (*iter1).getPointz() << endl;

	system("pause");
}