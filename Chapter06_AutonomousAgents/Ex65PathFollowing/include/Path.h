#ifndef Ex65PathFollowing_Path_h
#define Ex65PathFollowing_Path_h

#pragma once
#include <vector>
#include "cinder/Vector.h"
#include "cinder/gl/gl.h"

using namespace ci;

class Path
{
    
public:
	Path();
    
    void draw() const;
	void addPoint( const float x, const float y );
	void reset();
	Vec2f getStart() const;
	Vec2f getEnd() const;
	float getRadius() const;
	const std::vector< Vec2f >& getPoints() const;
    
private:
	std::vector< Vec2f > points;
	float radius;
    float circleRadius;

};

#endif