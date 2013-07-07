#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex25GravitationalAttractorsApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Ex25GravitationalAttractorsApp::setup()
{
}

void Ex25GravitationalAttractorsApp::mouseDown( MouseEvent event )
{
}

void Ex25GravitationalAttractorsApp::update()
{
}

void Ex25GravitationalAttractorsApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( Ex25GravitationalAttractorsApp, RendererGl )
