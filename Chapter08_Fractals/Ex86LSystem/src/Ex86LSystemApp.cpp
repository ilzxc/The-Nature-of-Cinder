#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex86LSystemApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Ex86LSystemApp::setup()
{
}

void Ex86LSystemApp::mouseDown( MouseEvent event )
{
}

void Ex86LSystemApp::update()
{
}

void Ex86LSystemApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( Ex86LSystemApp, RendererGl )
