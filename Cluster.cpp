#include "Cluster.h"

Cluster::Cluster()
{

}

Cluster::~Cluster()
{

}

Cluster::Cluster(INotifyReshuffle* pMain)
{
	pMainClass = pMain;
}

Point Cluster::GetMean()
{
	return mean;
}

void Cluster::AddPoint(Point* point)
{
	bool bIsInitialization = points.size() == 0;
	for (vector<Point*>::iterator it = points.begin(); it != points.end(); ++it)
	{
		if (*it == point)
		{
			return;
		}
	}
	points.push_back(point);

	CalculateMean();

	if(!bIsInitialization)
		pMainClass->ReShuffle();
}

void Cluster::RemovePoint(Point* point)
{
	vector<Point*>::iterator it = points.begin();
	bool bPointFound = false;
	for (; it != points.end(); it++)
	{
		if (*it == point)
		{
			bPointFound = true;
			break;
		}
	}

	if(bPointFound)
		points.erase(it);

	CalculateMean();
}

int Cluster::GetPointsSize()
{
	return points.size();
}

Point* Cluster::GetPoint(int index)
{
	return points[index];
}

void Cluster::CalculateMean()
{
	Point _mean;
	int size = points.size();

	vector<Point*>::iterator it = points.begin();
	for (; it != points.end(); ++it)
	{
		_mean += **it;
	}

	_mean /= size;

	mean = _mean;
}