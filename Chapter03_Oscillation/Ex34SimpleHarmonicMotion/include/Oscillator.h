//
//  Oscillator.h
//  Ex34SimpleHarmonicMotion
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//  HWH Maintenance 8/17/13
//

#ifndef Ex34SimpleHarmonicMotion_Oscillator_h
#define Ex34SimpleHarmonicMotion_Oscillator_h

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;

class Oscillator {
    
public:
    Oscillator( Rand& r, const Vec2f& windowCenter );
    void update();
    void draw() const;
    
private:
    Vec2f angle;
    Vec2f velocity;
    Vec2f amplitude;
    Vec2f display;

};

#endif
