#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "GOL.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex72GameOfLifeApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
  private:
    unique_ptr< GOL > gol;
};

void Ex72GameOfLifeApp::setup()
{
    gl::enableAlphaBlending();
    gol = unique_ptr< GOL >( new GOL() );
}

void Ex72GameOfLifeApp::mouseDown( MouseEvent event )
{
    gol->init();
}

void Ex72GameOfLifeApp::update()
{
    gol->generate();
}

void Ex72GameOfLifeApp::draw()
{
  	gl::clear( Color{ 1.f, 1.f, 1.f } );
    gol->draw();
}

CINDER_APP_NATIVE( Ex72GameOfLifeApp, RendererGl )
