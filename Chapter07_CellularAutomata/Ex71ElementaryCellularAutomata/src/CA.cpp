//
//  CA.cpp
//  Ex71ElementaryCellularAutomata
//
//  Created by Ilya Rostovtsev on 8/4/13.
//
//

#include "CA.h"

// Public

CA::CA( const int _ruleset[ 8 ] )
: ruleset{ _ruleset[ 0 ], _ruleset[ 1 ],
           _ruleset[ 2 ], _ruleset[ 3 ],
           _ruleset[ 4 ], _ruleset[ 5 ],
           _ruleset[ 6 ], _ruleset[ 7 ]  },
  radius( 5 )
{
    columns = app::getWindowWidth() / ( radius * 2 );
    rows = app::getWindowHeight() / ( radius * 2 );
    matrix = new int[ columns * rows ];
    restart();
}

CA::~CA()
{
    delete matrix;
}

void CA::restart()
{
    for( auto i = 0; i < columns; ++i ) {
        for ( auto j = 0; j < rows; ++j ) {
            matrix[ i * columns + j ] = 0;
        }
    }
    matrix[ columns / 2 ] = 1;
    generation = 0;
}

void CA::generate() {
    // For every spot, determine new state from current state & neighbor cells:
    for ( auto i = 0; i < columns; ++i ) {
        auto y     = generation % rows;
        auto left  = matrix[ ( ( i + columns - 1 ) % columns ) * columns + y ];
        auto me    = matrix[ i * columns + y ];
        auto right = matrix[ ( ( i + 1 ) % columns ) * columns + y ];
        matrix[ i * columns + ( ( generation + 1 ) % rows ) ] = rules( left, me, right );
    }
    ++generation;
}

void CA::update() {
    
}

void CA::draw() const
{
    int offset = generation % rows;
    
    for ( auto i = 0; i < columns; ++i ) {
        for ( auto j = 0; j < rows; ++j ) {
            auto y = j - offset;
            if ( y <= 0 ) {
                y = rows + y;
                if ( matrix[ i * columns + j ] == 1 ) {
                    gl::color( 0.f, 0.f, 0.f );
                } else {
                    gl::color( 1.f, 1.f, 1.f );
                }
                gl::drawSolidCircle( Vec2f( i * 2 * radius, ( y - 1 ) * 2 * radius ), radius );
            }
        }
    }
}

// Private

int CA::rules( const int a, const int b, const int c ) const
{
    // "dumb" implementation:
    if ( ( a == 1 ) && ( b == 1 ) && ( c == 1 ) ) { return ruleset[ 0 ]; }
    if ( ( a == 1 ) && ( b == 1 ) && ( c == 0 ) ) { return ruleset[ 1 ]; }
    if ( ( a == 1 ) && ( b == 0 ) && ( c == 1 ) ) { return ruleset[ 2 ]; }
    if ( ( a == 1 ) && ( b == 0 ) && ( c == 0 ) ) { return ruleset[ 3 ]; }
    if ( ( a == 0 ) && ( b == 1 ) && ( c == 1 ) ) { return ruleset[ 4 ]; }
    if ( ( a == 0 ) && ( b == 1 ) && ( c == 0 ) ) { return ruleset[ 5 ]; }
    if ( ( a == 0 ) && ( b == 0 ) && ( c == 1 ) ) { return ruleset[ 6 ]; }
    if ( ( a == 0 ) && ( b == 0 ) && ( c == 0 ) ) { return ruleset[ 7 ]; }
    return 0;
}

bool CA::finished() const
{
    if ( generation > app::getWindowHeight() ) {
        return true;
    }
    return false;
}