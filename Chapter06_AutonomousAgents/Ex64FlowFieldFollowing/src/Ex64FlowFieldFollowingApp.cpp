#include <vector>
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "FlowField.h"
#include "Vehicle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex64FlowFieldFollowingApp : public AppNative {
public:
	void setup();
	void resize();
	void mouseDown( MouseEvent event );
	void update();
	void draw();
    
	FlowField flowfield;
	std::vector<Vehicle> vehicles;
};

void Ex64FlowFieldFollowingApp::setup() {
	flowfield = FlowField(20);
	for ( int i = 0; i < 1000; ++i ) {
		vehicles.push_back( Vehicle( Vec2f( Rand::randFloat( getWindowWidth() ), Rand::randFloat( getWindowHeight() ) ), Rand::randFloat(0.03f, 0.09f), Rand::randFloat(2.0f, 5.0f) ) );
	}
}

void Ex64FlowFieldFollowingApp::resize() {
	flowfield = FlowField(20);
}

void Ex64FlowFieldFollowingApp::mouseDown( MouseEvent event ) {
	flowfield.init();
}

void Ex64FlowFieldFollowingApp::update() {
	for (auto& v : vehicles ) {
		v.update(flowfield);
	}
}

void Ex64FlowFieldFollowingApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 1, 1, 1 ) );
	flowfield.draw();
	for ( auto& v : vehicles ) {
		v.draw();
	}
}

CINDER_APP_NATIVE( Ex64FlowFieldFollowingApp, RendererGl )
