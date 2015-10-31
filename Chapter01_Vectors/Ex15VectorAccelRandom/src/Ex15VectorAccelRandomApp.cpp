#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex15VectorAccelRandomApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void Ex15VectorAccelRandomApp::setup()
{
}

void Ex15VectorAccelRandomApp::mouseDown( MouseEvent event )
{
}

void Ex15VectorAccelRandomApp::update()
{
}

void Ex15VectorAccelRandomApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( Ex15VectorAccelRandomApp, RendererGl )
