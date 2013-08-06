//
//  CollisionDetection.cpp
//  Ex58AdvancedCollisions
//
//  Created by Ilya Rostovtsev on 8/6/13.
//
//

#include "CollisionDetection.h"

void CollisionDetection::BeginContact( b2Contact *contact ) {
    // like before, get objects that are colliding:
    void* objectA = contact->GetFixtureA()->GetBody()->GetUserData();
    void* objectB = contact->GetFixtureB()->GetBody()->GetUserData();
    if ( objectA && objectB ) { // if they are BOTH not NULL, two valid "ObjectTypes" collided...
        ObjectType* ObjectA = static_cast< ObjectType* >(objectA);
        ObjectType* ObjectB = static_cast< ObjectType* >(objectB);
        
        if( ObjectA->kind != ObjectB->kind ) { // we only care about different kinds of objects colliding
            ConvertAndExecute( ObjectA, ObjectB->kind );
            ConvertAndExecute( ObjectB, ObjectA->kind );
        }
    }
}

// The following method casts the void* pointer according to what object type that is, and executes
// the collision function inside the collidable pair.


void CollisionDetection::ConvertAndExecute( ObjectType* currentObject, const int otherObjectKind ) {
    switch( currentObject->kind ) {
        case CIRCLE_PARTICLE:
            static_cast< Circle* >( currentObject->object )->onCollisionWith( otherObjectKind );
            break;
        case SQUARE_PARTICLE:
            static_cast< Square* >( currentObject->object )->onCollisionWith( otherObjectKind );
            break;
        case TRIANGLE_PARTICLE:
            static_cast< Triugolnik* >( currentObject->object )->onCollisionWith( otherObjectKind );
            break;
        default:
            std::cout << "Oops, something went wrong, incompatible 'kind' set in ObjectType." << std::endl;
            break;
    }
}