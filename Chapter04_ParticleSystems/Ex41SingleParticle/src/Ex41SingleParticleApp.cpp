#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex41SingleParticleApp : public AppNative {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
    void shutdown();
    
    Particle *p;
    Rand r;
};

void Ex41SingleParticleApp::prepareSettings( Settings *settings ) {
    settings->setWindowSize(640, 360);
}

void Ex41SingleParticleApp::setup()
{
    gl::enableAlphaBlending();
    r.randomize();
    
    p = new Particle( Vec2f(getWindowWidth() / 2, 30), Vec2f( r.nextFloat(-0.001, 0.001), r.nextFloat(0.03, 0.05) ) );
}

void Ex41SingleParticleApp::update()
{
    p->update();
    if (p->isDead()) {
        delete p;
        p = new Particle( Vec2f(getWindowWidth() / 2, 30), Vec2f( r.nextFloat(-0.01, 0.01), r.nextFloat(0, 0.05) ) );
    }
}

void Ex41SingleParticleApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    p->display();
}

void Ex41SingleParticleApp::shutdown() {
    delete p;
}

CINDER_APP_NATIVE( Ex41SingleParticleApp, RendererGl )
