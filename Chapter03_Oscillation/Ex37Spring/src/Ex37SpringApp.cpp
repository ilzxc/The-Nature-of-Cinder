#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Bob.h"
#include "Spring.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex37SpringApp : public AppNative {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
    void mouseDrag( MouseEvent event );
    void mouseUp( MouseEvent event );
	void update();
	void draw();
    
    Bob bob;
    Spring spring;
    Vec2f mouseLocation;
    Vec2f gravity;
};

void Ex37SpringApp::prepareSettings( Settings *settings ){
    settings->setWindowSize( 650, 350 );
}

void Ex37SpringApp::setup() {
    spring = Spring( getWindowWidth() / 2.0f, 10, 100 );
    bob = Bob( getWindowWidth() / 2.0f, 100 );
    mouseLocation = Vec2f::zero();
    gravity = Vec2f(0.0f, 2.0f);
}

void Ex37SpringApp::mouseDown( MouseEvent event ) {
    bob.clicked( event.getPos() );
    mouseLocation = event.getPos();
    
}

void Ex37SpringApp::mouseDrag( MouseEvent event ) {
    mouseLocation = event.getPos();
}

void Ex37SpringApp::mouseUp( MouseEvent event ) {
    bob.stopDragging();
}

void Ex37SpringApp::update() {
    bob.applyForce( gravity );
    spring.update(bob, 30, 400);
    bob.update( mouseLocation );
}

void Ex37SpringApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    spring.draw( bob );
    bob.draw();
}

CINDER_APP_NATIVE( Ex37SpringApp, RendererGl )
