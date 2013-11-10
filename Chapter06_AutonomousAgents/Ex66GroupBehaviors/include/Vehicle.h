//
//  Vehicle.h
//  Ex66GroupBehaviors
//
//  Created by Ilya Rostovtsev on 11/8/13.
//
//

#ifndef Ex66GroupBehaviors_Vehicle_h
#define Ex66GroupBehaviors_Vehicle_h

#include "cinder/gl/gl.h"
#include "Path.h"

using namespace ci;

class Vehicle
{
    
public:
    Vehicle( const Vec2f& loc, const float ms, const float mf );
    
    void update( const std::vector< Vehicle >& vehicles, const Path& path );
    void draw() const;
    const Vec2f& getLocation() const;
    
private:
    Vec2f location;
    Vec2f velocity;
    Vec2f acceleration;
    float r;
    float maxForce;
    float maxSpeed;
    
    void applyBehaviors( const std::vector< Vehicle >& vehicles, const Path& path );
    void applyForce( const Vec2f& force );
    Vec2f follow( const Path& p ) const;
    Vec2f separate( const std::vector< Vehicle >& vehicles ) const;
    Vec2f getNormalPoint( const Vec2f& p, const Vec2f& a, const Vec2f b ) const;
    Vec2f seek( const Vec2f& target ) const;
    void borders();
    
};

#endif
