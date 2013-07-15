#include <vector>
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "ParticleSystem.h"
#include "Repeller.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class iOSTestApp : public AppNative {
  public:
	void setup();
    void touchesBegan( TouchEvent event );
	void touchesMoved( TouchEvent event );
	void update();
	void draw();
    
    ParticleSystem ps;
    Repeller repeller;
    Rand random;
    Vec2f gravity;
};

void iOSTestApp::setup() {
    gl::enableAlphaBlending();
    ps = ParticleSystem( Vec2f( getWindowWidth() / 2, getWindowHeight() * 0.2f ), random );
    repeller = Repeller( Vec2f( getWindowWidth() / 2 - 30, getWindowHeight() * 0.50f ) );
    gravity.set(0.0f, 0.01f);
}

void iOSTestApp::touchesBegan( TouchEvent event ) {
    Vec2f position = Vec2f::zero();
    int counter = event.getTouches().size();
    for( vector<TouchEvent::Touch>::const_iterator touchIt = event.getTouches().begin(); touchIt != event.getTouches().end(); ++touchIt ) {
		position += touchIt->getPos();
    }
    repeller.setLocation( position / counter );
}

void iOSTestApp::touchesMoved( TouchEvent event ) {
    Vec2f position = Vec2f::zero();
    int counter = event.getTouches().size();
    for( vector<TouchEvent::Touch>::const_iterator touchIt = event.getTouches().begin(); touchIt != event.getTouches().end(); ++touchIt ) {
		position += touchIt->getPos();
    }
    repeller.setLocation( position / counter );
}

void iOSTestApp::update() {
    ps.update( gravity, repeller, random );
}

void iOSTestApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 1, 1, 1 ) );
    repeller.draw();
    ps.draw();
}

CINDER_APP_NATIVE( iOSTestApp, RendererGl )
