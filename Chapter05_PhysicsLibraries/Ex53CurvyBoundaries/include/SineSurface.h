//
//  SineSurface.h
//  Ex53CurvyBoundaries
//
//  Created by Ilya Rostovtsev on 7/14/13.
//
//

#ifndef Ex53CurvyBoundaries_SineSurface_h
#define Ex53CurvyBoundaries_SineSurface_h

#include <vector>
#include "cinder/Vector.h"

using namespace ci;

class SineSurface {
private:
    std::vector<Vec2f> pointsForBox2D;
    
public:
    SineSurface() { }
    SineSurface( int s );
    std::vector<Vec2f> getPoints() const;
};

#endif
