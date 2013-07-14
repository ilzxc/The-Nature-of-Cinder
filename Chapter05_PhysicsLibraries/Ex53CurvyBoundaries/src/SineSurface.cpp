//
//  SineSurface.cpp
//  Ex53CurvyBoundaries
//
//  Created by Ilya Rostovtsev on 7/14/13.
//
//

#include "SineSurface.h"

SineSurface::SineSurface( int s ) {
    float subdiv = s;
    float pixelWidth = app::getWindowWidth();
    float step = pixelWidth / subdiv; // this many pixel segments...
    float radPerStep = 3.141592653589793 * 3.0f / subdiv;
    float elevation = 100.0f;
    
    for (int i = 0; i <= subdiv; ++i) {
        float x = i * step;
        float y = 3.0 * app::getWindowHeight() / 4.0 - sin( i * radPerStep ) * elevation;
        pointsForBox2D.push_back( Vec2f( x, y ) );
    }
}

std::vector<Vec2f> SineSurface::getPoints() const {
    return pointsForBox2D;
}
