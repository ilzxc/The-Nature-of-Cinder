#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/System.h"

#include "OSCInterface.h"
#include "square.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class oscarApp : public AppNative {
  public:
    void setup();
    void mouseDown( MouseEvent event );
    void mouseMove( MouseEvent event );
    void update();
    void draw();
    
    OSCInterface oscar;
    square mySquare;
};

void oscarApp::setup()
{
    oscar.setup( 2222 ); // listens on the number provided, sends out data on port + 1
}

void oscarApp::mouseDown( MouseEvent event )
{
    oscar.appendMessage( event.getX(), "/fromCinder/MouseDown/X" );
    oscar.appendMessage( event.getY(), "/fromCinder/MouseDown/Y" );
    oscar.sendMessage();
}

void oscarApp::mouseMove( MouseEvent event)
{
    oscar.appendMessage( event.getX(), "/fromCinder/MouseMove/X" );
    oscar.appendMessage( event.getY(), "/fromCinder/MouseMove/Y" );
    oscar.sendMessage();
}

void oscarApp::update()
{
    oscar.update();
    mySquare.update( oscar.rotation );
    mySquare.update( oscar.color );
}

void oscarApp::draw()
{
    // clear out the window with black
    gl::clear( Color( 0, 0, 0 ) );
    mySquare.draw();
}

CINDER_APP_NATIVE( oscarApp, RendererGl )
