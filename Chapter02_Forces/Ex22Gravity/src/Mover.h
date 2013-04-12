//
//  Mover.h
//  Ex1_4_VectorAccelConst
//
//  Created by Ilya Rostovtsev on 4/7/13.
//
//

#ifndef Ex1_4_VectorAccelConst_Mover_h
#define Ex1_4_VectorAccelConst_Mover_h

#include "cinder/app/AppBasic.h"
#include "cinder/Vector.h"
#include "cinder/Rand.h"

class Mover {
  public:
    Mover( float fatness );
    void resetPosition();
    void setAccel( cinder::Vec2f );
    void update();
    void draw();
    void setWind( const ci::Vec2f windDirection, const float wingMag );
    void setGravity ( const ci::Vec2f gravDirection, const float gravMag );
    void applyForces();
    
    float fatness; // functions as mass

private:
    ci::Vec2f position;
    ci::Vec2f velocity;
    ci::Vec2f acceleration;
    ci::Vec2f windForce;
    ci::Vec2f gravityForce;
    void applyForce( ci::Vec2f force );
    void checkEdges();
    float scaledDirections = -0.88;
};


#endif
