#include"Point.h"
#include"PointCloud.h"
#include"DepthCamera.h"
#include"PassThroughFilter.h"
#include"PointCloudRecorder.h"
#include"PointCloudGenerator.h"
#include"RadiusOutlierFilter.h"
#include"PointCloudInterface.h"
#include"Transform.h"
#include<iostream>
#include<list>
using namespace std;
int main() {

	DepthCamera DC1, DC2;
	PointCloudRecorder PCR;
	string str1 = "camera1.txt", str2 = "camera2.txt";
	PointCloudInterface PCI;
	PCI.setRecorder(&PCR);
	DC1.setfileName(str1);
	DC2.setfileName(str2);

	PCI.addGenerator(&DC1);
	PCI.addGenerator(&DC2);
	PCI.generate();
	PCI.record();

	system("pause");
}