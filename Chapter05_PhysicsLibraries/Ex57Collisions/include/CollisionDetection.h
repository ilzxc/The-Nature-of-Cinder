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
#include "Particle.h"

class CollisionDetection : public b2ContactListener {
public:
    void BeginContact( b2Contact *contact ) {
        void* objectA = contact->GetFixtureA()->GetBody()->GetUserData();
        void* objectB = contact->GetFixtureB()->GetBody()->GetUserData();
        if ( objectA && objectB ) { // if they are not NULL, we have particles!
            static_cast< Particle* >(objectA)->onTouch();
            static_cast< Particle* >(objectB)->onTouch();
        }
    }
    void EndContact ( b2Contact *contact ) {
        void* objectA = contact->GetFixtureA()->GetBody()->GetUserData();
        void* objectB = contact->GetFixtureB()->GetBody()->GetUserData();
        if ( objectA && objectB ) { // if they are not NULL, we have particles!
            static_cast< Particle* >(objectA)->offTouch();
            static_cast< Particle* >(objectB)->offTouch();
        }
    }
};

#endif
