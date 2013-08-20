#include <vector>
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex23FrictionApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
	void setup();
	void update();
	void draw();
    
    vector< Mover > movers;
    Vec2f wind;
    Vec2f gravity;
    Vec2f friction;
    const float c = 0.05f;
};

void Ex23FrictionApp::prepareSettings(Settings* settings)
{
    settings->setWindowSize(383, 200);
}


void Ex23FrictionApp::setup()
{
    Rand::randomize();
    for ( int i = 0; i < 7; ++i ) {
        movers.push_back( Mover( randFloat( 1.0f, 4.0f ), randFloat( getWindowWidth() ), 0.0f ) );
    }
    
    wind = Vec2f( 0.01f, 0.0f );
    gravity = Vec2f::zero();
    friction = Vec2f::zero();
}


void Ex23FrictionApp::update()
{
    for ( auto& mover : movers ) {
        gravity.set( 0.0f, 0.1f * mover.getMass() );
        friction = mover.getVelocity();
        
        if ( friction != Vec2f::zero() ) {
            friction *= -1.0f;
            friction.normalize();
            friction *= c;
        }
        
        mover.applyForce( friction );
        mover.applyForce( wind );
        mover.applyForce( gravity );
        
        mover.update();
    }
}

void Ex23FrictionApp::draw()
{
	gl::clear( Color( 0.0f, 0.0f, 0.0f ) );
    
    for ( auto& mover : movers ) {
        mover.draw();
    }
}

CINDER_APP_NATIVE( Ex23FrictionApp, RendererGl )
