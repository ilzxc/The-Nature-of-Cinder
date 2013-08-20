#include <vector>
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex22GravityApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
	void setup();
	void update();
	void draw();
    
    vector< Mover > movers;
    Vec2f wind;
    Vec2f gravity;
};

void Ex22GravityApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 800, 200 );
}

void Ex22GravityApp::setup()
{
    wind.set( 0.01f, 0.0f );
    Rand::randomize();
    for ( int i = 0; i < 20; ++i ) {
        movers.push_back( Mover( Rand::randFloat( 1.0f, 4.0f ), 0.0f, 0.0f ) );
    }
}

void Ex22GravityApp::update()
{
    for ( auto& mover : movers ) {
        gravity.set( 0.0f, 0.1f * mover.getMass() );
        mover.applyForce( wind );
        mover.applyForce( gravity );
        mover.update();
    }
}

void Ex22GravityApp::draw()
{
	gl::clear( Color( 0.111f, 0.111f, 0.111f ) );
    
    for ( auto& mover : movers ) {
        mover.draw();
    }
}

CINDER_APP_NATIVE( Ex22GravityApp, RendererGl )
