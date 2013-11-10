#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Path.h"
#include "Vehicle.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex66GroupBehaviorsApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    unique_ptr< Path > path;
    vector< Vehicle > vehicles;
};

void Ex66GroupBehaviorsApp::prepareSettings( Settings* settings )
{
    settings->setWindowSize( Vec2i{ 640, 260 } );
}
    
void Ex66GroupBehaviorsApp::setup()
{
    path = unique_ptr< Path > ( new Path() );
    auto offset = 30.f;

    path->addPoint( offset, offset );
    path->addPoint( getWindowWidth() - offset, offset );
    path->addPoint( getWindowWidth() - offset, getWindowHeight() - offset );
    path->addPoint( getWindowWidth() / 2.f , getWindowHeight() - offset * 3 );
    path->addPoint( offset, getWindowHeight() - offset );
    
    Rand::randomize();
    for ( auto i = 0; i < 100; ++i ) {
        vehicles.push_back( Vehicle( Vec2f{ Rand::randFloat( getWindowWidth() ), Rand::randFloat( getWindowHeight() ) }, 2.f, 1.f ) );
    }
}

void Ex66GroupBehaviorsApp::mouseDown( MouseEvent event )
{
}

void Ex66GroupBehaviorsApp::update()
{
    for ( auto& v : vehicles ) {
        v.update( vehicles, *path );
    }
}

void Ex66GroupBehaviorsApp::draw()
{
	gl::clear( Color{ 1.f, 1.f, 1.f } );
    path->draw();
    for ( const auto& v : vehicles ) {
        v.draw();
    }
}

CINDER_APP_NATIVE( Ex66GroupBehaviorsApp, RendererGl )
