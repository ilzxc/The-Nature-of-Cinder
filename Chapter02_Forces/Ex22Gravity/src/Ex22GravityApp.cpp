#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex21WindApp : public AppBasic {
public:
	void setup();
	void mouseDown( MouseEvent event );
	void update();
	void draw();
    
    vector<Mover> ball;
    const int numBalls = 1500;
};

void Ex21WindApp::setup()
{
    for (int i = 0; i < numBalls; i++) {
        ball.push_back ( *new Mover( 2.0 + 20.0 * (float)(i) / numBalls ) );
        ball[i].resetPosition();
        ball[i].setWind( Vec2f( 1.0f, -0.3f ), 0.7 );
        ball[i].setGravity( Vec2f( 0.0f, 1.0f ), 1.8 );
    }
}

void Ex21WindApp::mouseDown( MouseEvent event )
{
    Vec2f newWind = Vec2f( ci::randFloat(1.0f), -ci::randFloat(1.0f) );
    float newWindMag = ci::randFloat( 2.0f );
    
    for (int i = 0; i < ball.size(); i++) {
        ball[i].resetPosition();
        ball[i].setWind( newWind, newWindMag );
    }
}

void Ex21WindApp::update()
{
    for (int i = 0; i < ball.size(); i++) {
        ball[i].update();
    }
}

void Ex21WindApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    for (int i = 0; i < ball.size(); i++) {
        ball[i].draw();
    }
}

CINDER_APP_BASIC( Ex21WindApp, RendererGl )
