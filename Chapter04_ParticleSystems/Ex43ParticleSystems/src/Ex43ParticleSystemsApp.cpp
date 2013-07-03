#include <vector>
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "ParticleSystem.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex43ParticleSystemsApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    Rand seed;
    std::vector<ParticleSystem> pss;
};

void Ex43ParticleSystemsApp::setup()
{
    gl::enableAlphaBlending();
    seed.randomize();
}

void Ex43ParticleSystemsApp::mouseDown( MouseEvent event )
{
    seed.randomize();
    pss.push_back( ParticleSystem( Vec2f( event.getX(), event.getY() ), seed.nextFloat(0, 10000) ) );
}

void Ex43ParticleSystemsApp::update()
{
    if(pss.size() > 0) {
        for ( auto& system : pss ) {
            system.update();
        }
    }
}

void Ex43ParticleSystemsApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    if(pss.size() > 0) {
        for ( auto& system : pss ) {
            system.draw();
        }
    }
}

CINDER_APP_NATIVE( Ex43ParticleSystemsApp, RendererGl )
