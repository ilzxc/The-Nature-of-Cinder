#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "CA.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex71ElementaryCellularAutomataApp : public AppNative {
  public:
    void setup();
    void mouseDown( MouseEvent event ); 
    void update();
    void draw();
    
  private:
    std::unique_ptr< CA > ca;
};

void Ex71ElementaryCellularAutomataApp::setup()
{
    int array[] = { 0, 1, 0, 1, 1, 0, 1, 0 };
    ca = std::unique_ptr< CA > ( new CA( array ) );
    ca->restart();
}

void Ex71ElementaryCellularAutomataApp::mouseDown( MouseEvent event )
{
}

void Ex71ElementaryCellularAutomataApp::update()
{
}

void Ex71ElementaryCellularAutomataApp::draw()
{
    // clear out the window with black
    gl::clear( Color( 0, 0, 0 ) );
    ca->draw();
}

CINDER_APP_NATIVE( Ex71ElementaryCellularAutomataApp, RendererGl )
