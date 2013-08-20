//
//  WaveComponent.cpp
//  Ex35Waves
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//  HWH Maintenance 8/17/13
//

#include "WaveComponent.h"

WaveComponent::WaveComponent( const Vec2f& position_, const float radius_, const float amplitude_, const float angle_, const float angleVelocity_ )
: position( position_ ),
  yOffset( position.y ),
  radius( radius_ ),
  amplitude( amplitude_ ),
  angle( angle_ ),
  angleVelocity( angleVelocity_ )
{ }

void WaveComponent::update()
{
    angle += angleVelocity;
    position.y = sin( angle ) * amplitude + yOffset;
}

void WaveComponent::draw() const
{
    gl::drawSolidCircle( position, radius );
}