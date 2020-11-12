#include <iostream>
#include <string>
#include "Point.h"
#include "DepthCamera.h"
#include "PointCloud.h"
using namespace std;

int main()
{
	Point *A = new Point[5];
	for (int i = 0; i < 5; i++)
	{
		A[i].setPointx((i + 1) * 4);
		A[i].setPointy((i + 1) * 5);
		A[i].setPointz((i + 1) * 6);
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == j)
				continue;
			else
				cout << "Distance: " << "A[" << i << "] - A[" << j << "] = " << A[i].distance(A[j]) << endl;
		}
		cout << "A:" << endl;
		cout << "Point x: " << A[i].getPointx() << endl;
		cout << "Point y: " << A[i].getPointy() << endl;
		cout << "Point z: " << A[i].getPointz() << endl;
		cout << endl;
	}
	if (A[0] == A[1])
		cout << "True" << endl;
	else
		cout << "False" << endl;

	system("pause");
}