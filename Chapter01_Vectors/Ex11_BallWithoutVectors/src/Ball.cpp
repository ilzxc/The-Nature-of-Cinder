//
//  Ball.cpp
//  Ex11_BallWithoutVectors
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//

#include "Ball.h"

void Ball::update() {
    x += xSpeed;
    y += ySpeed;
    if ( ( x < cRadius ) || (x > (app::getWindowWidth() - cRadius) ) ) {
        xSpeed *= -1;
    }
    if ( ( y < cRadius ) || (y > (app::getWindowHeight() - cRadius) ) ) {
        ySpeed *= -1;
    }
}

void Ball::draw() {
    gl::color(0.0f, green, 1.0f, 1.0f);
    gl::drawSolidCircle( Vec2f(x, y), cRadius);
}