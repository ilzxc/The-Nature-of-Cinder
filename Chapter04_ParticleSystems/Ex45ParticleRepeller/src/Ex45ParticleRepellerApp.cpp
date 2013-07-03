#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex45ParticleRepellerApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Ex45ParticleRepellerApp::setup()
{
}

void Ex45ParticleRepellerApp::mouseDown( MouseEvent event )
{
}

void Ex45ParticleRepellerApp::update()
{
}

void Ex45ParticleRepellerApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( Ex45ParticleRepellerApp, RendererGl )
