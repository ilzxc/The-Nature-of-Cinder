//
//  FlowField.h
//  Ex64FlowFieldFollowing
//
//  Created by Ilya Rostovtsev on 7/16/13.
//
//

#ifndef Ex64FlowFieldFollowing_FlowField_h
#define Ex64FlowFieldFollowing_FlowField_h

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/Perlin.h"

using namespace ci;

class FlowField {
    
public:
	FlowField( int r );
            
    void init();
    Vec2f lookup( const Vec2f& lookUp ) const;
    void draw() const;
    
private:
	std::vector< std::vector< Vec2f > > field;
	int resolution;
	Perlin perlin;

	void drawVector( const Vec2f& vec, const Vec2f& position, float scale ) const;
};

#endif