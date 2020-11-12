#pragma once
/**
* @file		: Transform.h
* @Author	: Sina Kusoglu/152120171039/sinakusoglu@gmail.com
* @date		: Aralik, 2019
* @brief	: Transform sinifinin tanimi
*
*/
#include "PointCloud.h"
#include<Eigen/Dense>z
class Transform
{
private:
	Eigen::Vector3d angles1;/*!< acilari iceren vektor */ 
	Eigen::Vector3d trans1;/*!<  dondurme degerlerini iceren vektor */
	Eigen::Matrix4d transMatrix1;/*!< transformation matrisi */
public:
	//! Transform constructor.
	Transform();
	//! Transform deconstructor.
	~Transform();
	/**
	* @brief			: Bu fonksiyon aci degerlerini atar.
	* @param angle1		: 1. aci degeri.
	* @param angle2		: 2. aci degeri.
	* @param angle3		: 3. aci degeri.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	void setAngles(double,double,double);
	/**
	* @brief			: Bu fonksiyon donusum degerlerini atar.
	* @param transx		: x ekseni icin donusum degeri.
	* @param transy		: y ekseni icin donusum degeri.
	* @param transz		: z ekseni icin donusum degeri.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	void setTrans(double,double,double);
	/**
	* @brief			: Bu fonksiyon aci degerlerini iceren diziyi dondurur.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	double *getAngles();
	/**
	* @brief			: Bu fonksiyon donusum degerlerini iceren diziyi dondurur.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	double *getTrans();
	/**
	* @brief			: Bu fonksiyon rotation matrisini olusturur.
	* @param ang[]		: aci degerlerini iceren dizi.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	void setRotation(double ang[]);
	/**
	* @brief			: Bu fonksiyon rotation matrisini olusturur.
	* @param ang		: aci degerlerini iceren vektor.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	void setRotation(Eigen::Vector3d ang);
	/**
	* @brief			: Bu fonksiyon translation matrisini olusturur.
	* @param tr[]		: translation degerlerini iceren dizi.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	void setTranslation(double tr[]);
	/**
	* @brief			: Bu fonksiyon translation matrisini olusturur.
	* @param tr			: translation degerlerini iceren vektor.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	void setTranslation(Eigen::Vector3d tr);
	/**
	* @brief			: Bu fonksiyon bir nokta icin transformation islemini yapar.
	* @param p			: Point tipinde nokta degiskeni.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	Point doTransform(Point p);
	/**
	* @brief			: Bu fonksiyon nokta list degiskeni icin transformation islemini yapar.
	* @param lp			: Point list tipinde nokta liste degiskeni.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	list<Point> doTransform(list<Point> lp);
	/**
	* @brief			: Bu fonksiyon nokta bulutu icin transformation islemini yapar.
	* @param pc			: Point cloud tipinde nokta bulutu degiskeni.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	PointCloud doTransform(PointCloud pc);
};

