#include "Path.h"

Path::Path()
: radius{ 60.f },
  circleRadius{ radius * 0.75f }
{ }

void Path::draw() const
{
    gl::color( 0.777f, 0.777f, 0.777f );
    gl::lineWidth( radius );
    gl::begin( GL_LINE_STRIP );
    for ( auto& p : points ) {
        gl::vertex( p );
    }
    gl::end();
    
    for ( auto& p : points ) {
        gl::drawSolidCircle( p, circleRadius );
    }
    
    gl::color( 0.777f, 0.f, 0.f );
    gl::lineWidth( 1.f );
    gl::begin( GL_LINE_STRIP );
    for ( auto& p : points ) {
        gl::vertex( p );
    }
    gl::end();
}

void Path::addPoint( const float x, const float y )
{
    points.push_back( Vec2f{ x, y } );
}

Vec2f Path::getStart() const
{
    return points[ 0 ];
}

Vec2f Path::getEnd() const
{
    return points[ points.size() - 1 ];
}

float Path::getRadius() const
{
    return radius / 2.f;
}

const std::vector< Vec2f >& Path::getPoints() const
{
    return points;
}

void Path::reset()
{
    points.clear();
}