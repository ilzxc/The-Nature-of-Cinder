#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex74Var02ProbabilisticCAApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void Ex74Var02ProbabilisticCAApp::setup()
{
}

void Ex74Var02ProbabilisticCAApp::mouseDown( MouseEvent event )
{
}

void Ex74Var02ProbabilisticCAApp::update()
{
}

void Ex74Var02ProbabilisticCAApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( Ex74Var02ProbabilisticCAApp, RendererGl )
