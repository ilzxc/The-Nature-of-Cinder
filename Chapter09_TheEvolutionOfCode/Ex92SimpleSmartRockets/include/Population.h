//
//  Population.h
//  Ex92SimpleSmartRockets
//
//  Created by Ilya Rostovtsev on 4/22/14.
//
//

#ifndef __Ex92SimpleSmartRockets__Population__
#define __Ex92SimpleSmartRockets__Population__

#include "Rocket.h"

class Population
{
public:
    Population( const float m, const int num, const int lifetime, shared_ptr< Rand > random );
    void live( const vector< shared_ptr< Obstacle > > obstacles, const shared_ptr< Obstacle > target );
    bool target_reached() const;
    void fitness();
    void selection();
    void reproduction();
    int get_generations() const;
    float get_max_fitness() const;
    
private:
    float mutation_rate;
    vector< shared_ptr< Rocket > > population;
    vector< shared_ptr< Rocket > > mating_pool;
    int generations;
    shared_ptr< Rand > random;
    const Vec2f location;
    
};

#endif /* defined(__Ex92SimpleSmartRockets__Population__) */
