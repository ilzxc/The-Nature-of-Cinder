#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Boid.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex67FlockingApp : public AppNative {
  public:
    void setup();
    void mouseDown( MouseEvent event );
    void mouseUp( MouseEvent event );
    void update();
    void draw();
    
  private:
    vector< unique_ptr< Boid > > flock;
    bool makeBoids;
};

void Ex67FlockingApp::setup()
{
    makeBoids = false;
    for ( auto i = 0; i < 400; ++i ) {
        flock.push_back( unique_ptr< Boid > ( new Boid( getWindowCenter() ) ) );
    }
}

void Ex67FlockingApp::mouseDown( MouseEvent event )
{
    makeBoids = true;
}

void Ex67FlockingApp::mouseUp( MouseEvent event )
{
    makeBoids = false;
}


void Ex67FlockingApp::update()
{
    for ( auto& boid : flock ) {
        boid->update( flock );
    }
}

void Ex67FlockingApp::draw()
{
    gl::clear( Color{ 1.f, 1.f, 1.f } );
    for ( const auto& boid : flock ) {
        boid->draw();
    }
}

CINDER_APP_NATIVE( Ex67FlockingApp, RendererGl )
