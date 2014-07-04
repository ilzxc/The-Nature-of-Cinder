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
    std::vector< std::unique_ptr< Particle > > particles;
    Rand random;
};

void Ex46TexturedParticlesApp::setup()
{
    gl::enableAlphaBlending();
    gl::enableAdditiveBlending();
    random.randomize();
    image = gl::Texture( loadImage( loadResource( "texture00.png" ) ) );
    windDirection = 0.0f;
    windSpeed = 0.11f;
}

void Ex46TexturedParticlesApp::update()
{
    windDirection += windSpeed;
    if ( windDirection >= M_PI * 2 ) {
        windSpeed = random.nextFloat( 0.07f, 0.23f );
        windDirection -= M_PI * 2;
    }
    wind = Vec2f( sin(windDirection) * 0.0005f, 0.0f );
    
    particles.push_back( std::unique_ptr< Particle > ( new Particle( &image, Vec2f( getWindowWidth() / 2.0f, getWindowHeight() * 0.7f ), random ) ) );
    
    for ( auto& p : particles ) {
        p->update( wind );
    }
    
    particles.erase( std::remove_if( particles.begin(), particles.end(), std::mem_fn( &Particle::isDead ) ), particles.end() );
}

void Ex46TexturedParticlesApp::draw()
{
    gl::clear( Color( 0.0f, 0.0f, 0.0f ) );
    for( auto& p : particles ) {
        p->draw();
    }
}

CINDER_APP_NATIVE( Ex46TexturedParticlesApp, RendererGl )
