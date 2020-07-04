/**
* @file		: PointCloud.h
* @Author	: Ismail Demircan /152120171029/ismaildemircann98@gmail.com
* @date		: December 2019
* @brief	: PointCloud sinifinin tanimi.
*/
#pragma once
#include "Point.h"
#include <list>
using namespace std;
class PointCloud : public Point
{
private:
	list<Point> points;
	int pointNumber;
public:
	//! PointCloud constructor
	PointCloud();
	/**
	* @brief			: Bu fonksiyon nokta sayisinin atamasini yapar.
	* @param pointNumber: kac adet nokta oldugunu iceren degisken.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	void setPointNumber(int pointNumber);
	/**
	* @brief			: Bu fonksiyon nokta bulutunda kac adet nokta bulundugunu dondurur.
	* @return			: Nokta sayisini return eder.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	int getPointNumber();
	/**
	* @brief			: Bu fonksiyon noktayi nokta bulutuna atar.
	* @param p			: Nokta bulutuna atanacak nokta degiskeni.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	void setPoints(list<Point> * p);
	/**
	* @brief			: Bu fonksiyon nokta bulutunda bulunan noktalari dondurur.
	* @return			: Noktalari dondurur.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	list<Point> getPoints();
	/**
	* @brief			: Bu fonksiyon iki nokta bulutunu toplamayi saglar.
	* @param &A			: PointCloud tipinde toplanacak bir nokta bulutu degiskeni.
	* @return			: Toplanan nokta bulutunu return eder.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	PointCloud operator+(PointCloud& A);
	/**
	* @brief			: Bu fonksiyon nokta bulutu tipinde bir degiskenin atama yapilmasini saglar.
	* @param *A			: PointCloud tipinde atanacak degerleri iceren nokta bulutu.
	* @return			: Atanan degerleri PointCloud tipinde return eder.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	void operator=(PointCloud* A);
	//! PointCloud Destructor.
	~PointCloud();
};