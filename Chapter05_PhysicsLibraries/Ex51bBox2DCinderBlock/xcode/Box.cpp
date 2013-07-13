//
//  Box.cpp
//  Ex51aBox2DCustom
//
//  Created by Ilya Rostovtsev on 7/9/13.
//
//

#include "Box.h"


void Box::update(b2World * world){
    position = Conversions::toScreen( body->GetPosition() );
    angle = toDegrees( body->GetAngle() );
}

void Box::draw() const {
    gl::color( 127.0f/255, 127.0f/255, 127.0f/255 );
    gl::pushMatrices();
    gl::translate( position );
    gl::rotate( angle );
    gl::drawSolidRect( bounds );
    gl::popMatrices();
}

bool Box::isDead() {
    if( position.y > app::getWindowHeight() ) {
        return true;
    }
    
    return false;
}

b2Body* Box::getBody() {
    return body;
}