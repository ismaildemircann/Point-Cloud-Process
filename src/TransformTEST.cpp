/**
 * @file	: TransformTEST.cpp
 * @brief	: Bu fonksiyon Transform kullanarak istenilen dogrultuda calisip calismadigini test etmek icin olusturulmustur.
 */
#include <iostream>
#include"Transform.h"
using namespace std;
/*! Bu fonksiyon Transform kullanarak istenilen dogrultuda calisip calismadigini test etmek icin olusturulmustur. */
int main()
{
	Point A, C, *p1 = new Point[2];
	list<Point> listt;
	A.setPointx(150);
	A.setPointy(150);
	A.setPointz(-50);
	Transform B;
	PointCloud D;
	PointCloud F;
	D.setPointNumber(2);
	B.setAngles(0, 0, -90.0);
	B.setTrans(100, 500, 50);
	double *ang,*tr;
	ang = B.getAngles();
	tr = B.getTrans();
	for (int i = 0; i < 3; i++) {
		cout << *(ang + i) << endl;
	}
	cout << "---------------------------" << endl;
	for (int i = 0; i < 3; i++) 
	{
		cout << *(tr + i) << endl;
	}
	cout << "---------------------------" << endl;
	B.setRotation(B.getAngles());
	cout << "---------------------------" << endl;
	B.setTranslation(B.getTrans());
	cout << "---------------------------" << endl;
	C = B.doTransform(A);
	cout << "C " << C.getPointx() << " " << C.getPointy() << " " << C.getPointz() << endl;
	cout << "---------------------------" << endl;

	(p1)->setPointx(150);
	p1->setPointy(150);
	p1->setPointz(-50);
	(p1+1)->setPointx(2);
	(p1 + 1)->setPointy(5);
	(p1 + 1)->setPointz(1);
	listt.push_back(*p1);
	listt.push_back(*(p1 + 1));
	D.setPoints(&listt);
	F = B.doTransform(D);
	listt = F.getPoints();
	list<Point>::iterator iter;
	for (iter = listt.begin(); iter != listt.end(); iter++)
	{
		Point temp;
		temp = *iter;
		cout << temp.getPointx() << "\t" << temp.getPointy() << "\t" << temp.getPointz() << endl;
	}
	system("pause");
}