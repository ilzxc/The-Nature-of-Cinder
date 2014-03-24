//
//  Turtle.cpp
//  Ex86LSystem
//
//  Created by Ilya Rostovtsev on 3/23/14.
//
//

#include "Turtle.h"

using namespace ci;

Turtle::Turtle( const string& s, const float l, const float t )
: todo( s ), len( l ), theta( t )
{
}

void Turtle::render()
{
    for ( auto i = 0; i < todo.size(); ++i )
    {
        char c = todo[ i ];
        if ( ( c == 'F' ) || ( c == 'G' ) ) {
            gl::drawLine( Vec2f::zero(), Vec2f( len, 0.f ) );
            gl::translate( Vec2f( len, 0.f ) );
        } else if ( c == '+' ) {
            gl::rotate( toDegrees( theta ) );
        } else if ( c == '-' ) {
            gl::rotate( toDegrees( -theta ) );
        } else if ( c == '[' ) {
            gl::pushMatrices();
        } else if ( c == ']' ) {
            gl::popMatrices();
        }
    }
}

void Turtle::setLen( const float l )
{
    len = l;
}

void Turtle::changeLen( const float percent )
{
    len *= percent;
}

void Turtle::setToDo( string s )
{
    todo = s;
}
