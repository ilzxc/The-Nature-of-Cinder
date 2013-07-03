#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "ParticleSystem.h"
#include "Repeller.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex45ParticleRepellerApp : public AppNative {
  public:
	void setup();
    void mouseMove( MouseEvent event );
	void update();
	void draw();
    void shutdown();
    
    ParticleSystem *ps;
    Repeller *repeller;
    Rand random;
    Vec2f gravity;
};

void Ex45ParticleRepellerApp::setup() {
    gl::enableAlphaBlending();
    ps = new ParticleSystem( Vec2f( getWindowWidth() / 2, getWindowHeight() * 0.08f ), random );
    repeller = new Repeller( Vec2f( getWindowWidth() / 2 - 30, getWindowHeight() * 0.50f ) );
    gravity.set(0.0f, 0.01f);
}

void Ex45ParticleRepellerApp::mouseMove( MouseEvent event ){
    repeller->setLocation( event.getPos() );
}

void Ex45ParticleRepellerApp::update() {
    ps->update( gravity, repeller, random );
}

void Ex45ParticleRepellerApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
    repeller->draw();
    ps->draw();
}

void Ex45ParticleRepellerApp::shutdown() {
    delete ps;
    delete repeller;
}

CINDER_APP_NATIVE( Ex45ParticleRepellerApp, RendererGl )
