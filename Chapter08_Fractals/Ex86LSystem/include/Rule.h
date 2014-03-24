//
//  Rule.h
//  Ex86LSystem
//
//  Created by Ilya Rostovtsev on 3/23/14.
//
//

#ifndef __Ex86LSystem__Rule__
#define __Ex86LSystem__Rule__

#include <string>

using namespace std;

struct Rule
{
  public:
    Rule( const char a, const string& b ): a( a ), b( b ) { }
    char getA() const { return a; }
    string getB() const { return b; }
    
  private:
    char a;
    string b;
};


#endif /* defined(__Ex86LSystem__Rule__) */
