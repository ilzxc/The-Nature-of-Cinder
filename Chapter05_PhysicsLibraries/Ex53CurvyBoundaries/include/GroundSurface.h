//
//  Surface.h
//  Ex53CurvyBoundaries
//
//  Created by Ilya Rostovtsev on 7/13/13.
//
//

#ifndef Ex53CurvyBoundaries_GroundSurface_h
#define Ex53CurvyBoundaries_GroundSurface_h

#include <vector>
#include "cinder/gl/gl.h"
#include "Box2D/Box2D.h"
#include "Conversions.h"

using namespace ci;

class GroundSurface {
private:
    std::vector<Vec2f> points;
    std::vector<Vec2f> debugPoints;
    b2Body* body;
    
    void createBody( b2World * world, std::vector<Vec2f> boxPoints );

public:
    GroundSurface() {}
    GroundSurface( b2World * world, std::vector<Vec2f> toWorldPoints ): points( toWorldPoints ) {
        createBody( world, toWorldPoints );
    }
    
    void draw() const;
    void resetSurface( b2World * world );
};

#endif
