//
//  Conversions.h
//  Ex51aBox2DCustom
//
//  Created by Ilya Rostovtsev on 7/12/13.
//
//

#ifndef Ex51aBox2DCustom_Conversions_h
#define Ex51aBox2DCustom_Conversions_h

#pragma once
#include <Box2D/Box2D.h>
#import "cinder/Vector.h"

using namespace ci;

struct Conversions {
    
    constexpr static const float scaling = 50.0f;
    
    static Vec2f toScreen( b2Vec2 fin )
    {
        return Vec2f(fin.x, fin.y) * scaling;
    }
    
    static b2Vec2 toPhysics( Vec2f fin )
    {
        return b2Vec2( fin.x/scaling, fin.y/scaling );
    }
    
    static float toPhysics( float fin )
    {
        return fin / scaling;
    }
    
    static float toScreen( float fin )
    {
        return fin * scaling;
    }
    
};

#endif
