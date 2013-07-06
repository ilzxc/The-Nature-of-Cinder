#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex16_VectorAccelMouseApp : public AppNative {
  public:
	void setup();
	void mouseMove( MouseEvent event );
	void update();
	void draw();
    
    Mover ball;
    Vec2f mousePosition;
};

void Ex16_VectorAccelMouseApp::setup() {
    mousePosition = getWindowCenter();
}

void Ex16_VectorAccelMouseApp::mouseMove( MouseEvent event ) {
    mousePosition = event.getPos();
}

void Ex16_VectorAccelMouseApp::update() {
    ball.update(mousePosition);
}

void Ex16_VectorAccelMouseApp::draw() {
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    ball.draw();
}

CINDER_APP_NATIVE( Ex16_VectorAccelMouseApp, RendererGl )
