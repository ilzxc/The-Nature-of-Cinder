#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Mover.h"
#include "Attractor.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex25GravitationalAttractorsApp : public AppNative {
  public:
    void prepareSettings( Settings *settings );
	void setup();
    void mouseMove( MouseEvent event );
	void mouseDown( MouseEvent event );
	void mouseReleased( MouseEvent event );
	void update();
	void draw();
    
    Mover m;
    Attractor a;
};

void Ex25GravitationalAttractorsApp::prepareSettings( Settings * settings) {
    settings->setWindowSize(640, 360);
}

void Ex25GravitationalAttractorsApp::setup() {
    a.setLocation(getWindowCenter());
}

void Ex25GravitationalAttractorsApp::mouseMove( MouseEvent event ){
    a.drag( event.getPos() );
    a.hover( event.getPos() );
}

void Ex25GravitationalAttractorsApp::mouseDown( MouseEvent event ) {
    a.clicked( event.getPos() );
}

void Ex25GravitationalAttractorsApp::mouseReleased( MouseEvent event ) {
    a.stopDragging();    
}

void Ex25GravitationalAttractorsApp::update()
{
    ci::Vec2f force = a.attract(m);
    m.applyForce(force);
    m.update();
}

void Ex25GravitationalAttractorsApp::draw()
{
	// clear out the window with black
    gl::enableAlphaBlending();
	gl::clear( Color( 0, 0, 0 ) );
    
    a.draw();
    m.draw();
}

CINDER_APP_NATIVE( Ex25GravitationalAttractorsApp, RendererGl )
