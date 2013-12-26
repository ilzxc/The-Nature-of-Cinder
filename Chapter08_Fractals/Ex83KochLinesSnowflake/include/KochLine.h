//
//  KochLine.h
//  Ex83KochLinesSnowflake
//
//  Created by Ilya Rostovtsev on 12/25/13.
//
//

#ifndef Ex83KochLinesSnowflake_KochLine_h
#define Ex83KochLinesSnowflake_KochLine_h

#include "cinder/Vector.h"
#include "cinder/gl/gl.h"

using namespace ci;

class KochLine
{
public:
    KochLine( const Vec2f& a, const Vec2f& b );
    void draw() const;
    
    Vec2f kochA();
    Vec2f kochB();
    Vec2f kochC();
    Vec2f kochD();
    Vec2f kochE();
    
private:
    Vec2f start;
    Vec2f end;
    
    void rotate( Vec2f* v, const float theta );
};

#endif
