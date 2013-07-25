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
    void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
    
    const float g = 0.4f;
    vector<Mover> movers;
};

void Ex26EverythingAttractsApp::prepareSettings( Settings *settings ) {
    settings->setWindowSize(800, 300);
    settings->setFrameRate( 60.0f );
}

void Ex26EverythingAttractsApp::setup() {
    Rand::randomize();
    gl::enableAlphaBlending();
    for (int i = 0; i < 300; i++) {
        movers.push_back( Mover( randFloat(0.1, 2), randFloat(getWindowWidth()), randFloat(getWindowHeight()) ) );
    }
}

void Ex26EverythingAttractsApp::update() {
    for ( std::vector<Mover>::iterator iter = movers.begin(); iter != movers.end(); ++iter) {
        for ( std::vector<Mover>::iterator iter2 = iter + 1; iter2 != movers.end(); ++iter2) {
            Vec2f force = iter2->attract(*iter, g);
            iter->applyForce(force);
            iter2->applyForce(-force);
        }
        iter->update();
    }
    
}

void Ex26EverythingAttractsApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );

    for ( auto& mover : movers ) {
        mover.draw();
    }
}

CINDER_APP_NATIVE( Ex26EverythingAttractsApp, RendererGl )
