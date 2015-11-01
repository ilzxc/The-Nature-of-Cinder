#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "Flock.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex17StupidFlockApp : public App {
  public:
	void setup() override;
	void mouseMove( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
  private:
    Flock flock;
    vec2 mouseLast;
    Font font;
};

void Ex17StupidFlockApp::setup()
{
    app::setWindowSize( 900, 400 );
    mouseLast = app::getWindowCenter();
    font = Font();
}

void Ex17StupidFlockApp::mouseMove( MouseEvent event )
{
    mouseLast = event.getPos();
}

void Ex17StupidFlockApp::update()
{
    flock.interact( mouseLast );
    flock.update();
    cout << "framerate: " << getAverageFps() << endl;
}

void Ex17StupidFlockApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    flock.draw();
    gl::drawString( "*" + to_string( getAverageFps() ), vec2{ 10.f, 10.f }, Color::white(), font );
}

CINDER_APP( Ex17StupidFlockApp, RendererGl )
