//
//  Ball.hpp
//  Ex11BallWithoutVectors
//
//  Created by Ilya Rostovtsev on 10/31/15.
//
//

#ifndef Ball_hpp
#define Ball_hpp

namespace cinder {
    class Rand;
}

class Ball {
    
public:
    constexpr Ball(): x{ 0.f }, y{ 0.f }, x_velocity{ 0.f }, y_velocity{ 0.f }, radius{ 20.f } { }
    Ball( const float x, const float y, const ci::Rand& r );
    
    void update();
    void draw() const;
    
private:
    float x, y;
    float x_velocity, y_velocity;
    float radius;
};

#endif /* Ball_hpp */
