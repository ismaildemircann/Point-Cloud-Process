/**
 * @file	: PointCloudInterface.cpp
 * @Author	: Onur Akkepenek (akkepenek38@gmail.com)
 * @date	: january, 2020
 */
#include "PointCloudInterface.h"
PointCloudInterface::PointCloudInterface(){}
PointCloudInterface::~PointCloudInterface() {}
/*!
* \param PCG: bir PointCloudGenerator nesnesi.
*/
void PointCloudInterface::addGenerator(PointCloudGenerator* PCG)
{
	this->generators.push_back(PCG);
}
/*!
* \param PCG: bir PointCloudRecorder nesnesi.
*/
void PointCloudInterface::setRecorder(PointCloudRecorder* pcr)
{
	recorder = pcr;
}

bool PointCloudInterface::generate()
{
	if (generators.size()==0)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < generators.size(); i++)
		{
			patch = this->generators[i]->captureFor();
			pointCloud = pointCloud + patch;
		}
		return true;
	}
	
}

bool PointCloudInterface::record()
{
	string str = "cikti.txt";
	recorder->setfileName(str);
	recorder->save(pointCloud);
	return true;
}
