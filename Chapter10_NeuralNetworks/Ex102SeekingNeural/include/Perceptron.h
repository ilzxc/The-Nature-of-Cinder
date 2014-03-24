//
//  Perceptron.h
//  Ex102SeekingNeural
//
//  Created by Ilya Rostovtsev on 3/24/14.
//
//

#ifndef __Ex102SeekingNeural__Perceptron__
#define __Ex102SeekingNeural__Perceptron__

#include <vector>
#include "cinder/Rand.h"

using namespace std;
using namespace ci;

class Perceptron
{
  public:
    Perceptron( const int n, const float c, shared_ptr< Rand > random );
    void train( const vector< Vec2f >& forces, const Vec2f& error );
    Vec2f feedforward( const vector< Vec2f >& forces );
    
  private:
    vector< float > weights;
    float c;
    
};

#endif /* defined(__Ex102SeekingNeural__Perceptron__) */
