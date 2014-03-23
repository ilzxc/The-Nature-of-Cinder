#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex77Var05HistoricalCAApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Ex77Var05HistoricalCAApp::setup()
{
}

void Ex77Var05HistoricalCAApp::mouseDown( MouseEvent event )
{
}

void Ex77Var05HistoricalCAApp::update()
{
}

void Ex77Var05HistoricalCAApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( Ex77Var05HistoricalCAApp, RendererGl )
