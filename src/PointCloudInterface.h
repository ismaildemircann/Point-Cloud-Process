/**
 * @file	: PointCloudInterface.h
 * @Author	: Onur Akkepenek (akkepenek38@gmail.com) 152120171023
 * @date	: january, 2020
 * @brief	: PointCloudInterface classinin tanimi.
 */
#pragma once
#include"Point.h"
#include"PointCloud.h"
#include"DepthCamera.h"
#include"PassThroughFilter.h"
#include"PointCloudRecorder.h"
#include"RadiusOutlierFilter.h"
#include"Transform.h"
#include<iostream>
#include<vector>
 //! PointCloudInterface Class
 /*!
   Bu class islemleri kolaylastirmak icin kullanilan bir arayuz siniftir.
 */
class PointCloudInterface
{
private:
	PointCloud pointCloud, patch;/*!< Nokta bulutlari */
	vector<PointCloudGenerator*> generators;/*!< Nesneleri tutmaya yarayan generators vektoru */
	PointCloudRecorder *recorder;/*!< Dosyaya yazdirma islemi icin kullanilan nesne */
public:
	//! PointCloudInterface constructor
	PointCloudInterface();
	//! PointCloudInterface constructor
	~PointCloudInterface();
	/**
	* @brief			: Nesneleri vektore push islemi yapar.
	* @param PCG		: PointCloudGenerator
	* @see main()		: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	void addGenerator(PointCloudGenerator*PCG);
	/**
	* @brief			: Set islemi yapar.
	* @param PCR		: PointCloudRecorder
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	void setRecorder(PointCloudRecorder*PCR);
	/**
	* @brief			: Generators üyesinde bulunan tüm nesnelerden captureFor fonksiyonu çaðrÝlarak nokta bulutlarý saðlanýr.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	bool generate();	
	/**
	* @brief			: Bu fonksiyonu ise, pointCloud içindeki noktalarý dosyaya kaydeder.
	* @see main()		: Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	bool record();
};

