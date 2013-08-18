//
//  WaveComponent.h
//  Ex35Waves
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//  HWH Maintenance 8/17/13
//

#ifndef Ex35Waves_WaveComponent_h
#define Ex35Waves_WaveComponent_h

#include "cinder/gl/gl.h"

using namespace ci;

class WaveComponent {
public:
    WaveComponent( const Vec2f& p, const float r, const float a, const float startAngle, const float v );
    void update();
    void draw() const;

private:
    Vec2f position;
    float yOffset;
    const float radius;
    const float amplitude;
    float angle;
    float angleVelocity;
};

#endif
