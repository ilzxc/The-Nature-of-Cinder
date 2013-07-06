#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Ball.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex12_BallWithVectorsApp : public AppNative {
  public:
	void setup();
	void update();
	void draw();
    
    Ball ball;
};

void Ex12_BallWithVectorsApp::setup() {
    ball = Ball( getWindowCenter() );
}

void Ex12_BallWithVectorsApp::update() {
    ball.update();
}

void Ex12_BallWithVectorsApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    ball.draw();
}


CINDER_APP_NATIVE( Ex12_BallWithVectorsApp, RendererGl )
