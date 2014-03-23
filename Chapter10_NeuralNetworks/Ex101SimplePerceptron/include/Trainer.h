//
//  Trainer.h
//  Ex101SimplePerceptron
//
//  Created by Ilya Rostovtsev on 3/23/14.
//
//

#ifndef __Ex101SimplePerceptron__Trainer__
#define __Ex101SimplePerceptron__Trainer__

#include <vector>

using namespace std;

// Simple Perceptron Example
// See: http://en.wikipedia.org/wiki/Perceptron
// A class to describe a training point
// Has an x and y, a "bias" (1) and known output
// Could also add a variable for "guess" but not required here
struct Trainer
{
    Trainer( const float x, const float y, const int a ): inputs{ x, y, 1 }, answer( a ) { }
    vector< float > inputs;
    int answer;
};

#endif /* defined(__Ex101SimplePerceptron__Trainer__) */
