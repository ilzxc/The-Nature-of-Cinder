//
//  GOL.h
//  Ex72GameOfLife
//
//  Created by Ilya Rostovtsev on 11/11/13.
//
//

#ifndef __Ex72GameOfLife__GOL__
#define __Ex72GameOfLife__GOL__

#include "Cell.h"
#include "cinder/gl/gl.h"

using namespace std;
using namespace ci;

class GOL
{
    
public:
    GOL();
    ~GOL();
    
    void init();
    void generate();
    void draw() const;
    
private:
    Rand random;
    const int w = 5;
    int columns, rows;
    vector< vector< Cell > > board;
    
};

#endif /* defined(__Ex72GameOfLife__GOL__) */