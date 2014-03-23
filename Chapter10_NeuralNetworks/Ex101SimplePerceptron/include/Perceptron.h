//
//  Perceptron.h
//  Ex101SimplePerceptron
//
//  Created by Ilya Rostovtsev on 3/23/14.
//
//

#ifndef __Ex101SimplePerceptron__Perceptron__
#define __Ex101SimplePerceptron__Perceptron__

#include <vector>
#include "cinder/Rand.h"

using namespace std;

class Perceptron
{
  public:
    Perceptron( const int n, const float c_, shared_ptr< ci::Rand > random );
    
    void train( const vector< float >& inputs, const int desired );
    int feedforward( const vector< float >& inputs ) const;
    int activate( const float sum ) const;
    vector< float > getWeights() const;
    
    
  private:
    vector< float > weights;    // array of weights for inputs
    float c;                    // learning constant
};

#endif /* defined(__Ex101SimplePerceptron__Perceptron__) */
