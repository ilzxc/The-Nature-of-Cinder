#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Pendulum.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex36PendulumApp : public AppNative {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
    void mouseDrag( MouseEvent event );
    void mouseUp( MouseEvent event );
	void update();
	void draw();
    
    Pendulum p;
    Vec2f mouseLocation;
};

void Ex36PendulumApp::prepareSettings( Settings *settings ) {
    settings->setWindowSize( 650, 330 );
}

void Ex36PendulumApp::setup() {
    p = Pendulum( Vec2f( getWindowWidth() / 2.0f, 0.0f), 300.0f );
    mouseLocation = Vec2f::zero();
}

void Ex36PendulumApp::mouseDown( MouseEvent event ) {
    p.clicked( event.getPos() );
    mouseLocation = event.getPos();
}

void Ex36PendulumApp::mouseDrag( MouseEvent event ) {
    mouseLocation = event.getPos();
}

void Ex36PendulumApp::mouseUp( MouseEvent event ) {
    p.stopDragging();
}

void Ex36PendulumApp::update() {
    p.update( mouseLocation );
}

void Ex36PendulumApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    p.draw();
}

CINDER_APP_NATIVE( Ex36PendulumApp, RendererGl )
