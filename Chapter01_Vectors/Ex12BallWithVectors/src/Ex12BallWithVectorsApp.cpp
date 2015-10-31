#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Ball.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex12BallWithVectorsApp : public App {
  public:
	void setup() override;
	void update() override;
	void draw() override;
    
  private:
    Ball ball{ vec2{ 200.f, 200.f } };  // ctor (const vec2&)
    unique_ptr< Ball > smartBall; // no initialization -- no ctor call
};

void Ex12BallWithVectorsApp::setup()
{
    /// one of the following two can be commented out:
    smartBall = make_unique< Ball > ( getWindowCenter() ); // ctor (const vec2&)
    smartBall = make_unique< Ball > ( ball ); // copy (const Ball&)
    
    ball = *smartBall.get(); // operator=(const Ball&) -- will call copy
    ball = ball; // self-assignemnt -- operator=(const Ball&) without copy
}

void Ex12BallWithVectorsApp::update()
{
    ball.update();
    smartBall->update();
}

void Ex12BallWithVectorsApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    ball.draw();
    smartBall->draw();
}

CINDER_APP( Ex12BallWithVectorsApp, RendererGl )
