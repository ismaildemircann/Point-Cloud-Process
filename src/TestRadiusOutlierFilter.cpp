/**
 * TestRadiusOutlierFilter.cpp 
 * @brief Bu test fonkisyonu RadiusOutlierFilter Classýný calistirir ve kontrol eder.
 */
#include "RadiusOutlierFilter.h"
#include "DepthCamera.h"
#include <iostream>
#include <string>
#include <list>
#include <iterator>
using namespace std;
int main()
{
	RadiusOutlierFilter N;
	N.setRadiusOutlierFilter(25);
	DepthCamera Cam;
	PointCloud PC1, PC2;

	Cam.setfileName("camera1.txt");
	PC1 = Cam.capture();
	N.filter(PC1);
	//Point *P = new Point[PC1.getPointNumber()];
	list<Point> P, L;
	list<Point>::iterator iter1, iter2;
	P = PC1.getPoints();
	cout << "Camera1 after radius outlier filter" << endl << endl;
	for (iter1 = P.begin(); iter1 != P.end(); iter1++)
		cout << (*iter1).getPointx() << " " << (*iter1).getPointy() << " " << (*iter1).getPointz() << endl;

	Cam.setfileName("camera2.txt");
	PC2 = Cam.capture();
	N.filter(PC2);
	//Point *L = new Point[PC2.getPointNumber()];
	L = PC2.getPoints();
	cout << endl << "Camera2 after radius outlier filter" << endl << endl;
	for (iter1 = L.begin(); iter1 != L.end(); iter1++)
		cout << (*iter1).getPointx() << " " << (*iter1).getPointy() << " " << (*iter1).getPointz() << endl;

	system("pause");
}