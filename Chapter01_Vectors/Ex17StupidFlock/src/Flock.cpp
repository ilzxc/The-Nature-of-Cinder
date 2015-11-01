//
//  Flock.cpp
//  Ex17StupidFlock
//
//  Created by Ilya Rostovtsev on 10/31/15.
//
//

#include <thread>
#include "Flock.hpp"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;

Flock::Flock()
{
    auto random = Rand{};
    random.randomize();
    
    flockData.reserve( numBoids );
    auto lambert = gl::ShaderDef().lambert().color();
    auto shader = gl::getStockShader( lambert );
    
    for ( auto i = 0; i < numBoids; ++i ) {
        auto fatness = randFloat( 0.6f );
        flockData.emplace_back( fatness );
    
        auto boid = geom::Circle().radius( fatness * 10.f );
        flockBatch[ i ] = gl::Batch::create( boid, shader );
    }
    
    tt = new std::thread[ numThreads ];
    
}

void Flock::interact( const vec2& mousePosition )
{
    constexpr float maxAccel = 3.6f;
    for ( auto& boid : flockData ) {
        boid.acceleration = glm::normalize( mousePosition - boid.position ) * ( maxAccel - boid.fatness );
    }
}

void Flock::update()
{

    constexpr auto load = numBoids / numThreads;
 
    for ( auto i = 0; i < numThreads; ++i ) {
        std::cout << "thread #" << i << ": " << i * load << " --> " << i * load + load << std::endl;
        tt[ i ] = std::thread( [ this, i ] {
            for ( auto j = i * load; j < i * load + load; ++j ) {
                auto newVelocity = flockData[ j ].velocity + flockData[ j ].acceleration;
                flockData[ j ].velocity = glm::clamp( newVelocity, -20.f, 20.f );
                flockData[ j ].position += flockData[ j ].velocity;
            }
        });
    }
    
    for ( auto i = 0; i < numThreads; ++i ) {
        tt[ i ].join();
    }


/*
    for ( auto& boid : flockData ) {
        auto newVelocity = boid.velocity + boid.acceleration;
        boid.velocity = glm::clamp( newVelocity, -20.f, 20.f );
        boid.position += boid.velocity;
    }
*/
}

void Flock::draw() const
{
    for ( auto i = 0; i < flockData.size(); ++i ) {
        gl::ScopedModelMatrix smm;
        gl::translate( flockData[ i ].position );
        flockBatch[ i ]->draw();
    }
}