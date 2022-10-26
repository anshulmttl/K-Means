#pragma once
#ifndef _MAINCLASS_H
#define _MAINCLASS_H
#include "Interfaces.h"
#include "Point.h"
#include "Cluster.h"
#include <vector>

using namespace std;

class MainClass : public INotifyReshuffle
{
private:
	vector<Cluster*> clusters;
	vector<Point*> points; // Local copy of all points.
	int totalClusters;
	int EuclideanDistance(Point p1, Point p2);

	void ReShuffle();

public :
	MainClass();
	~MainClass();

	void Clusterize(int arr[10][4], int numberOfClusters);
	vector<int> GetArray();
};
#endif