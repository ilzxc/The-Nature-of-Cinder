#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "vecToCenter.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex1_3_VectorSandboxApp : public AppBasic {
public:
	void setup();
	void mouseMove( MouseEvent event );
    void mouseUp ( MouseEvent event );
	void update();
	void draw();
    
    Vec2f mouseLoc;
    vecToCenter centre = new vecToCenter( true );
};

void Ex1_3_VectorSandboxApp::setup() {
    centre.setCenterPoint(getWindowCenter());
}

void Ex1_3_VectorSandboxApp::mouseMove( MouseEvent event ) {
    mouseLoc = event.getPos();
}

void Ex1_3_VectorSandboxApp::mouseUp( MouseEvent event ) {
    centre.active = !(centre.active);
}

void Ex1_3_VectorSandboxApp::update() {
    centre.update(mouseLoc);
    
}

void Ex1_3_VectorSandboxApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    centre.draw();
}

CINDER_APP_BASIC( Ex1_3_VectorSandboxApp, RendererGl )
