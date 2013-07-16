#ifndef Ex65PathFollowing_Path_h
#define Ex65PathFollowing_Path_h

#pragma once
#include <vector>
#include "cinder/Vector.h"
#include "cinder/gl/gl.h"

using namespace ci;

class Path
{
private:
	std::vector< Vec2f > points;
	float radius;

public:
	Path(): radius( 60.0f ) { }

	void addPoint(float x, float y);
	void reset();
	Vec2f getStart() const;
	Vec2f getEnd() const;
	float getRadius() const;
	std::vector< Vec2f > getPoints() const;
	void draw(void) const;
};

#endif