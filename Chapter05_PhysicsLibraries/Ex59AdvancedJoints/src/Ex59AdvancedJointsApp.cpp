#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Box2D/Box2D.h"
#include "Boundary.h"
#include "Arm.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex59AdvancedJointsApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );
    void mouseUp( MouseEvent event );
    void mouseDrag( MouseEvent event );
	void update();
	void draw();
    void shutdown();
    
    b2World *world;
    float32 timeStep;
    int32 velocityIterations;
    int32 positionIterations;
    
    Vec2f mouse;
    
    Arm *arm;
    Boundary *floor;
};

void Ex59AdvancedJointsApp::setup() {
    world = new b2World( b2Vec2( 0.0f, 10.0f ) );
    timeStep = 1.0f / 60.0f;
    velocityIterations = 8;
    positionIterations = 3;
    
    arm = new Arm( world );
    floor = new Boundary( world, 0.0f, getWindowHeight() - 10.0f, getWindowWidth(), 5.0f );
}

void Ex59AdvancedJointsApp::mouseDown( MouseEvent event ) {
    mouse = event.getPos();
}

void Ex59AdvancedJointsApp::mouseDrag( MouseEvent event ) {
    mouse = event.getPos();
}

void Ex59AdvancedJointsApp::mouseUp( MouseEvent event ) {
    mouse = Vec2f::zero();
}

void Ex59AdvancedJointsApp::update() {
    arm->update( mouse );
    world->Step( timeStep, velocityIterations, positionIterations );
    world->ClearForces();
}

void Ex59AdvancedJointsApp::draw() {
	gl::clear( Color( 0.666, 0.666, 0.666 ) );
    arm->draw();
    floor->draw();
}

void Ex59AdvancedJointsApp::shutdown() {
    delete arm;
    delete floor;
    delete world;
}

CINDER_APP_NATIVE( Ex59AdvancedJointsApp, RendererGl )
