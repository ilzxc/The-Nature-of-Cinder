#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class SpinningBatonApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    float angle = 0;
    int distance = 50;
};

void SpinningBatonApp::setup()
{
    gl::enableAlphaBlending();
}

void SpinningBatonApp::mouseDown( MouseEvent event )
{
}

void SpinningBatonApp::update()
{
    angle += 3;
}

void SpinningBatonApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    gl::pushMatrices();
    gl::translate( getWindowCenter() );
    gl::rotate(angle);
    
    gl::drawLine( Vec2f(-distance, 0), Vec2f(distance, 0) );
    gl::drawSolidCircle( Vec2f(-distance, 0), 10 );
    gl::drawSolidCircle( Vec2f( distance, 0), 10 );
    gl::popMatrices();
}

CINDER_APP_NATIVE( SpinningBatonApp, RendererGl )
