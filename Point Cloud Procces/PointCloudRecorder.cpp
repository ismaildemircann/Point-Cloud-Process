#include "PointCloudRecorder.h"
#include <fstream>
#include "PointCloud.h"
#include <string> 
#include <list>
#include <iterator>
using namespace std;
/*!
* \param filename: dosya adini alir.
*/
void PointCloudRecorder::setfileName(string fileName) {
	this->fileName = fileName;
}
string PointCloudRecorder::getfileName() {
	return this->fileName;
}
/*!
* \param Pc: Dosyaya kaydedilecek pointcloud.
*/
bool PointCloudRecorder::save(PointCloud&  Pc){
	ofstream myfile;
	myfile.open(this->getfileName());
	list<Point> P;
	list<Point>::iterator iter;
	P = Pc.getPoints();
	for (iter = P.begin(); iter != P.end(); iter++)
		myfile << (*iter).getPointx() << " " << (*iter).getPointy() << " " << (*iter).getPointz() << endl;
	myfile.close();
	return true;
}