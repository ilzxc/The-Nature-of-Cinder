#include <vector>
#include "Box2D/Box2D.h"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Boundary.h"
#include "CustomShape.h"
#include "Microphone.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex54ComplexFormsApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );
    void keyDown( KeyEvent event );
    void keyUp( KeyEvent event );
	void update();
	void draw();
    
    b2World *world;
    float32 timestep;
    int32 velocityIterations;
    int32 positionIterations;
    
    std::vector<Boundary> boundaries;
    std::vector<CustomShape> polygons;
    std::vector<Microphone> microphones;
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
    if ( Rand::randInt( 2 ) == 0 ) {
        polygons.push_back( CustomShape(world, event.getPos()) );
    } else {
        microphones.push_back( Microphone(world, event.getPos()) );
    }
}

void Ex54ComplexFormsApp::keyDown( KeyEvent event ) {
    if( event.getCode() == KeyEvent::KEY_w ) {
        gl::enableWireframe();
    }
}

void Ex54ComplexFormsApp::keyUp( KeyEvent event ) {
    if( event.getCode() == KeyEvent::KEY_w ) {
        gl::disableWireframe();
    }
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
    
    for (std::vector<Microphone>::iterator iter = microphones.begin(); iter != microphones.end();) {
        iter->update();
        if ( iter->isDead() ) {
            iter->killBody( world );
            iter = microphones.erase( iter );
        } else {
            ++iter;
        }
    }
}

void Ex54ComplexFormsApp::draw()
{
	gl::clear( Color( 59.0f/255, 58.0f/255, 57.0f/255 ) );
    for ( auto& b : boundaries ) {
        b.draw();
    }
    
    for ( auto& p : polygons ) {
        p.draw();
    }
    
    for ( auto& m : microphones ) {
        m.draw();
    }
}

CINDER_APP_NATIVE( Ex54ComplexFormsApp, RendererGl )
