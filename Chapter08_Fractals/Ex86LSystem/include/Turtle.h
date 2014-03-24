//
//  Turtle.h
//  Ex86LSystem
//
//  Created by Ilya Rostovtsev on 3/23/14.
//
//

#ifndef __Ex86LSystem__Turtle__
#define __Ex86LSystem__Turtle__

#include <string>
#include "cinder/gl/gl.h"

using namespace std;

class Turtle
{
  public:
    Turtle( const string& s, const float l, const float t );
    void render();
    void setLen( const float l );
    void changeLen( const float percent );
    void setToDo( string s );
    
    
  private:
    string todo;
    float len, theta;
};

#endif /* defined(__Ex86LSystem__Turtle__) */
