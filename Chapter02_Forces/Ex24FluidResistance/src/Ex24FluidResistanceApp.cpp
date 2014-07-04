#include <vector>
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"
#include "Liquid.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex24FluidResistanceApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
    void setup();
    void resetMovers();
    void mouseDown( MouseEvent event );
    void update();
    void draw();
    
    vector< Mover > movers;
    unique_ptr< Liquid > liquid;
};

void Ex24FluidResistanceApp::prepareSettings( Settings* settings )
{
    settings->setWindowSize( 800, 200 );
}

void Ex24FluidResistanceApp::setup()
{
    gl::enableAlphaBlending();
    liquid = unique_ptr< Liquid > ( new Liquid{ 0.f, getWindowHeight() / 2.f, static_cast< float >( getWindowWidth() ), static_cast< float >( getWindowHeight() ), 0.1f } );
    resetMovers();
}

void Ex24FluidResistanceApp::resetMovers()
{
    if ( movers.size() != 0 ) {
        movers.clear();
    }
    
    for ( auto i = 0; i < 10; ++i ) {
        movers.push_back( Mover( Rand::randFloat( 0.5f, 3.f ), 40. + i * 70, 0.f ) );
    }
}

void Ex24FluidResistanceApp::mouseDown( MouseEvent event )
{
    resetMovers();
}

void Ex24FluidResistanceApp::update()
{
    for ( auto& mover : movers ) {
        if ( liquid->contains( mover ) ) {
            auto dragForce = liquid->drag( mover );
            mover.applyForce( dragForce );
        }
        auto gravity = Vec2f{ 0.f, 0.1f * mover.getMass() };
        mover.applyForce( gravity );
        mover.update();
    }
}

void Ex24FluidResistanceApp::draw()
{
    gl::clear( Color{ 0.f, 0.f, 0.f } );
    for ( auto& mover : movers ) {
        mover.draw();
    }
    liquid->draw();
}

CINDER_APP_NATIVE( Ex24FluidResistanceApp, RendererGl )
