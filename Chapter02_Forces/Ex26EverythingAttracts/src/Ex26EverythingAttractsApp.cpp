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
    settings->setWindowSize(800, 200);
}

void Ex26EverythingAttractsApp::setup() {
    Rand::randomize();
    for (int i = 0; i < 300; i++) {
        movers.push_back( Mover( randFloat(0.1, 2), randFloat(getWindowWidth()), randFloat(getWindowHeight()) ) );
    }
}

void Ex26EverythingAttractsApp::update() {
    for (int i = 0; i < movers.size(); ++i) {
        for (int j = 0; j < movers.size(); ++j) {
            if (i != j) {
                Vec2f force = movers[j].attract(movers[i], g);
                movers[i].applyForce(force);
            }
        }
        movers[i].update();
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
