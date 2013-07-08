//
//  WaveComponent.h
//  Ex35Waves
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//

#ifndef Ex35Waves_WaveComponent_h
#define Ex35Waves_WaveComponent_h

#include "cinder/gl/gl.h"

using namespace ci;

class WaveComponent {
private:
    Vec2f position;
    float yOffset;
    float radius;
    float amplitude;
    float angle;
    float angleVelocity;
    
public:
    WaveComponent() { }
    WaveComponent( const Vec2f& p, const float r, const float a, const float startAngle, const float v )
    : position( p ),
      yOffset( position.y ),
      radius( r ),
      amplitude( a ),
      angle( startAngle ),
      angleVelocity( v ) { }
    void update();
    void draw() const;
};

#endif
