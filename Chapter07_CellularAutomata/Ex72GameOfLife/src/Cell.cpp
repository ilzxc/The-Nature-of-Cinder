//
//  Cell.cpp
//  Ex72GameOfLife
//
//  Created by Ilya Rostovtsev on 11/11/13.
//
//

#include "Cell.h"
#include <assert.h>

void Cell::set( const float x, const float y, const float w, const int _state )
{
    cell = Rectf{ x, y, x + w, y + w };
    state = { _state };
    previous = { state };
}

int Cell::getPrevious() const
{
    return previous;
}

int Cell::getState() const
{
    return state;
}

void Cell::savePrevious()
{
    previous = state;
}

void Cell::newState( const int s )
{
    assert( ( s >= 0 ) && ( s <= 1 ) );
    state = s;
}

void Cell::draw() const
{
    if ( ( previous == 0 ) && ( state == 1 ) ) {
        gl::color( 0.777f, 0.777f, 0.777f );
    } else if ( ( state == 1 ) ) {
        gl::color( 0.f, 0.f, 0.f );
    } else if ( ( previous == 1 ) && ( state == 0 ) ) {
        gl::color( 0.222f, 0.222f, 0.222f );
    } else { gl::color( 1.f, 1.f, 1.f ); }
    gl::drawSolidRect( cell );
    
    gl::color( Color::black() );
    gl::drawStrokedRect( cell );
}