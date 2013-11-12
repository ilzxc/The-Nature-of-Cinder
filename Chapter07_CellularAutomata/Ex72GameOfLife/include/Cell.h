//
//  Cell.h
//  Ex72GameOfLife
//
//  Created by Ilya Rostovtsev on 11/11/13.
//
//

#ifndef __Ex72GameOfLife__Cell__
#define __Ex72GameOfLife__Cell__

#include "cinder/gl/gl.h"
#include "cinder/Vector.h"
#include "cinder/Rand.h"

using namespace ci;

class Cell
{
    
public:
    Cell() { }
    void set( const float x, const float y, const float w, const int state );

    void savePrevious();
    void newState( const int s );
    void draw() const;
    int getPrevious() const;
    int getState() const;
    
private:
    Rectf cell;
    int state;
    int previous;
    
};

#endif /* defined(__Ex72GameOfLife__Cell__) */
