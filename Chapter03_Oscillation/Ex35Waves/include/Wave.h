//
//  Wave.h
//  Ex35Waves
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//  HWH Maintenance 8/17/13
//

#ifndef Ex35Waves_Wave_h
#define Ex35Waves_Wave_h

#include <vector>
#include "cinder/gl/gl.h"
#include "cinder/gl/FBO.h"
#include "cinder/Rand.h"
#include "WaveComponent.h"

using namespace ci;

class Wave {
    
public:
    Wave( const float width, const float height, const Vec2f& windowPosition_, const int numCircles, const float angVel );
    void update();
    void draw();
    
private:
    gl::Fbo window;
    const Vec2f windowPosition;
    std::vector< WaveComponent > circles;

};

#endif
