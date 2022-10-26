#pragma once
#ifndef _CLUSTER_H
#define _CLUSTER_H
#include "Interfaces.h"
#include "Point.h"
#include <vector>
using namespace std;
class Cluster
{
private:
	INotifyReshuffle* pMainClass;
	vector<Point*> points;
	Point mean;


	// Private methods
	void CalculateMean();

public:
	Cluster();
	~Cluster();
	Cluster(INotifyReshuffle* pMain);
	
	Point GetMean();
	void AddPoint(Point* point);
	void RemovePoint(Point* point);

	// Methods required for ReShuffle.
	int GetPointsSize();
	Point* GetPoint(int index);
};
#endif