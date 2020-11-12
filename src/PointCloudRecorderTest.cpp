#include <iostream>
#include "DepthCamera.h"
#include "Point.h"
#include "PointCloud.h"
#include <string>
#include "PointCloudRecorder.h"
#include <list>
using namespace std;
int main() {
	DepthCamera Cam;
	PointCloud K;
	PointCloudRecorder Po;
	Cam.setfileName("camera1.txt");
	Po.setfileName("save.txt");
	K = Cam.capture();
	bool a;
	PointCloud Sum;
	a = Po.save(K);
	cout << endl;
	list<Point> P;
	P = K.getPoints();
	system("pause");

}
