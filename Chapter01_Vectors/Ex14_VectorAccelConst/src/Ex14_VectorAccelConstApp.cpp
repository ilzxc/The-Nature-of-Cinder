#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex14_VectorAccelConstApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
    void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

    Mover ball;
};

void Ex14_VectorAccelConstApp::prepareSettings( Settings* settings )
{
    settings->setWindowSize( 900, 400 );
}

void Ex14_VectorAccelConstApp::setup()
{
    ball.randomizeAcceleration();
}

void Ex14_VectorAccelConstApp::mouseDown( MouseEvent event )
{
    setup();
}

void Ex14_VectorAccelConstApp::update()
{
    ball.update();
}

void Ex14_VectorAccelConstApp::draw()
{
	gl::clear( Color( 0.111f, 0.111f, 0.111f ) );
    ball.draw();
}

CINDER_APP_NATIVE( Ex14_VectorAccelConstApp, RendererGl )
