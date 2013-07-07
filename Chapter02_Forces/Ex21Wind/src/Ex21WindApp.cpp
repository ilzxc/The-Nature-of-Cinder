#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex21WindApp : public AppNative {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    Mover m;
    Vec2f wind;
    Vec2f gravity;
};

void Ex21WindApp::prepareSettings( Settings *settings ) {
    settings->setWindowSize(640, 360);
}

void Ex21WindApp::setup() {
    wind.set(0.01f, 0.0f);
    gravity.set(0.0f, 0.1f);
}

void Ex21WindApp::mouseDown( MouseEvent event ) {
}

void Ex21WindApp::update() {
    m.applyForce(wind);
    m.applyForce(gravity);
    m.update();
}

void Ex21WindApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    m.draw();
}

CINDER_APP_NATIVE( Ex21WindApp, RendererGl )
