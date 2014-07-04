#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex92SimpleSmartRocketsApp : public AppNative {
  public:
    void setup();
    void mouseDown( MouseEvent event ); 
    void update();
    void draw();
};

void Ex92SimpleSmartRocketsApp::setup()
{
}

void Ex92SimpleSmartRocketsApp::mouseDown( MouseEvent event )
{
}

void Ex92SimpleSmartRocketsApp::update()
{
}

void Ex92SimpleSmartRocketsApp::draw()
{
    // clear out the window with black
    gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( Ex92SimpleSmartRocketsApp, RendererGl )
