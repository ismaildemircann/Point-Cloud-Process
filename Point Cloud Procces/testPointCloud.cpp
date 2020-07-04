/**
 * @file	: TestPointCloud.cpp
 * @brief	: bu fonksiyon pointcloud sinifinin dogru calisip calismadigini kontrol eder.
 */
#include <iostream>
#include "PointCloud.h"
#include <list>
#include <iterator>
using namespace std;

int main()
{
	PointCloud PC1, PC2, PC3;
	PC1.setPointNumber(5);
	PC2.setPointNumber(5);
	list<Point> A, B, C;
	Point a;
	list<Point>::iterator iter1, iter2, iter3;
	for (int i = 0; i < 5; i++)
	{
		a.setPointx(i);
		a.setPointy(i + 1);
		a.setPointz(i + 2);
		A.push_back(a);
	}
	PC1.setPoints(&A);
	A = PC1.getPoints();


	cout << "A:" << endl;
	for (iter1 = A.begin(); iter1 != A.end(); iter1++)
		cout << (*iter1).getPointx() << " " << (*iter1).getPointy() << " " << (*iter1).getPointz() << endl;
		
	B = A;
	PC2.setPoints(&B);
	B = PC2.getPoints();
	cout << endl << "B:" << endl;
	for (iter2 = B.begin(); iter2 != B.end(); iter2++)
		cout << (*iter2).getPointx() << " " << (*iter2).getPointy() << " " << (*iter2).getPointz() << endl;
	
	PC3 = PC1 + PC2;
	C = PC3.getPoints();
	cout << endl << "C:" << endl;
	for (iter3 = C.begin(); iter3 != C.end(); iter3++)
		cout << (*iter3).getPointx() << " " << (*iter3).getPointy() << " " << (*iter3).getPointz() << endl;


	system("pause");
}