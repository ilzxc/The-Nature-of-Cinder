//
//  vecToCenter.cpp
//  Ex1_3_VectorSandbox
//
//  Created by Ilya Rostovtsev on 4/7/13.
//
//

#include "vecToCenter.h"

vecToCenter::vecToCenter( bool setActive ) {
    active = setActive;
    magnitude = 0;
}

void vecToCenter::setCenterPoint( ci::Vec2f center ) {
    centerPoint = center;
}

void vecToCenter::update( ci::Vec2f mouseLocation) {
    endPoint = mouseLocation;
    magnitude = (endPoint - centerPoint).length();
}

void vecToCenter::draw() {
    if (active) {
        cinder::gl::color( 1.0, 0.0, 0.7, 1.0 );
        cinder::gl::drawLine( centerPoint, endPoint );
        cinder::gl::drawLine( ci::Vec2f(0, 0), endPoint );
        cinder::gl::drawLine( ci::Vec2f(0, ci::app::getWindowHeight()), endPoint );
        cinder::gl::drawLine( ci::Vec2f(ci::app::getWindowWidth(), 0), endPoint );
        cinder::gl::drawLine( ci::Vec2f(ci::app::getWindowWidth(), ci::app::getWindowHeight()), endPoint );
        
        cinder::gl::color(0.4, 0.4, 0.4, 0.4);
        cinder::gl::drawSolidRect( ci::Rectf(0.0f, 0.0f, magnitude, 10.0f) );
    } else {
        cinder::gl::color( 0.0, 0.7, 1.0, 1.0 );
        cinder::gl::pushMatrices();
        cinder::gl::translate( centerPoint );
        cinder::gl::drawLine( ci::Vec2f(0, 0), (endPoint - centerPoint).normalized() * 100 );
        cinder::gl::popMatrices();
        
    }
    
}