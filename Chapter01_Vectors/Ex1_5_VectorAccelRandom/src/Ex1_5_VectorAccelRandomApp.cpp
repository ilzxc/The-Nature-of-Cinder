#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex1_5_VectorAccelRandomApp : public AppBasic {
public:
    void prepareSettings( Settings * );
	void setup();
	void mouseDown( MouseEvent event );
	void update();
	void draw();
    
    Mover ball;
};

void Ex1_5_VectorAccelRandomApp::prepareSettings(Settings *settings){
    settings -> setWindowSize( 900, 400 );
}

void Ex1_5_VectorAccelRandomApp::setup() {
    ball.resetPosition();
}

void Ex1_5_VectorAccelRandomApp::mouseDown( MouseEvent event ) {
    ball.newAcceleration();
}

void Ex1_5_VectorAccelRandomApp::update() {
    ball.update();
}

void Ex1_5_VectorAccelRandomApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    ball.draw();
}

CINDER_APP_BASIC( Ex1_5_VectorAccelRandomApp, RendererGl )
