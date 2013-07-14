//
//  NoiseSurface.h
//  Ex53CurvyBoundaries
//
//  Created by Ilya Rostovtsev on 7/14/13.
//
//

#ifndef Ex53CurvyBoundaries_NoiseSurface_h
#define Ex53CurvyBoundaries_NoiseSurface_h

#include <vector>
#include "cinder/Vector.h"
#include "cinder/Perlin.h"

using namespace ci;

class NoiseSurface {
private:
    std::vector<Vec2f> pointsForBox2D;
    Perlin p;
    
public:
    NoiseSurface() { }
    NoiseSurface( int s );
    std::vector<Vec2f> getPoints() const;
};

#endif
