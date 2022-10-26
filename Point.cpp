#include "Point.h"

Point::Point()
{

}

Point::~Point()
{

}

void Point::AddCoordinate(int coor)
{
	coordinate.push_back(coor);
}

int Point::GetCoordinate(int index)
{
	return coordinate[index];
}

bool Point::operator==(const Point& point1)
{
	bool bIsEqual = false;

	if (coordinate.size() == point1.coordinate.size())
	{
		for (int i = 0; i < coordinate.size(); i++)
		{
			if (coordinate[i] == point1.coordinate[i])
			{
				bIsEqual = true;
			}
			else
			{
				bIsEqual = false;
				break;
			}
		}
	}

	return bIsEqual;
}

Point& Point::operator=(const Point& point1)
{
	if (this == &point1)
		return *this;
	
	if(coordinate.size()  != 0)
		coordinate.clear();

	for (vector<int>::const_iterator it = point1.coordinate.begin(); it != point1.coordinate.end(); ++it)
	{
		coordinate.push_back(*it);
	}
	//std::copy(point1.coordinate.begin(), point1.coordinate.end(), back_inserter(coordinate));

	return *this;
}

Point& Point::operator+=(const Point& point1)
{
	// TODO: insert return statement here
	if (point1.coordinate.size() == 0)
	{
		assert(NULL);
	}

	if (coordinate.size() == 0)
	{
		for (vector<int>::const_iterator it = point1.coordinate.begin(); it != point1.coordinate.end(); ++it)
		{
			coordinate.push_back(*it);
		}
		//std::copy(point1.coordinate.begin(), point1.coordinate.end(), back_inserter(coordinate));
		return *this;
	}

	if (coordinate.size() != point1.coordinate.size())
	{
		assert(NULL); // This case should not happen
	}
	else
	{
		for (int i = 0; i < coordinate.size(); i++)
		{
			coordinate[i] += point1.coordinate[i];
		}
	}
	
	return *this;
}

Point& Point::operator/=(const int num)
{
	// TODO: insert return statement here
	if (num == 0)
	{
		assert(NULL);
	}

	for (int i = 0; i < coordinate.size(); i++)
	{
		coordinate[i] /= num;
	}

	return *this;
}

Point operator+(const Point& lhs, const Point& rhs)
{
	Point p;

	if (lhs.coordinate.size() != rhs.coordinate.size())
	{
		// To implement
		assert(NULL);
	}

	if (lhs.coordinate.size() == 0 && rhs.coordinate.size() != 0)
	{
		return rhs;
	}

	if (rhs.coordinate.size() == 0)
	{
		// To implement
		assert(NULL);
	}

	for (int i = 0; i < lhs.coordinate.size(); i++)
	{
		p.coordinate.push_back(lhs.coordinate[i] + rhs.coordinate[i]);
	}

	return p;
}
