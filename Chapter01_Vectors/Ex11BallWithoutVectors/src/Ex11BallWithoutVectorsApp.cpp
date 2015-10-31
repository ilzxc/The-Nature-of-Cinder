#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Ball.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex11BallWithoutVectorsApp : public App {
  public:
    Ex11BallWithoutVectorsApp();
    ~Ex11BallWithoutVectorsApp();
    
	void setup() override;
	void update() override;
	void draw() override;
    
  private:
    Rand random;
    Ball *ballOnTheHeap;
    Ball ballOnTheStack;
    std::unique_ptr< Ball > ballSmartPointer;
};

Ex11BallWithoutVectorsApp::Ex11BallWithoutVectorsApp()
{
    random.randomize();
    ballOnTheHeap = new Ball{ getWindowWidth() / 2.f, getWindowHeight() / 2.f, random };
    ballOnTheStack = Ball{ getWindowWidth() / 2.f, getWindowHeight() / 2.f, random };
    ballSmartPointer = make_unique< Ball > ( getWindowWidth() / 2.f, getWindowHeight() / 2.f, random ); // C++14
    // ballSmartPointer = unique_ptr< Ball > ( new Ball{ getWindowWidth() / 2.f, getWindowHeight() / 2.f, random } ); // C++11
}

Ex11BallWithoutVectorsApp::~Ex11BallWithoutVectorsApp()
{
    delete ballOnTheHeap; // allocations using "new" that aren't smart pointers require cleanup
}

void Ex11BallWithoutVectorsApp::setup()
{
    app::setWindowSize( 900, 300 );
    app::setFrameRate( 60.f );
}

void Ex11BallWithoutVectorsApp::update()
{
    ballOnTheHeap->update();
    ballOnTheStack.update();
    ballSmartPointer->update();
}

void Ex11BallWithoutVectorsApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    ballOnTheHeap->draw();
    ballOnTheStack.draw();
    ballSmartPointer->draw();
}

CINDER_APP( Ex11BallWithoutVectorsApp, RendererGl )
