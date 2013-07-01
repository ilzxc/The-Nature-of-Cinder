#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include <vector>
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex23FrictionApp : public AppBasic {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    vector<Mover> balls;
    const int numBalls = 50;
    
};

void Ex23FrictionApp::prepareSettings( Settings *settings ) {
    settings->setWindowSize( 1100, 500 );
    settings->setFrameRate( 60.0f );
    for ( int i = 0; i < numBalls; i++ ) {
        balls.push_back( *new Mover() );
    }
}

void Ex23FrictionApp::setup() {
    Vec2f setWind = Vec2f( randFloat(2.9), randFloat(2.9) );
    
    for (int i = 0; i < balls.size(); i++ ) {
        balls[i] = *new Mover();
        balls[i].setup( Vec2f( 0.0, 3.0 ), setWind, randFloat(0.05, 0.12) );
    }
}

void Ex23FrictionApp::mouseDown( MouseEvent event ) {
    setup();
}

void Ex23FrictionApp::update()
{
    for (int i = 0; i < balls.size(); i++ ) {
        balls[i].update();
    }
}

void Ex23FrictionApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    for (int i = 0; i < balls.size(); i++ ) {
        balls[i].draw();
    }
}

CINDER_APP_BASIC( Ex23FrictionApp, RendererGl )
