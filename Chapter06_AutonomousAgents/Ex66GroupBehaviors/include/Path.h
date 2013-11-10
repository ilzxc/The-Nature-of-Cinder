//
//  Path.h
//  Ex66GroupBehaviors
//
//  Created by Ilya Rostovtsev on 11/8/13.
//
//

#ifndef Ex66GroupBehaviors_Path_h
#define Ex66GroupBehaviors_Path_h

#include "cinder/gl/gl.h"
#include <vector>

class Path
{
    
public:
    Path();
    ~Path();
    
    void addPoint( const float x, const float y );
    void draw() const;
    ci::Vec2f getPoint( const int index ) const;
    const std::vector< ci::Vec2f >& getPoints() const;
    float getRadius() const;
    
    
private:
    std::vector< ci::Vec2f > points;
    float radius;
    
};

#endif
