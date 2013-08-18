#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex32DirectionOfMovementApp : public AppNative {
  public:
	void setup();
	void mouseMove( MouseEvent event );
	void update();
	void draw();
    
    Mover car;
    Vec2f mousePosition;
};

void Ex32DirectionOfMovementApp::setup() {
    mousePosition = getWindowCenter();
}

void Ex32DirectionOfMovementApp::mouseMove( MouseEvent event ) {
    mousePosition = event.getPos();
}

void Ex32DirectionOfMovementApp::update() {
    car.update( mousePosition );
}

void Ex32DirectionOfMovementApp::draw() {
	gl::clear( Color( 0.111f, 0.111f, 0.111f ) );
    car.draw();
}

CINDER_APP_NATIVE( Ex32DirectionOfMovementApp, RendererGl )
