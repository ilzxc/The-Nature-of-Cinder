//
//  CollisionDetection.h
//  Ex57Collisions
//
//  Created by Ilya Rostovtsev on 7/25/13.
//
//

#ifndef Ex57Collisions_CollisionDetection_h
#define Ex57Collisions_CollisionDetection_h

#pragma once
#include "Box2D/Box2D.h"
#include "ObjectType.h"
#include "Circle.h"
#include "Square.h"
#include "Triugolnik.h"

class CollisionDetection : public b2ContactListener {
public:
    void BeginContact( b2Contact *contact );
    
private:
    void ConvertAndExecute( ObjectType* currentObject, const int otherObjectKind );
};

#endif
