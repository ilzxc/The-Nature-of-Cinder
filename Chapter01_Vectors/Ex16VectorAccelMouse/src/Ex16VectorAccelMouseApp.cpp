#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex16VectorAccelMouseApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void Ex16VectorAccelMouseApp::setup()
{
}

void Ex16VectorAccelMouseApp::mouseDown( MouseEvent event )
{
}

void Ex16VectorAccelMouseApp::update()
{
}

void Ex16VectorAccelMouseApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( Ex16VectorAccelMouseApp, RendererGl )
