#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex73Var01NonRectangularGridsApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Ex73Var01NonRectangularGridsApp::setup()
{
}

void Ex73Var01NonRectangularGridsApp::mouseDown( MouseEvent event )
{
}

void Ex73Var01NonRectangularGridsApp::update()
{
}

void Ex73Var01NonRectangularGridsApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( Ex73Var01NonRectangularGridsApp, RendererGl )
