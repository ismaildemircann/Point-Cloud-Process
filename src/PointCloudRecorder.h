#pragma once
#include<iostream>
#include<string>
#include"PointCloud.h"
using namespace std;
class PointCloudRecorder
{
private:
	string fileName;
public:
	/**
	* @brief			: Bu fonksiyon dosya adini alip atama yapar.
	* @param			: atanacak filename i alir.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	void setfileName(string fileName);
	/**
	* @brief			: Bu fonksiyon dosya adini geri dondurur.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	string getfileName();
	/**
	* @brief			: Bu fonksiyon filtreden gecirilmis noktalari dosyaya kaydeder.
	* @param			: dosyaya kaydedilecek pointcloud u alir.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	bool save(PointCloud&);
};

