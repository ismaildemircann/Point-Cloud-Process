/**
 * @file	: Point.h
 * @Author	: Onur Akkepenek (akkepenek38@gmail.com) 152120171023
 * @date	: january, 2020
 * @brief	: Point Sinif tanimi.
 */
#pragma once
 //! Point Class
 /*!
   Bu class x,y,z noktalari olusturup,bu noktalarin her birine deger atama,deger okuma ,esitlik durumu ve noktalar arasi uzakliklerini bulma islemleri yapilabilir.
 */
class Point
{
private:
	double x;/*!< x ekseni */
	double y;/*!< y ekseni */
	double z;/*!< z ekseni */
public:
	/**
	* @brief			: Bu yapici fonksiyon ilk koordinat deger atamalarini yapar.
	* @param x			: x ekseni degeri.
	* @param y			: y ekseni degeri.
	* @param z			: z ekseni degeri.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	Point(double x = 0, double y = 0, double z = 0) :x(x), y(y), z(z) {}
	~Point();
	/**
	* @brief			: Bu fonksiyon x eksen degeri atamasi yapar.
	* @param x			: x ekseni degeri.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	void setPointx(double x);
	/**
	* @brief			: Bu fonksiyon y eksen degeri atamasi yapar.
	* @param y			: y ekseni degeri.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	void setPointy(double y);
	/**
	* @brief			: Bu fonksiyon z eksen degeri atamasi yapar.
	* @param z			: z ekseni degeri.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	void setPointz(double z);
	/**
	* @brief			: Bu fonksiyon x eksen degerini dondurur.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	double const getPointx();
	/**
	* @brief			: Bu fonksiyon y eksen degerini dondurur.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	double const getPointy();
	/**
	* @brief			: Bu fonksiyon z eksen degerini dondurur.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	double const getPointz();
	/**
	* @brief			: Bu fonksiyon iki noktanin birbirine esit olup olmadigini kontrol eder.
	* @param A			: Point tipinde bir degiskendir.
	* @return			: Esit olma durumuna gore true veya false degeri dondurur.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	bool operator==(const Point& A)const;
	/**
	* @brief			: Bu fonksiyon iki nokta arasindaki uzakligi hesaplar.
	* @param A			: Point tipinde bir degiskendir.
	* @return			: Iki nokta arasindaki mesafeyi return eder.
	* @see main()		: fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
	double const distance(const Point&);
};

