#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Vehicle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex63StayingWithinWallsApp : public AppNative {
  public:
	void setup();
	void resize();
	void update();
	void draw();
    
    unique_ptr< Vehicle > vehicle;
};

void Ex63StayingWithinWallsApp::setup()
{
    vehicle = unique_ptr< Vehicle > ( new Vehicle{ getWindowCenter(), getWindowSize() } );
}

void Ex63StayingWithinWallsApp::resize()
{
    vehicle->setBoundary( getWindowSize() );
}

void Ex63StayingWithinWallsApp::update()
{
    vehicle->update();
}

void Ex63StayingWithinWallsApp::draw()
{
	gl::clear( Color{ 1.f, 1.f, 1.f } );
    vehicle->draw();
}

CINDER_APP_NATIVE( Ex63StayingWithinWallsApp, RendererGl )
