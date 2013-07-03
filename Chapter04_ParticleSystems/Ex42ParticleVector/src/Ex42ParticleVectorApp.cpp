#include <vector>
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex42ParticleVectorApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    void shutdown();
    
    std::vector<Particle*> particles;
    Rand random;
};

void Ex42ParticleVectorApp::setup()
{
    gl::enableAlphaBlending();
    random.randomize();
    particles.push_back( new Particle( Vec2f( getWindowWidth() / 2, 40 ), random ) );
}

void Ex42ParticleVectorApp::mouseDown( MouseEvent event )
{
}

void Ex42ParticleVectorApp::update()
{
    for(std::vector<Particle*>::reverse_iterator iter = particles.rbegin(); iter != particles.rend(); ++iter) {
        (*iter)->update();
        if ( (*iter)->isDead() ) {
            delete (*iter);
            particles.erase( --iter.base() );
        }
    }
    
    particles.push_back( new Particle( Vec2f( getWindowWidth() / 2, 40 ), random ) );
    
    // std::cout << "Current particle count is " << particles.size() << std::endl;
}

void Ex42ParticleVectorApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
    for (auto& particle : particles){
        particle->draw();
    }
}

void Ex42ParticleVectorApp::shutdown() {
    for (auto& particle : particles) {
        delete particle;
    }
}

CINDER_APP_NATIVE( Ex42ParticleVectorApp, RendererGl )
