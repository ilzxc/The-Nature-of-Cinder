//
//  Wave.h
//  Ex35Waves
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
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
private:
    gl::Fbo window;
    Vec2f windowPosition;
    std::vector<WaveComponent> circles;
    
public:
    Wave() { }
    Wave( const float width, const float height, const Vec2f& winPos, const int numCircles, const float angVel )
    : window( width, height ), windowPosition( winPos ) {
        float startAngle = 0.0f;
        float setRadius = width / numCircles;
        float setSkip = width / (numCircles - 1);
        float setYOffset = height / 2.0f;
        float setAmplitude = setYOffset * 0.88f;
        for (int i = 0; i < numCircles; ++i) {
            circles.push_back( WaveComponent( Vec2f(setSkip * (i), setYOffset ), setRadius, setAmplitude, startAngle + angVel * 2 * i, angVel / 2 ) );
        }
    }
    void update();
    void draw();
};

#endif
