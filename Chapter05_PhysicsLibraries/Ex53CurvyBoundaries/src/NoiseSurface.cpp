//
//  NoiseSurface.cpp
//  Ex53CurvyBoundaries
//
//  Created by Ilya Rostovtsev on 7/14/13.
//
//

#include "NoiseSurface.h"

NoiseSurface::NoiseSurface( int s ) {
    float subdiv = s;
    float pixelWidth = app::getWindowWidth();
    float step = pixelWidth / subdiv;
    
    float xoff = 0.0f;
    for (int i = 0; i <= subdiv; ++i) {
        float x = i * step;
        float y;
        if (x > app::getWindowWidth() / 2.0) {
            y = 200 + (app::getWindowWidth() - x) * 1.1 + ( -80 + (160.0 * p.noise(xoff) ) );
        }
        else {
            y = 200 + x * 1.1 + ( p.noise(xoff) * 80 - 40 );
        }
        
        xoff += 0.1f;
        // float y = (3 * app::getWindowHeight() / 4.0f ) - p.noise( x ) * elevation;
        pointsForBox2D.push_back( Vec2f( x, y ) );
    }
}

std::vector<Vec2f> NoiseSurface::getPoints() const {
    return pointsForBox2D;
}