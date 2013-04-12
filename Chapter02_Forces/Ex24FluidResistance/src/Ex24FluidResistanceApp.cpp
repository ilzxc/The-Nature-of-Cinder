#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex24FluidResistanceApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Ex24FluidResistanceApp::setup()
{
}

void Ex24FluidResistanceApp::mouseDown( MouseEvent event )
{
}

void Ex24FluidResistanceApp::update()
{
}

void Ex24FluidResistanceApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( Ex24FluidResistanceApp, RendererGl )
