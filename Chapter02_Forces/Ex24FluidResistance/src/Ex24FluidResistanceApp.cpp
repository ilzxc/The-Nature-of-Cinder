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
    void prepareSettings( Settings *settings );
	void setup();
    void resetMovers();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    vector<Mover> movers;
    Liquid liquid;
};

void Ex24FluidResistanceApp::prepareSettings( Settings *settings ) {
    settings->setWindowSize(800, 200);
}

void Ex24FluidResistanceApp::setup() {
    gl::enableAlphaBlending();
    
    liquid = Liquid( 0.0f, getWindowHeight() / 2, getWindowWidth(), getWindowHeight(), 0.1f );
    resetMovers();
}

void Ex24FluidResistanceApp::resetMovers() {
    if (movers.size() != 0) {
        movers.clear();
    }
    
    for (int i = 0; i < 11; ++i) {
        movers.push_back( Mover( Rand::randFloat(0.5f, 3.0f), 40.0 + i * 70, 0.0f) );
    }
}

void Ex24FluidResistanceApp::mouseDown( MouseEvent event ) {
    resetMovers();
}

void Ex24FluidResistanceApp::update() {
    for ( auto& mover: movers ) {
        if (liquid.contains( mover ) ) {
            Vec2f dragForce = liquid.drag( mover );
            mover.applyForce(dragForce);
        }
        
        Vec2f gravity = Vec2f( 0.0f, 0.1 * mover.getMass() );
        mover.applyForce(gravity);
        
        mover.update();
    }
}

void Ex24FluidResistanceApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    for (auto& mover : movers ) {
        mover.draw();
    }
    liquid.draw();
}

CINDER_APP_NATIVE( Ex24FluidResistanceApp, RendererGl )
