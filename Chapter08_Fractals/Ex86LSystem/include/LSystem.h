//
//  LSystem.h
//  Ex86LSystem
//
//  Created by Ilya Rostovtsev on 3/23/14.
//
//

#ifndef __Ex86LSystem__LSystem__
#define __Ex86LSystem__LSystem__

#include <vector>
#include <string>
#include "Rule.h"

using namespace std;

class LSystem
{
  public:
    LSystem( const string& axiom, const vector< Rule >& r );
    void generate();
    string getSentence() const;
    int getGeneration() const;
    
  private:
    string sentence;
    vector< Rule > ruleset;
    int generation;
    
};

#endif /* defined(__Ex86LSystem__LSystem__) */
