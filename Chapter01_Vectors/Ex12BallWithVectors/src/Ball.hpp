//
//  Ball.hpp
//  Ex12BallWithVectors
//
//  Created by Ilya Rostovtsev on 10/31/15.
//
//

#ifndef Ball_hpp
#define Ball_hpp

#include "cinder/vector.h"
using namespace ci;

class Ball {
  public:
    Ball( const vec2& position = vec2{ 0.f, 0.f } ); // vector constructor
    Ball( const Ball& other ); // copy constructor
    Ball& operator=( const Ball& other ); // copy assignment
    
    void update();
    void draw() const;
    
  private:
    vec2 position;
    vec2 velocity;
    float radius;
};

#endif /* Ball_hpp */
