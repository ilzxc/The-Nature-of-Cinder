#include <vector>
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"
#include "Attractor.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex31SpinningBasicsApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
	void setup();
	void mouseDown( MouseEvent event );
    void mouseUp( MouseEvent event );
    void mouseMove( MouseEvent event );
	void mouseDrag( MouseEvent event );
	void update();
	void draw();
    
    vector< Mover > movers;
    std::unique_ptr< Attractor > attractor;
    Vec2f mouseLocation;
};

void Ex31SpinningBasicsApp::prepareSettings( Settings* settings )
{
    settings->setWindowSize( 800, 200 );
}

void Ex31SpinningBasicsApp::setup()
{
    for ( int i = 0; i < 40; ++i ) {
        movers.push_back( Mover( randFloat( 0.5f, 1.5f ), randFloat( getWindowWidth() ), randFloat( getWindowHeight() ) ) );
    }
    attractor = std::unique_ptr< Attractor > ( new Attractor( getWindowCenter().x, getWindowCenter().y ) );
}

void Ex31SpinningBasicsApp::mouseDown( MouseEvent event )
{
    attractor->clicked( event.getPos() );
}

void Ex31SpinningBasicsApp::mouseUp( MouseEvent event )
{
    attractor->stopDragging();
}

void Ex31SpinningBasicsApp::mouseMove( MouseEvent event )
{
    mouseLocation = event.getPos();
}

void Ex31SpinningBasicsApp::mouseDrag( MouseEvent event )
{
    mouseLocation = event.getPos();
}

void Ex31SpinningBasicsApp::update()
{
    attractor->hover( mouseLocation );
    attractor->drag( mouseLocation );
    for ( auto& mover : movers ) {
        Vec2f force = attractor->attract( mover );
        mover.applyForce( force );
        mover.update();
    }
}

void Ex31SpinningBasicsApp::draw()
{
	gl::clear( Color( 0.0f, 0.0f, 0.0f ) );
    attractor->draw();
    for ( auto& mover : movers ) {
        mover.draw();
    }
}

CINDER_APP_NATIVE( Ex31SpinningBasicsApp, RendererGl )
