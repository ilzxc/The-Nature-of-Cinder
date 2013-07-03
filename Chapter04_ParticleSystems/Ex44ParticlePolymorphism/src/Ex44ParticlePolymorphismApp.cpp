#include <vector>
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Particle.h"
#include "Confetti.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex44ParticlePolymorphismApp : public AppNative {
  public:
	void setup();
	void update();
	void draw();
    void shutdown();
    Rand r;
    
    vector<Particle*> everything;
};

void Ex44ParticlePolymorphismApp::setup()
{
    gl::enableAlphaBlending();
    r.randomize();
}

void Ex44ParticlePolymorphismApp::update()
{
    if(everything.size() > 0) {
        for(std::vector<Particle*>::iterator iter = everything.end() - 1; iter >= everything.begin(); --iter) {
            (*iter)->update();
            if ( (*iter)->isDead() ) {
                delete (*iter);
                iter = everything.erase(iter);
            }
        }
    }
    
    if (r.nextInt(0, 100) > 50) {
        everything.push_back( new Particle( Vec2f(getWindowWidth() / 2, 70), r ) );
    } else {
        everything.push_back( new Confetti( Vec2f(getWindowWidth() / 2, 70), r ) );
    }
}

void Ex44ParticlePolymorphismApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0.8, 0.8, 0.8 ) );
    
    for (int i = 0; i < everything.size(); i++) {
        everything[i]->draw();
    }
}

void Ex44ParticlePolymorphismApp::shutdown() {
    for (int i = 0; i < everything.size(); ++i) {
        delete everything[i];
    }
}

CINDER_APP_NATIVE( Ex44ParticlePolymorphismApp, RendererGl )
