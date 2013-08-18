#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "VecToCenter.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex13_VectorSandboxApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );
	void mouseMove( MouseEvent event );
    void mouseDrag( MouseEvent event );
	void update();
	void draw();
    
    VecToCenter centre;
    Vec2f mouse;
    bool drawMode;
};

void Ex13_VectorSandboxApp::setup() {
    centre = VecToCenter ( true, getWindowCenter() );
    drawMode = true;
}

void Ex13_VectorSandboxApp::mouseDown( MouseEvent event ) {
    drawMode = !drawMode;
    centre.setActive( drawMode );
}

void Ex13_VectorSandboxApp::mouseMove( MouseEvent event ) {
    mouse = event.getPos();
}

void Ex13_VectorSandboxApp::mouseDrag( MouseEvent event ) {
    mouseMove( event );
}

void Ex13_VectorSandboxApp::update() {
    centre.update( mouse );
}

void Ex13_VectorSandboxApp::draw() {
	gl::clear( Color( 0.0f, 0.0f, 0.0f ) );
    centre.draw();
}

CINDER_APP_NATIVE( Ex13_VectorSandboxApp, RendererGl )
