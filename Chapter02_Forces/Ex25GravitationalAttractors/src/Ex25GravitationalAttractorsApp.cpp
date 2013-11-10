#include <vector>
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"
#include "Attractor.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex25GravitationalAttractorsApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
	void setup();
    void mouseDown( MouseEvent event );
    void mouseUp( MouseEvent event );
    void mouseMove( MouseEvent event );
	void mouseDrag( MouseEvent event );
	void update();
	void draw();
    
  private:
    vector< Mover > movers;
    unique_ptr< Attractor > attractor;
    Vec2f mouseLocation;

};

void Ex25GravitationalAttractorsApp::prepareSettings( Settings* settings )
{
    settings->setWindowSize( 800, 200 );
}

void Ex25GravitationalAttractorsApp::setup()
{
    for ( auto i = 0; i < 100; ++i ) {
        movers.push_back( Mover( randFloat( 0.5f, 1.5f ), randFloat( getWindowWidth() ), randFloat( getWindowHeight() ) ) );
    }
    attractor = unique_ptr < Attractor > ( new Attractor{ getWindowCenter().x, getWindowCenter().y } );
}

void Ex25GravitationalAttractorsApp::mouseDown( MouseEvent event )
{
    attractor->clicked( event.getPos() );
}

void Ex25GravitationalAttractorsApp::mouseUp( MouseEvent event )
{
    attractor->stopDragging();
}

void Ex25GravitationalAttractorsApp::mouseMove( MouseEvent event )
{
    mouseLocation = event.getPos();
}

void Ex25GravitationalAttractorsApp::mouseDrag( MouseEvent event )
{
    mouseLocation = event.getPos();
}

void Ex25GravitationalAttractorsApp::update()
{
    attractor->hover( mouseLocation );
    attractor->drag( mouseLocation );
    for ( auto& mover : movers ) {
        mover.applyForce( attractor->attract( mover ) );
        mover.update();
    }
}

void Ex25GravitationalAttractorsApp::draw()
{
	gl::clear( Color{ 0.f, 0.f, 0.f } );
    attractor->draw();
    for ( auto& mover : movers ) {
        mover.draw();
    }
}

CINDER_APP_NATIVE( Ex25GravitationalAttractorsApp, RendererGl )
