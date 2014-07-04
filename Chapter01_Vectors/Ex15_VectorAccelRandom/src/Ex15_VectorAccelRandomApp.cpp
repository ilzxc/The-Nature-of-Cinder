#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex15_VectorAccelRandomApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
    void update();
    void draw();
    
    Mover ball;
};

void Ex15_VectorAccelRandomApp::prepareSettings( Settings* settings )
{
    settings->setWindowSize( 900, 400 );
}

void Ex15_VectorAccelRandomApp::update()
{
    ball.update();
}

void Ex15_VectorAccelRandomApp::draw()
{
    gl::clear( Color{ 0.111f, 0.111f, 0.111f } );
    ball.draw();
}

CINDER_APP_NATIVE( Ex15_VectorAccelRandomApp, RendererGl )
