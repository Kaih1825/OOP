/*****************************************************************//**
 * \file   Point.h
 * \brief  A definition of a class named Point that might be used to store and manipulate the location of a point in the plane.
 *
 * \author kai
 * \date   2025/3/20
 *********************************************************************/
#ifndef _POINT_H
#define _POINT_H
class Point {
private:
	// The point possition
	float position[2] = { 0.0 };

public:
	// Sets the private data after an object of this class is created
	void Set(float x, float y);

	// To move the point along the horizontal and vertical directions specified by the first and second arguments
	void Move(float dx, float dy);

	// To rotate the point by 90 degrees clockwise around the origin.
	void Rotate();

	// To reflect point in the origin
	void Reflect();

	// To retrieve the current coordinates of the point (X)
	float GetHorizontal() const;

	// To retrieve the current coordinates of the point (Y)
	float GetVertical() const;

	// Copy value of other point
	Point& operator= (const Point& source);

	// A destructor used to release memory before the instance of class destroyed
	~Point();
};
#endif // !_POINT_H


