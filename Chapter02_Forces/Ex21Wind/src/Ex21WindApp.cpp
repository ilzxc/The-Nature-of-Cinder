#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex21WindApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
	void setup();
	void update();
	void draw();
    
  private:
    Mover ball;
    Vec2f wind;
    Vec2f gravity;
};

void Ex21WindApp::prepareSettings( Settings* settings )
{
    settings->setWindowSize( 640, 360 );
}

void Ex21WindApp::setup()
{
    wind.set( 0.01f, 0.f );
    gravity.set( 0.f, 0.1f );
}

void Ex21WindApp::update()
{
    ball.applyForce( wind );
    ball.applyForce( gravity );
    ball.update();
}

void Ex21WindApp::draw()
{
	gl::clear( Color( 0.111f, 0.111f, 0.111f ) );
    ball.draw();
}

CINDER_APP_NATIVE( Ex21WindApp, RendererGl )
