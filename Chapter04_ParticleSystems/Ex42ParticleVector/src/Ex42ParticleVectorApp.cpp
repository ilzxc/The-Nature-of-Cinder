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
	void update();
	void draw();

    
    std::vector<Particle> particles;
    Rand random;
};

void Ex42ParticleVectorApp::setup()
{
    gl::enableAlphaBlending();
    random.randomize();
    particles.push_back( Particle( Vec2f( getWindowWidth() / 2, 40 ), random ) );
}

void Ex42ParticleVectorApp::update()
{
    for( std::vector<Particle>::iterator iter = particles.begin(); iter != particles.end(); ) {
        iter->update();
        if ( iter->isDead() ) {
            iter = particles.erase(iter);
        } else {
            iter++;
        }
    }
    
    particles.push_back( Particle( Vec2f( getWindowWidth() / 2, 40 ), random ) );
    
    //std::cout << "Current particle count is " << particles.size() << std::endl;
}

void Ex42ParticleVectorApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
    for (auto& particle : particles){
        particle.draw();
    }
}

CINDER_APP_NATIVE( Ex42ParticleVectorApp, RendererGl )
