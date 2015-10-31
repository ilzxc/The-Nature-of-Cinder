#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex14VectorAccelConstApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void Ex14VectorAccelConstApp::setup()
{
}

void Ex14VectorAccelConstApp::mouseDown( MouseEvent event )
{
}

void Ex14VectorAccelConstApp::update()
{
}

void Ex14VectorAccelConstApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( Ex14VectorAccelConstApp, RendererGl )
