//
//  DNA.h
//  Ex92SimpleSmartRockets
//
//  Created by Ilya Rostovtsev on 4/22/14.
//
//

#ifndef __Ex92SimpleSmartRockets__DNA__
#define __Ex92SimpleSmartRockets__DNA__

#include "cinder/Rand.h"

using namespace std;
using namespace ci;

class DNA
{
public:
    DNA( const int lifetime, shared_ptr< Rand > random );
    DNA( const vector< Vec2f >& new_genes, shared_ptr< Rand > random );
    
    shared_ptr< DNA > crossover( const shared_ptr< DNA > partner );
    void mutate( const float m );
    inline const Vec2f& get_gene( const int index ) { return genes[ index ]; }
    inline const int get_genes_length() { return genes.size(); }
    
private:
    vector< Vec2f > genes;
    float max_force;
    shared_ptr< Rand > rand;
};

#endif /* defined(__Ex92SimpleSmartRockets__DNA__) */
