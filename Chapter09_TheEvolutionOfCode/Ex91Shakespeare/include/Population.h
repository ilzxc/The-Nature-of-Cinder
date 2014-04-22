//
//  Population.h
//  Ex91Shakespeare
//
//  Created by Ilya Rostovtsev on 12/25/13.
//
//

#ifndef Ex91Shakespeare_Population_h
#define Ex91Shakespeare_Population_h

#include "DNA.h"
#include "cinder/Rand.h"
#include "math.h"

class Population
{
    
  public:
    Population( const std::vector< char >& _target, const float m, const int num, std::shared_ptr< ci::Rand > rand );
    
    
    void natural_selection();
    std::vector< char > get_best();
    bool is_finished() const;
    int get_generations() const;
    float get_average_fiteness() const;
    std::vector< char > all_phrases() const;
    
  private:
    const float mutation_rate;
    std::vector< std::shared_ptr< DNA > > population;
    std::vector< std::shared_ptr< DNA > > mating_pool;
    std::vector< char > target;
    int generations;
    bool finished;
    int perfect_score;
    std::shared_ptr< ci::Rand > random;
    
    void generate();
    void compute_fitness();
};


#endif
