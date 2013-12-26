//
//  KochLine.cpp
//  Ex83KochLinesSnowflake
//
//  Created by Ilya Rostovtsev on 12/25/13.
//
//

#include "KochLine.h"

KochLine::KochLine( const Vec2f& a, const Vec2f& b ): start{ a }, end{ b } { }

void KochLine::draw() const
{
    gl::lineWidth( 2.f );
    gl::drawLine( start, end );
}

Vec2f KochLine::kochA()
{
    return start;
}

Vec2f KochLine::kochB()
{
    auto v = end - start;
    v /= 3;
    v += start;
    return v;
}

Vec2f KochLine::kochC()
{
    auto a = start;
    auto v = end - start;
    v /= 3;
    a += v; // move to point B;
    
    rotate( &v, toRadians( -60.f ) );
    a += v; // move to point C
    
    return a;
}

Vec2f KochLine::kochD()
{
    auto v = end - start;
    v *= ( 2 / 3.f );
    v += start;
    return v;
}

Vec2f KochLine::kochE()
{
    return end;
}

void KochLine::rotate( Vec2f* v, const float theta )
{
    auto xTemp = v->x;
    v->x = v->x * cos( theta ) - v->y * sin( theta );
    v->y = xTemp * sin( theta ) + v->y * cos( theta );
}
