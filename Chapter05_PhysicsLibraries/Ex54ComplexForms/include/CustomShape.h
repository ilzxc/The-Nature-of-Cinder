//
//  CustomShape.h
//  Ex54ComplexForms
//
//  Created by Ilya Rostovtsev on 7/16/13.
//
//

#ifndef Ex54ComplexForms_CustomShape_h
#define Ex54ComplexForms_CustomShape_h

#pragma once
#include "Box2D/Box2D.h"
#include "Conversions.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;

class CustomShape {
private:
    b2Body *body;
    std::vector< Vec2f > polygon;
    Vec2f startPoint;
    Vec2f position;
    float angle;
    
public:
    CustomShape() { }
    CustomShape( b2World *world, const Vec2f& where );
    void update( b2World *world );
    void draw() const;
    bool isDead() const;
    void killBody( b2World *world );
};

#endif
