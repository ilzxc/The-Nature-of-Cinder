//
//  Oscillator.h
//  Ex34SimpleHarmonicMotion
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//

#ifndef Ex34SimpleHarmonicMotion_Oscillator_h
#define Ex34SimpleHarmonicMotion_Oscillator_h

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;

class Oscillator {
private:
    Vec2f angle;
    Vec2f velocity;
    Vec2f amplitude;
    Vec2f display;
    
public:
    Oscillator() { };
    Oscillator( Rand& r, const Vec2f& windowCenter )
    : angle(Vec2f::zero()),
    velocity( r.randFloat(-0.05f, 0.05f), r.randFloat(-0.05f, 0.05f) ),
    amplitude( r.randFloat( windowCenter.x ), r.randFloat( windowCenter.y ) ) {
    }
    void update();
    void draw() const;
};

#endif
