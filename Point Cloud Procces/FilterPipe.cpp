/**
* @file		: FilterPipe.h
* @Author	: Orhan Inac /152120171050/orhaninc@outlook.com
* @date		: December 2019
*/
#include "FilterPipe.h"
#include <vector>
using namespace std;
FilterPipe::FilterPipe()
{
}

FilterPipe::~FilterPipe()
{
}
/*!
* \param filter: Eklenecek olan filtre fonksiyonuna ait nesne alir.
*/
void FilterPipe::addFilter(PointCloudFilter* filter)
{
	filters.push_back(filter);
}
/*!
* \param filter: Filtrelerin uygulanacagi pointcloud'u alir. .
*/
void FilterPipe::filterOut(PointCloud& pc)
{
	for (int i = 0; i < filters.size(); i++)
	{
		filters[i]->filter(pc);
	}
}
