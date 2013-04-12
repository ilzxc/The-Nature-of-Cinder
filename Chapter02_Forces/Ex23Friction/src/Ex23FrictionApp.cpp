#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex23FrictionApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Ex23FrictionApp::setup()
{
}

void Ex23FrictionApp::mouseDown( MouseEvent event )
{
}

void Ex23FrictionApp::update()
{
}

void Ex23FrictionApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( Ex23FrictionApp, RendererGl )
