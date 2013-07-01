#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <vector>
#include "Mover.h"
#include "Liquid.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex24FluidResistanceApp : public AppNative {
  public:
	void setup();
    void resize();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    Liquid liquid;
    vector<Mover> movers;
    int numMovers = 8;
};


void Ex24FluidResistanceApp::setup()
{
    ci::gl::enableAlphaBlending();
    liquid.setBounds();
    
    for (int i = 0; i < numMovers; i++) {
        Mover m( ci::randFloat(20, 60), ( 100 + i * (getWindowWidth() / numMovers) ), 30 );
        movers.push_back( m );
    }
}

void Ex24FluidResistanceApp::resize(){
    liquid.setBounds();
}

void Ex24FluidResistanceApp::mouseDown( MouseEvent event )
{
    movers.clear();
    setup();
}

void Ex24FluidResistanceApp::update()
{
    for(int i = 0; i < movers.size(); i++ ) {
        if (liquid.contains(movers[i])) {
            ci::Vec2f dragForce = liquid.drag(movers[i]);
            movers[i].applyForce(dragForce);
        }
        
        ci::Vec2f gravity(0, 0.1 * movers[i].mass);
        movers[i].applyForce(gravity);
        movers[i].update();
        movers[i].checkEdges();
    }
}

void Ex24FluidResistanceApp::draw()
{
	// clear out the window with black
    gl::clear();
    liquid.draw();
    
    for (int i = 0; i < movers.size(); i++) {
        movers[i].draw();
    }
    
    // frame done
}

CINDER_APP_NATIVE( Ex24FluidResistanceApp, RendererGl )
