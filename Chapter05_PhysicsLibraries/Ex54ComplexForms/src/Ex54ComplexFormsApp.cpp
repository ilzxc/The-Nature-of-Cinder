#include <vector>
#include "Box2D/Box2D.h"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Boundary.h"
#include "CustomShape.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex54ComplexFormsApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    b2World * world;
    float32 timestep;
    int32 velocityIterations;
    int32 positionIterations;
    
    std::vector<Boundary> boundaries;
    std::vector<CustomShape> polygons;
};

void Ex54ComplexFormsApp::setup() {
    gl::enableAlphaBlending();
    
    world = new b2World( b2Vec2( 0.0f, 10.0f ) );
    timestep = 1.0f / 60.0f;
    velocityIterations = 8;
    positionIterations = 3;
    
    boundaries.push_back( Boundary(world, getWindowCenter().x - 150.0f, getWindowCenter().y, 300.0f, 5.0f) );
    boundaries.push_back( Boundary(world, getWindowCenter().x / 2.0 - 100.0f, 4.0f * getWindowHeight() / 5.0f, 150.0f, 5.0f) );
    boundaries.push_back( Boundary(world, 3.0 * getWindowCenter().x / 2.0 - 50.0f, 4.0f * getWindowHeight() / 5.0f, 150.0f, 5.0f) );
}

void Ex54ComplexFormsApp::mouseDown( MouseEvent event ) {
    polygons.push_back( CustomShape(world, event.getPos()) );
}

void Ex54ComplexFormsApp::update() {
    world->Step( timestep, velocityIterations, positionIterations );
    
    for (std::vector<CustomShape>::iterator iter = polygons.begin(); iter != polygons.end();) {
        iter->update( world );
        if ( iter->isDead() ) {
            iter->killBody( world );
            iter = polygons.erase( iter );
        } else {
            ++iter;
        }
    }
}

void Ex54ComplexFormsApp::draw()
{
	gl::clear( Color( 0.877f, 0.877f, 0.877f ) );
    for ( auto& b : boundaries ) {
        b.draw();
    }
    
    for ( auto& p : polygons ) {
        p.draw();
    }
}

CINDER_APP_NATIVE( Ex54ComplexFormsApp, RendererGl )
