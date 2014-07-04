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
    
    std::unique_ptr < ParticleSystem > ps;
    std::unique_ptr < Repeller > repeller;
    Rand random;
    Vec2f gravity;
};

void Ex45ParticleRepellerApp::setup()
{
    gl::enableAlphaBlending();
    ps = std::unique_ptr< ParticleSystem> ( new ParticleSystem( Vec2f( getWindowWidth() / 2.0f, getWindowHeight() * 0.08f ) ) );
    repeller = std::unique_ptr< Repeller > ( new Repeller( Vec2f( getWindowWidth() / 2.0f - 30, getWindowHeight() * 0.50f ) ) );
    gravity.set( 0.0f, 0.01f );
}

void Ex45ParticleRepellerApp::mouseMove( MouseEvent event )
{
    repeller->setLocation( event.getPos() );
}

void Ex45ParticleRepellerApp::update()
{
    ps->update( gravity, *repeller, random );
}

void Ex45ParticleRepellerApp::draw()
{
    gl::clear( Color( 1.0f, 1.0f, 1.0f ) );
    repeller->draw();
    ps->draw();
}

CINDER_APP_NATIVE( Ex45ParticleRepellerApp, RendererGl )
