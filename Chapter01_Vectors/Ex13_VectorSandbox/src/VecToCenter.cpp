//
//  VecToCenter.cpp
//  Ex13_VectorSandbox
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//  HWH Maintenance 8/17/13
//

#include "VecToCenter.h"

VecToCenter::VecToCenter( const bool _active, const Vec2f &_centerPoint )
: active{ _active },
  magnitude{ 0.0f },
  centerPoint{ _centerPoint },
  endPoint{ Vec2f::zero() }
{ }

void VecToCenter::setCenter( const Vec2f& newCenter )
{
    centerPoint = newCenter;
}

void VecToCenter::setActive( const bool newActive )
{
    active = newActive;
}

void VecToCenter::update( const Vec2f& current )
{
    endPoint = current;
    magnitude = ( endPoint - centerPoint ).length();
}

void VecToCenter::draw() const
{
    if ( active ) {
        gl::color( 1.0f, 0.0f, 0.7f );
        gl::drawLine( centerPoint, endPoint );
        gl::color( 0.4f, 0.4f, 0.4f );
        gl::drawLine( Vec2f::zero(), endPoint );
        gl::drawLine( Vec2f{ 0.0f, app::getWindowHeight() }, endPoint );
        gl::drawLine( Vec2f{ app::getWindowWidth(), 0.0f }, endPoint );
        gl::drawLine( Vec2f{ app::getWindowWidth(), app::getWindowHeight() }, endPoint );
        gl::color( 1.0f, 0.0f, 0.7f );
        gl::drawSolidRect( ci::Rectf{ 0.0f, 0.0f, magnitude, 10.0f } );
    } else {
        gl::color( 0.0f, 0.7f, 1.0f );
        gl::pushMatrices();
        gl::translate( centerPoint );
        gl::drawLine( Vec2f::zero(), ( endPoint - centerPoint ).normalized() * 100 );
        gl::popMatrices();
    }
}