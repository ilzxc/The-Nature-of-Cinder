#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex1_2_BallWithVectorsApp : public AppBasic {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    Vec2f position;
    Vec2f velocity;
    float radius;
};

void Ex1_2_BallWithVectorsApp::prepareSettings( Settings *settings ) {
    settings -> setWindowSize( 640, 360 );
    settings -> setFrameRate( 60.0f );
}

void Ex1_2_BallWithVectorsApp::setup()
{
    Rand::randomize();
    
    position = getWindowCenter();
    velocity = Vec2f( randFloat(10.0f), randFloat(10.0f) );
    
    radius = 30.0f;
}

void Ex1_2_BallWithVectorsApp::mouseDown( MouseEvent event )
{
}

void Ex1_2_BallWithVectorsApp::update()
{
    position += velocity;
    
    if ( (position.x < radius) || (position.x > (getWindowWidth() - radius) ) ) {
        velocity.x *= -1;
    }
    
    if ( (position.y < radius) || (position.y > (getWindowHeight() - radius) ) ) {
        velocity.y *= -1;
    }
}

void Ex1_2_BallWithVectorsApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    gl::color( 0.3, 0.6, 0.9, 1.0 );
    gl::drawSolidCircle( position, 20.0f );
}

CINDER_APP_BASIC( Ex1_2_BallWithVectorsApp, RendererGl )
