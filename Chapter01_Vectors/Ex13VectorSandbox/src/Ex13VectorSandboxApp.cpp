#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "WindowVectors.hpp"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex13VectorSandboxApp : public App {
  public:
	void setup() override;
    void mouseMove( MouseEvent event ) override;
    void mouseDrag( MouseEvent event ) override;
	void draw() override;
    void resize() override;
    
  private:
    WindowVectors centre;
};

void Ex13VectorSandboxApp::setup()
{
    gl::enableAlphaBlending();
    centre = WindowVectors{ getWindowCenter() };
}

void Ex13VectorSandboxApp::mouseMove( MouseEvent event )
{
    centre.update( event.getPos() );
}

void Ex13VectorSandboxApp::mouseDrag( MouseEvent event )
{
    mouseMove( event );
}

void Ex13VectorSandboxApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    centre.draw();
}

void Ex13VectorSandboxApp::resize()
{
    centre.setCenter( getWindowCenter() );
}

CINDER_APP( Ex13VectorSandboxApp, RendererGl )
