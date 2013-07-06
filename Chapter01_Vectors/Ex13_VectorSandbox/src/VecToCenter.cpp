//
//  VecToCenter.cpp
//  Ex13_VectorSandbox
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//

#include "VecToCenter.h"

void VecToCenter::setCenter(const Vec2f& newCenter) {
    centerPoint = newCenter;
}

void VecToCenter::setActive(const bool newActive) {
    active = newActive;
}

void VecToCenter::update(Vec2f current) {
    endPoint = current;
    magnitude = (endPoint - centerPoint).length();
}

void VecToCenter::draw() {
    if (active) {
        cinder::gl::color( 1.0, 0.0, 0.7, 1.0 );
        cinder::gl::drawLine( centerPoint, endPoint );
        cinder::gl::color( 0.4, 0.4, 0.4 );
        cinder::gl::drawLine( ci::Vec2f(0, 0), endPoint );
        cinder::gl::drawLine( ci::Vec2f(0, ci::app::getWindowHeight()), endPoint );
        cinder::gl::drawLine( ci::Vec2f(ci::app::getWindowWidth(), 0), endPoint );
        cinder::gl::drawLine( ci::Vec2f(ci::app::getWindowWidth(), ci::app::getWindowHeight()), endPoint );
        
        cinder::gl::color( 1.0, 0.0, 0.7, 1.0 );
        cinder::gl::drawSolidRect( ci::Rectf(0.0f, 0.0f, magnitude, 10.0f) );
    } else {
        cinder::gl::color( 0.0, 0.7, 1.0, 1.0 );
        cinder::gl::pushMatrices();
        cinder::gl::translate( centerPoint );
        cinder::gl::drawLine( ci::Vec2f(0, 0), (endPoint - centerPoint).normalized() * 100 );
        cinder::gl::popMatrices();
    }
}