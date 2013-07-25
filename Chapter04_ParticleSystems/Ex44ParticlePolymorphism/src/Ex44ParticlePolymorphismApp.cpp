#include <vector>
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/params/Params.h"
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
    void shutdown();
    Rand r;
    
    vector<Particle*> everything;
    params::InterfaceGl mParams;
    float liklihood;
};

void Ex44ParticlePolymorphismApp::setup()
{
    gl::enableAlphaBlending();
    r.randomize();
    
    mParams = params::InterfaceGl( "ParticlePolymorphism", Vec2i( 225, 200 ) );
    mParams.addParam( "Composition", &liklihood, "min=0.0 max=100.0 step=2.0 keyIncr=s keyDecr=x" );
}

void Ex44ParticlePolymorphismApp::keyDown(KeyEvent event) {
    if (event.getCode() == KeyEvent::KEY_w) {
        gl::enableWireframe();
    }
    
    liklihood = 33;
}

void Ex44ParticlePolymorphismApp::keyUp(KeyEvent event) {
    gl::disableWireframe();
}

void Ex44ParticlePolymorphismApp::update()
{
    if(everything.size() > 0) {
        for(std::vector<Particle*>::reverse_iterator iter = everything.rbegin(); iter != everything.rend(); ++iter){
            (*iter)->update();
            if ( (*iter)->isDead() ) {
                delete (*iter);
                everything.erase(--iter.base());
            }
        }
    }
    int coin = r.nextInt(0, 100);
    if (coin <= liklihood) {
        everything.push_back( new Confetti( Vec2f(getWindowWidth() / 2, 70), r, 0 ) );
    } else if (coin <= (liklihood * 2)) {
        everything.push_back( new Confetti( Vec2f(getWindowWidth() / 2, 70), r, 1 ) );
    } else {
        everything.push_back( new RoundConfetti( Vec2f(getWindowWidth() / 2, 70), r ) );
    }
}

void Ex44ParticlePolymorphismApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0.96, 0.96, 0.96 ) );
    
    for (auto& p : everything) {
        p->draw();
    }
    
    mParams.draw();
}

void Ex44ParticlePolymorphismApp::shutdown() {
    for (auto& p : everything) {
        delete p;
    }
}

CINDER_APP_NATIVE( Ex44ParticlePolymorphismApp, RendererGl )
