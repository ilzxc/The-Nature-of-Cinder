//
//  WaveComponent.cpp
//  Ex35Waves
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//

#include "WaveComponent.h"

void WaveComponent::update() {
    angle += angleVelocity;
    position.y = sin(angle) * amplitude + yOffset;
}

void WaveComponent::draw() const {
    gl::drawSolidCircle( position, radius );
}