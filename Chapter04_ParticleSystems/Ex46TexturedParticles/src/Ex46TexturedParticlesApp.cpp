#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex46TexturedParticlesApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Ex46TexturedParticlesApp::setup()
{
}

void Ex46TexturedParticlesApp::mouseDown( MouseEvent event )
{
}

void Ex46TexturedParticlesApp::update()
{
}

void Ex46TexturedParticlesApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( Ex46TexturedParticlesApp, RendererGl )
