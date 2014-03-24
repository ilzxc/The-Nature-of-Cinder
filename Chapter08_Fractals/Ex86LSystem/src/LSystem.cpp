//
//  LSystem.cpp
//  Ex86LSystem
//
//  Created by Ilya Rostovtsev on 3/23/14.
//
//

#include "LSystem.h"

LSystem::LSystem( const string& axiom, const vector< Rule >& r )
: sentence( axiom ), ruleset( r ), generation( 0 )
{
}

void LSystem::generate()
{
    string nextGen;
    for ( auto i = 0; i < sentence.length(); ++i ) {
        char curr = sentence[ i ];
        string replace;
        replace.push_back( curr );
        for ( auto j = 0; j < ruleset.size(); ++j ) {
            char a = ruleset[ j ].getA();
            if ( a == curr ) {
                replace = ruleset[ j ].getB();
                break;
            }
        }
        nextGen.append( replace );
    }
    sentence = nextGen;
    ++generation;
}

string LSystem::getSentence() const
{
    return sentence;
}

int LSystem::getGeneration() const
{
    return generation;
}
