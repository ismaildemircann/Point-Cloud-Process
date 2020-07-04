/**
* @file		: FilterPipe.h
* @Author	: Orhan Inac /152120171050/orhaninc@outlook.com
* @date		: December 2019
* @brief	: FilterPipe sinifiin tanimi.
*/
#pragma once
#include"PointCloudFilter.h"
#include<vector>
using namespace std;
class FilterPipe
{
public:
	//! FilterPipe constructor
	FilterPipe();
	//! FilterPipe deconstructor
	~FilterPipe();
	/**
	* @brief			: Bu fonksiyon vektore filtrelere ait nesneleri ekler.
	* @param      filter: eklenecek filtreye ait nesneleri alir.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	void addFilter(PointCloudFilter* filter);
	/**
	* @brief			: Bu fonksiyon vektore atilan filtreleri gelen pointcloud noktalarina uygular.
	* @param      &pc	: filtrelerin uygulanacagi nokta bulutunu alir.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	void filterOut(PointCloud &pc);
private:
	vector<PointCloudFilter*> filters;
};

