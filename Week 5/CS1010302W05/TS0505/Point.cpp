/*****************************************************************//**
 * \file   Point.cpp
 * \brief  Point class implementation
 *
 * \author kai
 * \date   2025/3/21
 *********************************************************************/
#include "Point.h"

 /**
 * Sets the private data after an object of this class is created
 *
 * \param x The x value of the position
 * \param y The y value of the position
 */
void Point::Set(float x, float y) {
	// Set the position
	position[0] = x;
	position[1] = y;
}

/**
 * To move the point along the horizontal and vertical directions specified by the first and second arguments
 *
 * \param dx The x-distance of the movement
 * \param dy The y-distance of the movement
 */
void Point::Move(float dx, float dy) {
	// Move the posiion
	position[0] += dx;
	position[1] += dy;
}

/**
 * To rotate the point by 90 degrees clockwise around the origin.
 *
 */
void Point::Rotate() {
	// Exchange the x and y value
	float tmp = position[0];
	position[0] = position[1];
	// Set y = y * -1
	position[1] = -tmp;

	// Handle -0
	if (position[1] == -0.0) {
		position[1] = 0;
	}
}

/**
 * To reflect point in the origin
 *
 */
void Point::Reflect() {
	// Reflect the position
	position[0] *= -1;
	position[1] *= -1;

	// Handle -0
	if (position[0] == -0.0) {
		position[0] = 0;
	}
	if (position[1] == -0.0) {
		position[1] = 0;
	}
}

/**
 * To retrieve the current coordinates of the point (X)
 *
 * \return The x value
 */
float Point::GetHorizontal() const {
	return position[0];
}

/**
 * To retrieve the current coordinates of the point (X)
 *
 * \return The y value
 */
float Point::GetVertical() const {
	return position[1];
}

/**
 * Copy value of other point
 *
 * \param source The source point
 * \return This point
 */
Point& Point::operator= (const Point& source) {
	position[0] = source.GetHorizontal();
	position[1] = source.GetVertical();
	return *this;
}

/**
 * A destructor used to release memory before the instance of class
 *
 */
Point::~Point()
{
	// Nothing need to release
}