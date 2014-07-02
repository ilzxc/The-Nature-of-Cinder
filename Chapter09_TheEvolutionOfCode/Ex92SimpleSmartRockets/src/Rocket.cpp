//
//  Rocket.cpp
//  Ex92SimpleSmartRockets
//
//  Created by Ilya Rostovtsev on 4/22/14.
//
//

#include "Rocket.h"

Rocket::Rocket( const Vec2f& set_location, shared_ptr< DNA > set_dna, int total_rockets )
: acceleration(),
  velocity(),
  location( set_location ),
  radius( 8.f ),
  dna( set_dna ),
  finish_time( 0 ),
  record_distance( 10000 ),
  rocket_triangle_points{ Vec2f( 0.f, -radius * 2.f ), Vec2f( -radius, radius * 2.f ), Vec2f( radius, radius * 2.f ) }
{
    
}

void Rocket::compute_fitness()
{
    if ( record_distance < 1 ) {
        record_distance = 1;
    }
    
    fitness = ( 1.f / ( finish_time * record_distance ) );
    fitness = powf( fitness, 4 );
    
    if ( hit_obstacle ) {
        fitness *= 0.1;
    }
    
    if ( hit_target ) {
        fitness *= 2;
    }
}

void Rocket::run( const vector< shared_ptr< Obstacle > >& obstacles )
{
    if ( ( ! hit_obstacle ) && ( ! hit_target ) ) {
        apply_force( dna->get_gene( gene_counter ) );
        gene_counter = ( gene_counter + 1 ) % dna->get_genes_length();
        update();
        check_obstacles( obstacles );
        theta = toDegrees( atan2f( velocity.y, velocity.x ) );
    }
}

void Rocket::check_target( const shared_ptr< Obstacle > target )
{
    float d = location.distance( target->get_location() );
    if ( d < record_distance ) {
        record_distance = d;
    }

    if ( target->contains( location ) && ( ! hit_target ) ) {
        hit_target = true;
    } else if ( ! hit_target ) {
        ++finish_time;
    }
}

void Rocket::check_obstacles( const vector< shared_ptr< Obstacle > >& obstacles )
{
    for ( auto obstacle : obstacles ) {
        if ( obstacle->contains( location ) ) {
            hit_obstacle = true;
        }
    }
}

void Rocket::apply_force( const Vec2f& f )
{
    acceleration += f;
}

void Rocket::update()
{
    velocity += acceleration;
    location += velocity;
    acceleration.set( Vec2f::zero() );
}

void Rocket::draw() const
{
    gl::color( 0.683f, 0.683f, 0.683f );
    gl::pushMatrices();
    gl::translate( location );
    gl::rotate( theta );
    gl::drawSolidTriangle( rocket_triangle_points );
    gl::popMatrices();
}

float Rocket::get_fitness() const{
    return fitness;
}

shared_ptr< DNA > Rocket::get_dna() const{
    return dna;
}

bool Rocket::stopped() const
{
    return hit_obstacle;
}