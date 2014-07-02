//
//  Rocket.h
//  Ex92SimpleSmartRockets
//
//  Created by Ilya Rostovtsev on 4/22/14.
//
//

#ifndef __Ex92SimpleSmartRockets__Rocket__
#define __Ex92SimpleSmartRockets__Rocket__

#include "cinder/Vector.h"
#include "cinder/gl/gl.h"
#include "DNA.h"
#include "Obstacle.h"

using namespace std;
using namespace ci;

class Rocket
{
  public:
    Rocket( const Vec2f& set_location, shared_ptr< DNA > set_dna, int total_rockets );
    ~Rocket();
    
    void compute_fitness();
    void run( const vector< shared_ptr< Obstacle > >& obstacles );
    void check_target( const shared_ptr< Obstacle > target );
    void check_obstacles( const vector< shared_ptr< Obstacle > >& obstacles );
    void apply_force( const Vec2f& f );
    void update();
    void draw() const;
    float get_fitness() const;
    shared_ptr< DNA > get_dna() const;
    bool stopped() const;
    inline bool get_hit_target() const { return hit_target; }
    
    
  private:
    Vec2f location;
    Vec2f velocity;
    Vec2f acceleration;
    float radius;
    float record_distance;
    float fitness;
    shared_ptr< DNA > dna;
    shared_ptr< Rand > random;
    float theta;
    Vec2f rocket_triangle_points[ 3 ];
    int gene_counter;
    bool hit_obstacle;
    bool hit_target;
    int finish_time;
};

#endif /* defined(__Ex92SimpleSmartRockets__Rocket__) */
