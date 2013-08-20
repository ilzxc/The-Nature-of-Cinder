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
    std::unique_ptr< Ball > smartBall;
};

void Ex12_BallWithVectorsApp::setup()
{
    ball = Ball( getWindowCenter() );
    smartBall = std::unique_ptr< Ball > ( new Ball( getWindowCenter() ) );
}

void Ex12_BallWithVectorsApp::update()
{
    ball.update();
    smartBall->update();
}

void Ex12_BallWithVectorsApp::draw()
{
	gl::clear( Color( 0.222f, 0.222f, 0.222f ) );
    ball.draw();
    smartBall->draw();
}

/* no shutdown() is required for cleanup, if all of the variables are
   declared on the stack - of if smart pointers are used              */

CINDER_APP_NATIVE( Ex12_BallWithVectorsApp, RendererGl )
