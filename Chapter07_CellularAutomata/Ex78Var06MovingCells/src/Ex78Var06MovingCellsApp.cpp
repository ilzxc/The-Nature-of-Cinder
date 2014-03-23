#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex78Var06MovingCellsApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Ex78Var06MovingCellsApp::setup()
{
}

void Ex78Var06MovingCellsApp::mouseDown( MouseEvent event )
{
}

void Ex78Var06MovingCellsApp::update()
{
}

void Ex78Var06MovingCellsApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( Ex78Var06MovingCellsApp, RendererGl )
