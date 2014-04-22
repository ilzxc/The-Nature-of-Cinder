//
//  DNA.h
//  Ex91Shakespeare
//
//  Created by Ilya Rostovtsev on 12/25/13.
//
//

#ifndef Ex91Shakespeare_DNA_h
#define Ex91Shakespeare_DNA_h

#include <vector>
#include "cinder/Rand.h"

class DNA
{
    
  public:
    DNA();
    DNA( const int num, std::shared_ptr< ci::Rand > random );
    std::vector< char > get_phrase() const;
    void compute_fitness( const std::vector< char >& target );
    float get_fitness() const;
    std::shared_ptr< DNA > crossover( const std::shared_ptr< DNA > partner );
    void mutate( const float mutation_rate );
    void set_gene( const char value );
    
  private:
    std::vector< char > genes;
    float fitness;
    std::shared_ptr< ci::Rand > random;

};

#endif
