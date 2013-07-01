#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex31SpinningBasicsApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Ex31SpinningBasicsApp::setup()
{
}

void Ex31SpinningBasicsApp::mouseDown( MouseEvent event )
{
}

void Ex31SpinningBasicsApp::update()
{
}

void Ex31SpinningBasicsApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( Ex31SpinningBasicsApp, RendererGl )
