/*****************************************************************//**
 * \file   Point.cpp
 * \brief  Implementation the functions of point class
 *
 * \author Kai
 * \date   2025/3/11
 *********************************************************************/
#include "Point.h"

 /**
  * Set point position
  *
  * \param vertical The x value of then point
  * \param horizontal The y value of the point
  */
void Point::Set(int vertical, int horizontal)
{
	// Set the point position to the variable in the class
	this->vertical = vertical;
	this->horizontal = horizontal;
}

/**
 * Move the point
 *
 * \param x The distance of x
 * \param y The distance of y
 */
void Point::Move(int x, int y)
{
	// Move the point
	this->vertical += x;
	this->horizontal += y;
}

/**
 * Rotate the point 90 degrees clockwise from the origin
 *
 */
void Point::Rotate()
{
	// Switch the x and y value and set y = y * -1
	int tmp = this->vertical;
	this->vertical = this->horizontal;
	this->horizontal = -tmp;
}
