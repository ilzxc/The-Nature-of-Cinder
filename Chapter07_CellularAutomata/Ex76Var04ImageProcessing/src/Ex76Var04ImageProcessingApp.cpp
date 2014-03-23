#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex76Var04ImageProcessingApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Ex76Var04ImageProcessingApp::setup()
{
}

void Ex76Var04ImageProcessingApp::mouseDown( MouseEvent event )
{
}

void Ex76Var04ImageProcessingApp::update()
{
}

void Ex76Var04ImageProcessingApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( Ex76Var04ImageProcessingApp, RendererGl )
