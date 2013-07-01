#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex32DirectionOfMotionApp : public AppNative {
  public:
	void setup();
    void mouseMove( MouseEvent e );
	void update();
	void draw();
    
    Mover m;
    Vec2f mousePosition;
};

void Ex32DirectionOfMotionApp::setup()
{
    m.resetPosition();
}


void Ex32DirectionOfMotionApp::mouseMove( MouseEvent e ){
    mousePosition = e.getPos();
}

void Ex32DirectionOfMotionApp::update()
{
    m.setAccel( mousePosition );
    m.update();
}

void Ex32DirectionOfMotionApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );

    m.draw();
    
}

CINDER_APP_NATIVE( Ex32DirectionOfMotionApp, RendererGl )
