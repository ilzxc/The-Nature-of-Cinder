#ifndef Ex65PathFollowing_Vehicle_h
#define Ex65PathFollowing_Vehicle_h

#pragma once
#include "cinder/gl/gl.h"
#include "Path.h"

using namespace ci;

class Vehicle
{

public:
	Vehicle( const Vec2f& _position, float _maxForce, float _maxSpeed );
    
	void update( const Path& p );
	void draw() const;

private:
	Vec2f position;
	Vec2f velocity;
	Vec2f acceleration;
	float size;
	float maxForce;
	float maxSpeed;
	float angle;
    std::vector< Vec2f > triPoints;

	void follow( const Path& p );
	void seek( const Vec2f& target );
	Vec2f getNormalPoint( const Vec2f& p, const Vec2f& a, const Vec2f& b );
	void borders( const Path& p );

};

#endif
