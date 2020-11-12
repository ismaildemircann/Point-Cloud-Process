#pragma once
#include "Transform.h"
#include "FilterPipe.h"
class PointCloudGenerator
{
public:
	PointCloudGenerator();
	~PointCloudGenerator();
	virtual PointCloud capture() = 0;
	virtual PointCloud captureFor() = 0;
	/**
	* @brief			: Bu fonksiyon filterPipe nesnesini atar.
	* @param			: Filterpipe a ait nesne alir.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	void setFilterPipe(FilterPipe*);
	/**
	* @brief			: Bu fonksiyon Transform nesnesini atar.
	* @param			: Transform nesnesi alir.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	void setTransform(Transform);
	/**
	* @brief			: Bu fonksiyon trasnform nesnesini cagrildigi yere gonderir.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	Transform getTransform();
private:
	Transform transform;
	FilterPipe *filterpipe;
};