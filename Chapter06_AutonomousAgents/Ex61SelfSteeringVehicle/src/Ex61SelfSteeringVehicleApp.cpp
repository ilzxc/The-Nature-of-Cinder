#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Vehicle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex61SelfSteeringVehicleApp : public AppNative {
  public:
	void setup();
	void mouseMove( MouseEvent event );
	void update();
	void draw();
    
    unique_ptr< Vehicle > vehicle;
    Vec2f mouse;
    float mouseRadius;
};

void Ex61SelfSteeringVehicleApp::setup()
{
    vehicle = unique_ptr< Vehicle > ( new Vehicle { getWindowWidth(), getWindowHeight() } );
    mouse = Vec2f{ app::getWindowCenter() };
    mouseRadius = 50.0f;
}

void Ex61SelfSteeringVehicleApp::mouseMove( MouseEvent event )
{
    mouse = event.getPos();
}

void Ex61SelfSteeringVehicleApp::update()
{
    vehicle->update( mouse );
}

void Ex61SelfSteeringVehicleApp::draw()
{
	// clear out the window with black
	gl::clear( Color{ 0.9f, 0.9f, 0.9f } );
    
    gl::color( 0.444f, 0.444f, 0.444f );
    gl::drawSolidCircle( mouse, mouseRadius );
    vehicle->draw();
}

CINDER_APP_NATIVE( Ex61SelfSteeringVehicleApp, RendererGl )
