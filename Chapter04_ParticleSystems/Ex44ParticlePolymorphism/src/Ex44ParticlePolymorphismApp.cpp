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
        for(std::vector<Particle*>::reverse_iterator iter = everything.rbegin(); iter != everything.rend(); ++iter){
            (*iter)->update();
            if ( (*iter)->isDead() ) {
                delete (*iter);
                everything.erase(--iter.base());
            }
        }
    }
    int coin = r.nextInt(0, 100);
    if (coin <= 33) {
        everything.push_back( new Confetti( Vec2f(getWindowWidth() / 2, 70), r, 0 ) );
    } else if (coin <= 66) {
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
}

void Ex44ParticlePolymorphismApp::shutdown() {
    for (auto& p : everything) {
        delete p;
    }
}

CINDER_APP_NATIVE( Ex44ParticlePolymorphismApp, RendererGl )
