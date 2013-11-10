#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Path.h"
#include "Vehicle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex65PathFollowingApp : public AppNative {
public:
    void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );
	void update();
	void draw();
    
private:
	unique_ptr< Path > path;
	vector< unique_ptr< Vehicle > > cars;
    void resetPath();
};

void Ex65PathFollowingApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 900, 300 );
}

void Ex65PathFollowingApp::setup()
{
    path = unique_ptr< Path > ( new Path() );
	Rand::randomize();
	resetPath();
	cars.push_back( unique_ptr< Vehicle > ( new Vehicle( Vec2f{ 0.f, getWindowCenter().y }, 0.2f, 5.f ) ) );
    cars.push_back( unique_ptr< Vehicle > ( new Vehicle( Vec2f{ 0.f, getWindowCenter().y }, 0.4f, 7.f ) ) );
}

void Ex65PathFollowingApp::resetPath()
{
	path->reset();
	path->addPoint( -20.f, getWindowCenter().y );
	path->addPoint( Rand::randFloat( getWindowCenter().x ), Rand::randFloat( getWindowCenter().y ) );
	path->addPoint( Rand::randFloat( getWindowCenter().x, getWindowWidth() ), Rand::randFloat( getWindowHeight() ) );
	path->addPoint( getWindowWidth() + 20.f, getWindowCenter().y );
}

void Ex65PathFollowingApp::mouseDown( MouseEvent event )
{
	resetPath();
}

void Ex65PathFollowingApp::update()
{
	for ( auto& c : cars ) {
		c->update( *path );
	}
}

void Ex65PathFollowingApp::draw()
{
	gl::clear( Color{ 1.f, 1.f, 1.f } );
	path->draw();
	for (auto& c : cars) {
		c->draw();
	}
}

CINDER_APP_NATIVE( Ex65PathFollowingApp, RendererGl )
