//
//  Vehicle.h
//  Ex102SeekingNeural
//
//  Created by Ilya Rostovtsev on 3/24/14.
//
//

#ifndef __Ex102SeekingNeural__Vehicle__
#define __Ex102SeekingNeural__Vehicle__

#include <vector>
#include "Perceptron.h"

using namespace std;
using namespace ci;

class Vehicle
{
public:
    Vehicle( const int n, const float x, const float y, shared_ptr< Rand > random );
    void update();
    void draw() const;
    void applyForce( const Vec2f& force );
    void steer( const vector< Vec2f >& targets );
    Vec2f seek( const Vec2f& target );
    
private:
    Perceptron brain;
    Vec2f location;
    Vec2f velocity;
    Vec2f acceleration;
    Vec2f desired;
    float r, maxforce, maxspeed, theta;
    
};

#endif /* defined(__Ex102SeekingNeural__Vehicle__) */
