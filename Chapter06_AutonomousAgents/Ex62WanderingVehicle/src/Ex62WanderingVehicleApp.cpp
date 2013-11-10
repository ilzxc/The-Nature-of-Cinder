#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Vehicle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex62WanderingVehicleApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    unique_ptr< Vehicle > vehicle;
};

void Ex62WanderingVehicleApp::setup()
{
    vehicle = unique_ptr< Vehicle > ( new Vehicle ( getWindowCenter() ) );
}

void Ex62WanderingVehicleApp::mouseDown( MouseEvent event )
{
    vehicle->toggleDebug();
}

void Ex62WanderingVehicleApp::update()
{
    vehicle->update();
}

void Ex62WanderingVehicleApp::draw()
{
	gl::clear( Color{ 0.88f, 0.88f, 0.88f } );
    vehicle->draw();
}

CINDER_APP_NATIVE( Ex62WanderingVehicleApp, RendererGl )
