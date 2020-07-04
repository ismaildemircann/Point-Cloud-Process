/**
 * @file	: PassThroughFilter.h
 * @Author	: Onur Akkepenek (akkepenek38@gmail.com) 152120171023
 * @date	: january, 2020
 * @brief	: PassThroughFilter Sinifi tanimi.
 */
#pragma once
#include"PointCloud.h"
#include"DepthCamera.h"
#include"PointCloudFilter.h"
 //! PassThroughFilter Class
 /*!
   Bu class pointcloud icindeki x,y,z noktalarina tek tek bakarak filtreleme yapar.
 */
class PassThroughFilter : virtual public PointCloudFilter
{
public:
	//! A constructor.
	PassThroughFilter();
	//! A constructor.
	~PassThroughFilter();
	/**
	* @brief				: Bu fonksiyon UpperLimitX degeri atamasi yapar.
	* @param upperLimitX	: x eksenin limit degeri.
	*/
	void setUpperLimitX(double upperLimitX);
	/**
    * @brief				: Bu fonksiyon UpperLimitX  degerini dondurur.
    */
	double getUpperLimitX();
	/**
	* @brief				: Bu fonksiyon LowerLimitX degeri atamasi yapar.
	* @param LowerLimitX	: x eksenin limit degeri.
	*/
	void setLowerLimitX(double LowerLimitX);
	/**
	* @brief				: Bu fonksiyon getLowerLimitX  degerini dondurur.
	*/
	double getLowerLimitX();
	/**
	* @brief				: Bu fonksiyon UpperLimitY degeri atamasi yapar.
	* @param upperLimitY	: Y eksenin limit degeri.
	*/
	void setUpperLimitY(double upperLimitY);
	/**
	* @brief				: Bu fonksiyon UpperLimitY  degerini dondurur.
	*/
	double getUpperLimitY();
	/**
	* @brief				: Bu fonksiyon LowerLimitY degeri atamasi yapar.
	* @param LowerLimitY	: Y eksenin limit degeri.
	*/
	void setLowerLimitY(double LowerLimitY);
	/**
	* @brief				: Bu fonksiyon LowerLimitY  degerini dondurur.
	*/
	double getLowerLimitY();
	/**
	* @brief				: Bu fonksiyon UpperLimitZ degeri atamasi yapar.
	* @param setUpperLimitZ	: Z eksenin limit degeri.
	*/
	void setUpperLimitZ(double upperLimitZ);
	/**
	* @brief				: Bu fonksiyon gUpperLimitZ  degerini dondurur.
	*/
	double getUpperLimitZ();
	/**
	* @brief				: Bu fonksiyon LowerLimitZ degeri atamasi yapar.
	* @param setLowerLimitZ	: Z eksenin limit degeri.
	*/
	void setLowerLimitZ(double LowerLimitZ);
	/**
	* @brief				: Bu fonksiyon LowerLimitZ  degerini dondurur.
	*/
	double getLowerLimitZ();
	/**
	* @brief			: Bu fonksiyon PointClouda var olan noktalara filtreleme islemi yapar.
	* @param PointCloud : islem gorecek noktalar kumesi.
	*/
	void filter(PointCloud& pc);
private:
	double upperLimitX;/*!< X noktasi icin en yuksek limit */
	double lowerLimitX;/*!< X noktasi icin en dusuk limit */
	double upperLimitY;/*!< Y noktasi icin en yuksek limit */
	double lowerLimitY;/*!< Y noktasi icin en dusuk limit */
	double upperLimitZ;/*!< Z noktasi icin en yuksek limit */
	double lowerLimitZ;/*!< Z noktasi icin en dusuk limit */
};
