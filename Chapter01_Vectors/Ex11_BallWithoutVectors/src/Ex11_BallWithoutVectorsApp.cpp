#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Ball.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex11_BallWithoutVectorsApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
	void setup();
	void update();
	void draw();
    void shutdown();
    
    Rand random;
    
    Ball *ballOnTheHeap;
    Ball  ballOnTheStack;
    std::unique_ptr< Ball > ballSmartPointer;
};

void Ex11_BallWithoutVectorsApp::prepareSettings( Settings* settings ) {
    settings->setWindowSize( 900, 300 );
    settings->setFrameRate( 60.0f );
    random.randomize();
}

void Ex11_BallWithoutVectorsApp::setup() {
    ballOnTheHeap = new Ball( getWindowWidth() / 2.0f, getWindowHeight() / 2.0f, random );
    ballOnTheStack = Ball( getWindowWidth() / 2.0f, getWindowHeight() / 2.0f, random );
    ballSmartPointer = std::unique_ptr< Ball > ( new Ball( getWindowWidth() / 2.0f, getWindowHeight() / 2.0f, random ) );
}

void Ex11_BallWithoutVectorsApp::update() {
    ballOnTheHeap->update();        // dynamically allocated objects use -> to access public members of a class
    ballOnTheStack.update();        // objects on the stack use . to access class members
    ballSmartPointer->update();     // smart pointers use -> just like regular pointers
}

void Ex11_BallWithoutVectorsApp::draw()
{
	gl::clear( Color( 0.111f, 0.111f, 0.111f ) );
    ballOnTheHeap->draw();
    ballOnTheStack.draw();
    ballSmartPointer->draw();
}

void Ex11_BallWithoutVectorsApp::shutdown() {
    delete ballOnTheHeap;
    // do not need to invoke "delete" on ballSmartPointer, as this will be handled for us by std::unique_ptr
}

CINDER_APP_NATIVE( Ex11_BallWithoutVectorsApp, RendererGl )
