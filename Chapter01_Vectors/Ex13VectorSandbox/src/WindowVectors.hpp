//
//  WindowVectors.hpp
//  Ex13VectorSandbox
//
//  Created by Ilya Rostovtsev on 10/31/15.
//
//

#ifndef WindowVectors_hpp
#define WindowVectors_hpp

class WindowVectors {
  public:
    WindowVectors(): centerPoint{}, endPoint{} { }
    WindowVectors( const ci::vec2& centerPoint );
    
    void setCenter( const ci::vec2& newCenter );
    void update( const ci::vec2& current );
    void draw() const;
    
  private:
    ci::vec2 centerPoint;
    ci::vec2 endPoint;
};

#endif /* WindowVectors_hpp */
