#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex79Var07NestingApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Ex79Var07NestingApp::setup()
{
}

void Ex79Var07NestingApp::mouseDown( MouseEvent event )
{
}

void Ex79Var07NestingApp::update()
{
}

void Ex79Var07NestingApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( Ex79Var07NestingApp, RendererGl )
