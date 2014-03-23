//
//  CA.h
//  Ex71ElementaryCellularAutomata
//
//  Created by Ilya Rostovtsev on 8/4/13.
//
//

#ifndef Ex71ElementaryCellularAutomata_CA_h
#define Ex71ElementaryCellularAutomata_CA_h

#include <vector>
#include "cinder/gl/gl.h"

using namespace ci;

class CA {
    
  public:
    CA( const int _ruleset[ 8 ] );
    ~CA();
    void restart();
    void generate();
    void update();
    void draw() const;
    
  private:
    int  generation;
    int  ruleset[ 8 ];
    int  radius;
    int* matrix; // history of generations
    int  columns;
    int  rows;
    int  rules( const int a, const int b, const int c ) const;
    bool finished() const;

};

#endif
