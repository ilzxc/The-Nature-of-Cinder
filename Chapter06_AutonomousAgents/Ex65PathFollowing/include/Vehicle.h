#ifndef Ex65PathFollowing_Vehicle_h
#define Ex65PathFollowing_Vehicle_h

#pragma once
#include "cinder/gl/gl.h"
#include "../include/Path.h"

using namespace ci;

class Vehicle
{
private:
	Vec2f position;
	Vec2f velocity;
	Vec2f acceleration;
	float size;
	float maxForce;
	float maxSpeed;
	float angle;

	void follow( const Path& p );
	void seek( const Vec2f& target );
	Vec2f getNormalPoint( const Vec2f& p, const Vec2f& a, const Vec2f& b );
	void borders( const Path& p );

public:
	Vehicle() {}
	Vehicle( const Vec2f& _position, float _maxForce, float _maxSpeed )
		: position( _position ),
		  velocity( Vec2f::zero() ),
		  acceleration( Vec2f::zero() ),
		  size( 8.0f ),
		  maxForce( _maxForce ),
		  maxSpeed( _maxSpeed ),
	      angle( 0.0f ) {
	}

	void update( const Path& p );
	void draw() const;
};

#endif
