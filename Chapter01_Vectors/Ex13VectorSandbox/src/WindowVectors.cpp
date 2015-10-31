//
//  WindowVectors.cpp
//  Ex13VectorSandbox
//
//  Created by Ilya Rostovtsev on 10/31/15.
//
//

#include "WindowVectors.hpp"
#include "cinder/gl/gl.h"

using namespace ci;

WindowVectors::WindowVectors( const vec2& centerPoint )
: centerPoint{ centerPoint },
  endPoint{ 0.f, 0.f }
{ }

void WindowVectors::setCenter( const vec2& newCenter )
{
    centerPoint = newCenter;
}

void WindowVectors::update( const vec2& current )
{
    endPoint = current;
}

void WindowVectors::draw() const
{
    gl::color( 1.f, 0.f, 0.7f );
    gl::drawLine( centerPoint, endPoint ); 
    gl::color( 0.4f, 0.4f, 0.4f );
    /// drawing in absolute screen coordinates:
    gl::drawLine( vec2{}, endPoint );
    gl::drawLine( vec2{ 0.f, app::getWindowHeight() }, endPoint );
    gl::drawLine( vec2{ app::getWindowWidth(), 0.f }, endPoint );
    gl::drawLine( vec2{ app::getWindowWidth(), app::getWindowHeight() }, endPoint );
    
    /// drawing vector magnitude:
    gl::color( 1.0f, 0.0f, 0.7f );
    gl::drawSolidRect( Rectf( 0.f, 0.f, glm::length( endPoint - centerPoint ), 10.f ) );
    
    /// drawing a magnitude vector using relative coordinates:
    gl::color( 0.0f, 0.7f, 1.0f, 0.5f );
    gl::pushMatrices();
    gl::translate( centerPoint );
    gl::drawLine( vec2{}, glm::normalize( endPoint - centerPoint ) * 100.f );
    gl::popMatrices();
}