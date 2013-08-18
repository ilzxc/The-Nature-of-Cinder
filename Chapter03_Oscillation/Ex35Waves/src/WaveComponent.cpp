//
//  WaveComponent.cpp
//  Ex35Waves
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//  HWH Maintenance 8/17/13
//

#include "WaveComponent.h"

WaveComponent::WaveComponent( const Vec2f& p, const float r, const float a, const float startAngle, const float v )
: position( p ),
  yOffset( position.y ),
  radius( r ),
  amplitude( a ),
  angle( startAngle ),
  angleVelocity( v )
{ }

void WaveComponent::update() {
    angle += angleVelocity;
    position.y = sin( angle ) * amplitude + yOffset;
}

void WaveComponent::draw() const {
    gl::drawSolidCircle( position, radius );
}