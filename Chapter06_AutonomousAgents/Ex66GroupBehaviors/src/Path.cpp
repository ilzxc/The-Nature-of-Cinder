//
//  Path.cpp
//  Ex66GroupBehaviors
//
//  Created by Ilya Rostovtsev on 11/8/13.
//
//

#include "Path.h"

using namespace ci;

Path::Path(): radius{ 30.0f }
{ }

Path::~Path()
{
    if ( points.size() != 0 ) {
        points.clear();
    }
}

void Path::addPoint( const float x, const float y )
{
    points.push_back( Vec2f{ x, y } );
}

void Path::draw() const
{
    gl::color( 0.777f, 0.777f, 0.777f );
	gl::lineWidth( radius );
	gl::begin( GL_LINE_STRIP );
    for ( const auto& p : points ) {
        gl::vertex( p );
    }
    gl::vertex( points[0] );
    gl::end();
    
	for ( const auto& p : points ) {
		gl::drawSolidCircle( p, radius * 0.7f );
	}
    
	gl::color( 0.777f, 0.0f, 0.0f );
	gl::lineWidth( 1.0f );
	gl::begin( GL_LINE_STRIP );
    for ( const auto& p : points ) {
        gl::vertex( p );
    }
    gl::vertex( points[0] );
    gl::end();
}

Vec2f Path::getPoint( const int index ) const
{
    if ( ( index >= 0 ) && ( index < points.size() ) ) {
        return points[ index ];
    }
    return Vec2f::zero();
}

const std::vector< Vec2f >& Path::getPoints() const
{
    return points;
}

float Path::getRadius() const
{
    return radius;
}