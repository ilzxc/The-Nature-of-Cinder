#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex41SingleParticleApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
	void setup();
	void update();
	void draw();
    void shutdown();
    
    Particle* p;
};

void Ex41SingleParticleApp::prepareSettings( Settings* settings )
{
    settings->setWindowSize( 640, 360 );
}

void Ex41SingleParticleApp::setup()
{
    gl::enableAlphaBlending();
    Rand::randomize();
    p = new Particle( Vec2f( getWindowWidth() / 2.0f, 30.0f ), Vec2f( Rand::randFloat( -0.001f, 0.001f ), Rand::randFloat( 0.03f, 0.05f ) ) );
}

void Ex41SingleParticleApp::update()
{
    p->update();
    if ( p->isDead() ) {
        delete p;
        p = new Particle( Vec2f( getWindowWidth() / 2.0f, 30.0f ), Vec2f( Rand::randFloat( -0.01f, 0.01f ), Rand::randFloat( 0.0f, 0.05f ) ) );
    }
}

void Ex41SingleParticleApp::draw()
{
	gl::clear( Color( 0.0f, 0.0f, 0.0f ) );
    p->draw();
}

void Ex41SingleParticleApp::shutdown()
{
    delete p;
}

CINDER_APP_NATIVE( Ex41SingleParticleApp, RendererGl )
