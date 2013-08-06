//
//  ObjectType.h
//  Ex58AdvancedCollisions
//
//  Created by Ilya Rostovtsev on 7/28/13.
//
//

#ifndef Ex58AdvancedCollisions_ObjectType_h
#define Ex58AdvancedCollisions_ObjectType_h

enum ParticleTypes { // what types of shapes we need to keep track of
    SQUARE_PARTICLE,
    CIRCLE_PARTICLE,
    TRIANGLE_PARTICLE
};

class ObjectType {
public:
    int kind;       // what kind of object is it?
    void *object;   // pointer to the object ( set with "this" )
    
    ObjectType( int _kind, void* _object ): kind( _kind ), object( _object ) { } // extremely simple
};

#endif
