//
//  Obstacle.h
//  Ex92SimpleSmartRockets
//
//  Created by Ilya Rostovtsev on 4/22/14.
//
//

#ifndef __Ex92SimpleSmartRockets__Obstacle__
#define __Ex92SimpleSmartRockets__Obstacle__

#include "cinder/Rect.h"

using namespace std;
using namespace ci;

class Obstacle
{
  public:
    Obstacle( const float x, const float y, const float w, const float h );
    void draw();
    bool contains( const Vec2f& check ) const;
    inline Vec2f get_location() const { return Vec2f( draw_rect.x1, draw_rect.y1 ); }
    
  private:
    Rectf draw_rect;

};

#endif /* defined(__Ex92SimpleSmartRockets__Obstacle__) */
