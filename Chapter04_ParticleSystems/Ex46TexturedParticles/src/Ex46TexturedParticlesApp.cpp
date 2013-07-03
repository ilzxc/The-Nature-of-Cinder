#include "cinder/app/AppNative.h"
#include "Math.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/Rand.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex46TexturedParticlesApp : public AppNative {
  public:
	void setup();
	void update();
	void draw();
    
    gl::Texture image;
    float windDirection, windSpeed;
    Vec2f wind;
    std::vector<Particle*> particles;
    Rand random;
};

void Ex46TexturedParticlesApp::setup()
{
    gl::enableAlphaBlending();
    gl::enableAdditiveBlending();
    random.randomize();
    image = gl::Texture( loadImage( loadResource("texture00.png") ) );
    particles.push_back( new Particle( &image, Vec2f( getWindowWidth() / 2, getWindowHeight() * 0.7 ), random ) );
    windDirection = 0.0f;
    windSpeed = 0.11;
}

void Ex46TexturedParticlesApp::update()
{
    windDirection += windSpeed;
    if (windDirection >= 6.28318530717959) {
        windSpeed = random.nextFloat(0.07, 0.23);
        windDirection -= 6.28318530717959;
    }
    wind = Vec2f( sin(windDirection) * 0.0005f, 0.0f );
    for(std::vector<Particle*>::reverse_iterator iter = particles.rbegin(); iter != particles.rend(); ++iter) {
        (*iter)->update(wind);
        if ( (*iter)->isDead() ) {
            delete (*iter);
            particles.erase( --iter.base() );
        }
    }
    
    particles.push_back( new Particle( &image, Vec2f( getWindowWidth() / 2, getWindowHeight() * 0.7  ), random ) );
    
    // std::cout << "Current particle count is " << particles.size() << std::endl;
}

void Ex46TexturedParticlesApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
    for( auto& i : particles ) {
        i->draw();
    }
}

CINDER_APP_NATIVE( Ex46TexturedParticlesApp, RendererGl )
