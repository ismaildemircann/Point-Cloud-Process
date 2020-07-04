#include "PointCloudGenerator.h"
/**
* @file		: PointCloud.cpp
* @Author	: Orhan INAC /152120171050/orhaninc@outlook.com
* @date		: December 2019
*/
PointCloudGenerator::PointCloudGenerator()
{
}

PointCloudGenerator::~PointCloudGenerator()
{
}
/*!
* \param fp: atanacak filterpipe nesnesi.
*/
void PointCloudGenerator::setFilterPipe(FilterPipe * fp)
{
	this->filterpipe = fp;
}
/*!
* \param T: atanacak transform nesnesi.
*/
void PointCloudGenerator::setTransform(Transform T)
{
	transform = T;
}
Transform PointCloudGenerator::getTransform()
{
	return transform;
}
