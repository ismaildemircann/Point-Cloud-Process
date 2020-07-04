/**
 * @file DepthCamera.h
 * @Author ismail Demircan (ismaildemircann98@gmail.com) No: 152120171029
 * @date Aralik, 2019
 * @brief Bu dosya verilen PointClouddaki verileri yarýcapa gore filtreden gecirir.
 * Filtreden gecenleri pointclouda atar.
 */
#pragma once
#include"PointCloud.h"
#include"PointCloudFilter.h"
 //! RadiusOutlier class.
 /*!
 Bu class radiusa gore Filtrelenmis degerleri pointclouda atar.
  */
class RadiusOutlierFilter : virtual public PointCloudFilter
{
public:
	//! constructor. 
	RadiusOutlierFilter();
	//! destructor.
	~RadiusOutlierFilter(void);
	/**
	* @brief :Bu fonksiyon filtrelemede kullanilacak degeri alir ve radiusa atar.
	* \param radius: bir double yaricap degeri.
	* @see main() : Fonkisyonun cagrildigi yeri inceleyeniz.
	*/
	void setRadiusOutlierFilter(double radius);
	/**
	* @brief :Bu fonksiyon radius degerini dondurur.
	* @see main() : Fonkisyonun cagrildigi yeri inceleyeniz.
	*/
	double getRadiusOutlierFilter();
	/**
	* @brief :Bu fonksiyon alinan degerleri yaricapa gore filtreler.
	* \param PointCloud: bir PointCloud nesnesi.
	* @see main() : Fonkisyonun cagrildigi yeri inceleyeniz.
	*/
	void filter(PointCloud &pc);
private:
	double radius; /*!< Yaricap degeri */ 
};

