#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex1_6_VectorAccelMouseApp : public AppBasic {
public:
    void prepareSettings( Settings * );
	void setup();
	void mouseMove( MouseEvent event );
	void update();
	void draw();
    
    Mover ball;
    Vec2f mousePosition;
};

void Ex1_6_VectorAccelMouseApp::prepareSettings(Settings *settings){
    settings -> setWindowSize( 900, 400 );
}

void Ex1_6_VectorAccelMouseApp::setup() {
    mousePosition = getWindowCenter();
}

void Ex1_6_VectorAccelMouseApp::mouseMove( MouseEvent event ) {
    mousePosition = event.getPos();
}

void Ex1_6_VectorAccelMouseApp::update() {
    ball.setAccel(mousePosition);
    ball.update();
}

void Ex1_6_VectorAccelMouseApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    ball.draw();
}

CINDER_APP_BASIC( Ex1_6_VectorAccelMouseApp, RendererGl )
