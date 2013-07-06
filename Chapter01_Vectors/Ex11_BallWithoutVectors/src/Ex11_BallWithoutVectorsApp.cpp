#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Ball.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex11_BallWithoutVectorsApp : public AppNative {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
    void shutdown();
    
    Rand random;
    Ball *ballOnTheHeap;
    Ball ballOnTheStack;
};

void Ex11_BallWithoutVectorsApp::prepareSettings( Settings *settings ) {
    settings->setWindowSize(900, 300);
    settings->setFrameRate(25.0f);
    random.randomize();
}

void Ex11_BallWithoutVectorsApp::setup(){
    ballOnTheHeap = new Ball( getWindowWidth() / 2, getWindowHeight() / 2, random );
    ballOnTheStack = Ball( getWindowWidth() / 2, getWindowHeight() / 2, random );
}

void Ex11_BallWithoutVectorsApp::update() {
    ballOnTheHeap->update();
    ballOnTheStack.update();
}

void Ex11_BallWithoutVectorsApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    ballOnTheHeap->draw();
    ballOnTheStack.draw();
}

void Ex11_BallWithoutVectorsApp::shutdown() {
    delete ballOnTheHeap;
}

CINDER_APP_NATIVE( Ex11_BallWithoutVectorsApp, RendererGl )
