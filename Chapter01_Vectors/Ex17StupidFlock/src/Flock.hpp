//
//  Flock.hpp
//  Ex17StupidFlock
//
//  Created by Ilya Rostovtsev on 10/31/15.
//
//

#ifndef Flock_hpp
#define Flock_hpp

#include "cinder/vector.h"
#include "cinder/gl/gl.h"

namespace cinder { class Rand; }

class Flock {
  public:
    Flock();
    
    void interact( const ci::vec2& mousePosition );
    void update();
    void draw() const;
    
  private:
    static constexpr int numBoids = 8000;
    struct BoidData {
        BoidData( float fatness ): fatness{ fatness } { }
        ci::vec2 position;
        ci::vec2 velocity;
        ci::vec2 acceleration;
        float fatness;
    };
    std::vector< BoidData > flockData;
    ci::gl::BatchRef flockBatch[ numBoids ];
};

#endif /* Flock_hpp */
