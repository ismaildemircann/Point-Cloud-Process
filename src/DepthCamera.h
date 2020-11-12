/**
 * @file DepthCamera.h
 * @Author ismail Demircan (ismaildemircann98@gmail.com)  No: 152120171029
 * @date Aralik, 2019
 * @brief Bu dosya verilen dosyalardan verileri okur ve degerleri atar. 
 */
#pragma once
#include "PointCloudGenerator.h"
#include<iostream>
#include"PointCloud.h"
using namespace std;
/*!
* Once verilen dosyanin ismini alir ve dosyadan alinan degerleri pointcloud nesnesine atar.
*/
class DepthCamera : virtual public PointCloudGenerator
{
public:
	//! constructor. 
	DepthCamera();
	//! destructor.
	~DepthCamera();
	/**
	* @brief :Bu fonksiyon dosyanin ismini alir ve dosya ismine atar.
	* \param radius: bir string dosya ismi.
	* @see main() : Fonkisyonun cagrildigi yeri inceleyeniz.
	*/
	void setfileName(string fileName);
	/**
	* @brief :Bu fonksiyon dosyanin ismini dondurur.
	* @see main() : Fonkisyonun cagrildigi yeri inceleyeniz.
	*/
	string getfileName();
	/**
	* @brief :Bu fonksiyon dosyadan degerleri alir ve nesneye atar.
	* @see main() : Fonkisyonun cagrildigi yeri inceleyeniz.
	*/
	PointCloud capture();
	/**
	* @brief :Bu fonksiyon dosyadan degerleri alan capture fonksiyonunu cag�r�r.
	* Sonras�nda filterpipe icin gerekli filtreleri g�derir ve gerekli degerleri set eder.
	* Daha sonras�nda transform icin gerekli nesneyi g�nderir.
	* @see main() : Fonkisyonun cagrildigi yeri inceleyeniz.
	*/
	PointCloud captureFor();
private:
	string fileName; /*!< Dosya ismi */ 
};