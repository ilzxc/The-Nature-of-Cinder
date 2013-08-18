#include <vector>
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Oscillator.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex34SimpleHarmonicMotionApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    Rand random;
    vector< Oscillator > oscillators;
};

void Ex34SimpleHarmonicMotionApp::setup() {
    random.randomize();
    oscillators.push_back( Oscillator( random, app::getWindowCenter() ) );
}

void Ex34SimpleHarmonicMotionApp::mouseDown( MouseEvent event ) {
    if ( event.isLeft() ) {
        setup();
    } else {
        oscillators.pop_back();
    }
}

void Ex34SimpleHarmonicMotionApp::update() {
    for ( auto& osc : oscillators ) {
        osc.update();
    }
}

void Ex34SimpleHarmonicMotionApp::draw()
{
	gl::clear( Color( 0.0f, 0.0f, 0.0f ) );
    for ( auto& osc : oscillators ) {
        osc.draw();
    }
}

CINDER_APP_NATIVE( Ex34SimpleHarmonicMotionApp, RendererGl )
