#include "MainClass.h"

int MainClass::EuclideanDistance(Point p1, Point p2)
{
	int distanceSquare = 0;

	for (int i = 0; i < 4; i++)
	{
		int coor1 = p1.GetCoordinate(i);
		int coor2 = p2.GetCoordinate(i);

		distanceSquare = distanceSquare + ((coor1 - coor2) * (coor1 - coor2));
	}

	return sqrt(distanceSquare);
}

MainClass::MainClass()
{
	totalClusters = 0;
}

MainClass::~MainClass()
{
	for (vector<Cluster*>::iterator it = clusters.begin(); it != clusters.end(); ++it)
	{
		if (*it)
		{
			delete* it;
		}
	}
}

void MainClass::ReShuffle()
{
	for (int clusterIndex = 0; clusterIndex < totalClusters; clusterIndex++)
	{
		Cluster* clus = clusters[clusterIndex];

		int totalPoints = clus->GetPointsSize();

		for (int pointIndex = 0; pointIndex < totalPoints; pointIndex++)
		{
			if (pointIndex >= clus->GetPointsSize())
			{
				return;
			}

			Point* p = clus->GetPoint(pointIndex);

			// Every cluster every point recalculate euclidean distance and reinsert.
			//for (int i = 0; i < 10; i++)
			int mean = INT_MAX;
			int clusterIndex1 = -1;
			for (int j = 0; j < clusters.size(); j++)
			{
				Point meanPoint = clusters[j]->GetMean();
				int eucDis = EuclideanDistance(*(p), meanPoint);
				if (eucDis < mean)
				{
					mean = eucDis;
					clusterIndex1 = j;
				}
			}

			if (clusterIndex1 != clusterIndex)
			{
				clusters[clusterIndex1]->AddPoint(p);
				clus->RemovePoint(p);
			}
				
		}
	}
}

void MainClass::Clusterize(int arr[10][4], int numberOfClusters)
{
	if (numberOfClusters > 10)
	{
		assert(0);
	}

	totalClusters = numberOfClusters;

	for (int i = 0; i < 10; i++)
	{
		Point* p = new Point();
		p->AddCoordinate(arr[i][0]);
		p->AddCoordinate(arr[i][1]);
		p->AddCoordinate(arr[i][2]);
		p->AddCoordinate(arr[i][3]);

		points.push_back(p);
	}

	for (int i = 0; i < numberOfClusters; i++)
	{
		Cluster* clus = new Cluster(this);

		// Add 1 point randomly to cluster to initialize the cluster
		clus->AddPoint(points[i]);

		clusters.push_back(clus);
	}

	//Add the remaining points
	for (int i = numberOfClusters; i < 10; i++)
	{
		int mean = INT_MAX;
		int clusterIndex = -1;
		for (int j = 0; j < clusters.size(); j++)
		{
			Point meanPoint = clusters[j]->GetMean();
			int eucDis = EuclideanDistance(*(points[i]), meanPoint);
			if (eucDis < mean)
			{
				mean = eucDis;
				clusterIndex = j;
			}
		}

		clusters[clusterIndex]->AddPoint(points[i]);
		
	}

}

vector<int> MainClass::GetArray()
{
	vector<int> values;

	return values;
}
