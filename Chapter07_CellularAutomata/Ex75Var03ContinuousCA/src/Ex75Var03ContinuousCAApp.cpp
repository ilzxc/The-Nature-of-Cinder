#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex75Var03ContinuousCAApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Ex75Var03ContinuousCAApp::setup()
{
}

void Ex75Var03ContinuousCAApp::mouseDown( MouseEvent event )
{
}

void Ex75Var03ContinuousCAApp::update()
{
}

void Ex75Var03ContinuousCAApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( Ex75Var03ContinuousCAApp, RendererGl )
