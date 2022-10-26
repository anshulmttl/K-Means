#pragma once
#ifndef _POINT_H
#define _POINT_H
#include <vector>
#include <assert.h>
using namespace std;

class Point
{
private:
	vector<int> coordinate;

public:
	Point();
	~Point();

	void AddCoordinate(int coor);
	int GetCoordinate(int index);

	bool operator==(const Point& point1);
	friend Point operator+(const Point& lhs, const Point& rhs);
	Point& operator=(const Point& point1);
	Point& operator+=(const Point& point1);
	Point& operator/=(const int num);
};
#endif