#include <vector>
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "RoundConfetti.h"
#include "Confetti.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex44ParticlePolymorphismApp : public AppNative {
  public:
    void setup();
    void keyDown( KeyEvent event );
    void keyUp( KeyEvent event );
    void update();
    void draw();
    
    Rand random;
    std::vector< std::unique_ptr < Particle > > everything;
    int likelihood;
};

void Ex44ParticlePolymorphismApp::setup()
{
    gl::enableAlphaBlending();
    random.randomize();
    likelihood = 300;
}

void Ex44ParticlePolymorphismApp::keyDown( KeyEvent event )
{
    if ( event.getCode() == KeyEvent::KEY_w ) {
        gl::enableWireframe();
    }
}

void Ex44ParticlePolymorphismApp::keyUp( KeyEvent event )
{
    gl::disableWireframe();
}

void Ex44ParticlePolymorphismApp::update()
{
    // create new Particles in std::vector everything:
    int coin = random.nextInt( likelihood * 3 ); 
    if ( coin <= likelihood ) {
        everything.push_back( std::unique_ptr< Particle > ( new Confetti( Vec2f( getWindowWidth() / 2.0f, 70.0f ), random, 0 ) ) );
    } else if ( coin <= ( likelihood * 2 ) ) {
        everything.push_back( std::unique_ptr< Particle > ( new Confetti( Vec2f( getWindowWidth() / 2.0f, 70.0f ), random, 1 ) ) );
    } else {
        everything.push_back( std::unique_ptr< Particle > ( new RoundConfetti( Vec2f(getWindowWidth() / 2.0f, 70.0f ), random ) ) );
    }
    
    // update everything, and remove dead particles (garbage collection is handled by std::unique_ptr):
    for ( auto& e : everything ) {
        e->update();
    }
    everything.erase( std::remove_if( everything.begin(), everything.end(), std::mem_fn( &Particle::isDead ) ), everything.end() );
}

void Ex44ParticlePolymorphismApp::draw()
{
    gl::clear( Color( 0.96f, 0.96f, 0.96f ) );
    for ( auto& e : everything ) {
        e->draw();
    }
}

CINDER_APP_NATIVE( Ex44ParticlePolymorphismApp, RendererGl )
