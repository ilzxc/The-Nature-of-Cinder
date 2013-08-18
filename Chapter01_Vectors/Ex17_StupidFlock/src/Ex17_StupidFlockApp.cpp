#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <vector>
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex17_StupidFlockApp : public AppNative {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void mouseMove( MouseEvent event );
	void update();
	void draw();

    vector< Mover > balls;
    Vec2f mousePosition;
    const int numBalls = 10000;
};

void Ex17_StupidFlockApp::prepareSettings(Settings *settings){
    settings->setWindowSize( 900, 400 );
}

void Ex17_StupidFlockApp::setup() {
    Rand::randomize();
    for (int i = 0; i < numBalls; i++) {
        balls.push_back( Mover( randFloat( 0.6f ) ) );
    }
    mousePosition = getWindowCenter();
}

void Ex17_StupidFlockApp::mouseMove( MouseEvent event ) {
    mousePosition = event.getPos();
}

void Ex17_StupidFlockApp::update() {
    for ( auto& b : balls ) {
        b.setAccel( mousePosition );
        b.update();
    }
}

void Ex17_StupidFlockApp::draw()
{
	gl::clear( Color( 0.0f, 0.0f, 0.0f ) );
    for ( auto& b : balls ) {
        b.draw();
    }
}

CINDER_APP_NATIVE( Ex17_StupidFlockApp, RendererGl )
