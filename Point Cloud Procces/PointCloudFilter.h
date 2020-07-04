#pragma once
#include "PointCloud.h"
/**
	* @brief : Bu class filtereleri tek bir class alt�nda toplar.
	*/
class PointCloudFilter
{
public:
	PointCloudFilter()
	{
	}
	~PointCloudFilter()
	{
	}
	virtual void filter(PointCloud &pc) = 0;
};

