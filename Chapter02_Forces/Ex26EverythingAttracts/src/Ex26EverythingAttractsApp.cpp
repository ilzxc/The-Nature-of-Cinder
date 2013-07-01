#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex26EverythingAttractsApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Ex26EverythingAttractsApp::setup()
{
}

void Ex26EverythingAttractsApp::mouseDown( MouseEvent event )
{
}

void Ex26EverythingAttractsApp::update()
{
}

void Ex26EverythingAttractsApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( Ex26EverythingAttractsApp, RendererGl )
