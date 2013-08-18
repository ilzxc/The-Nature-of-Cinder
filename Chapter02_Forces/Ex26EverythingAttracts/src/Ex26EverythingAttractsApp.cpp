#include <vector>
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex26EverythingAttractsApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
	void setup();
	void update();
	void draw();
    
    const float g = 0.4f;
    vector< Mover > movers;
};

void Ex26EverythingAttractsApp::prepareSettings( Settings* settings ) {
    settings->setWindowSize( 800, 300 );
}

void Ex26EverythingAttractsApp::setup() {
    Rand::randomize();
    gl::enableAlphaBlending();
    for ( int i = 0; i < 300; ++i ) {
        movers.push_back( Mover( randFloat( 0.1f, 2.0f ), randFloat( getWindowWidth() ), randFloat( getWindowHeight() ) ) );
    }
}

void Ex26EverythingAttractsApp::update() {
    for ( std::vector< Mover >::iterator iter = movers.begin(); iter != movers.end(); ++iter ) {
        for ( std::vector< Mover >::iterator iter2 = iter + 1; iter2 != movers.end(); ++iter2 ) {
            Vec2f force = iter2->attract( *iter, g );
            iter->applyForce( force );
            iter2->applyForce( -force );
        }
        iter->update();
    }
    
}

void Ex26EverythingAttractsApp::draw() {
	gl::clear( Color( 0.0f, 0.0f, 0.0f ) );
    for ( auto& mover : movers ) {
        mover.draw();
    }
}

CINDER_APP_NATIVE( Ex26EverythingAttractsApp, RendererGl )
