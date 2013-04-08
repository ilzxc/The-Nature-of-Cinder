#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"
#include <list>

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex1_7_StupidFlockApp : public AppBasic {
public:
    void prepareSettings( Settings * );
	void setup();
	void mouseMove( MouseEvent event );
	void update();
	void draw();
    
    list<Mover> balls;
    Vec2f mousePosition;
    const int numBalls = 100;
};

void Ex1_7_StupidFlockApp::prepareSettings(Settings *settings){
    settings -> setWindowSize( 900, 400 );
}

void Ex1_7_StupidFlockApp::setup() {
    Rand::randomize();
    for (int i = 0; i < numBalls; i++) {
        balls.push_back( Mover( randFloat(0.6f) ) );
    }
    mousePosition = getWindowCenter();
}

void Ex1_7_StupidFlockApp::mouseMove( MouseEvent event ) {
    mousePosition = event.getPos();
}

void Ex1_7_StupidFlockApp::update() {
    
    for( list<Mover>::iterator p = balls.begin(); p != balls.end(); ++p ){
        p->setAccel(mousePosition);
        p->update();
    }
}

void Ex1_7_StupidFlockApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    for(list<Mover>::iterator p = balls.begin(); p != balls.end(); ++p) {
        p->draw();
    }
}

CINDER_APP_BASIC( Ex1_7_StupidFlockApp, RendererGl )
