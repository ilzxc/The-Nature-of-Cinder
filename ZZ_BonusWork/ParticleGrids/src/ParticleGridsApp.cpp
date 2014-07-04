#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

enum patterns { cosplussin, coscircles, sinconsinsquared };

class ParticleGridsApp : public AppBasic {
  public:
    void prepareSettings( Settings *settings );
    void setup();
    void resize( ResizeEvent event );
    void makeGrid();
    void makePattern();
    void mouseDown( MouseEvent event ); 
    void update();
    void draw();
    
    float particleSize;
    vector<particle> particles;
    
    patterns currentPattern;
};

void ParticleGridsApp::prepareSettings( Settings *settings ){
    settings -> setWindowSize( 800, 600 );
    settings -> setFrameRate( 30.0f );
}

void ParticleGridsApp::setup() {
    if (!particles.empty()) {
        particles.clear();
    }
    currentPattern = (currentPattern == cosplussin) ? (coscircles) : ( (currentPattern == coscircles) ? (sinconsinsquared) : (cosplussin) );
    particleSize = randFloat(2.0, 8.0);
    makeGrid();
    makePattern();
}

void ParticleGridsApp::resize( ResizeEvent event) {
    particles.clear();
    makeGrid();
    makePattern();
}

void ParticleGridsApp::makeGrid() {
    for (float i = 0.5f; i < app::getWindowWidth() / (2 * particleSize); i++) {
        for (float j = 0.5f; j < app::getWindowHeight() / (2 * particleSize); j++) {
            ci::Vec2f pos = Vec2f ( (particleSize * 2 * i), (particleSize * 2 * j) );
            particles.push_back( *new particle( pos, particleSize, ci::Color(1.0, 1.0, 1.0) ) );
        }
    }
}

void ParticleGridsApp::makePattern() {
    
    Vec2f multiplier = Vec2f( randFloat(0.05, 0.2), randFloat(0.05, 0.2) );
    
    for ( int i = 0; i < particles.size(); i++ ) {
        if (currentPattern == cosplussin) {
            particles[i].size = cos( particles[i].position.y * multiplier.y ) + sin( particles[i].position.x * multiplier.x ) + 2.0f;
        } else if (currentPattern == coscircles) {
            particles[i].size = ( cos( particles[i].position.y * particles[(i + 20) % particles.size()].position.x ) + 1.0f ) * 2.0f;
        } else if (currentPattern == sinconsinsquared) {
            float xyOffset = sin( cos( sin( particles[i].position.y * 0.3183f ) + cos( particles[i].position.x * 0.3183f ) ) ) + 1.0f;
            particles[i].size = xyOffset * xyOffset * 1.8f;
        }
        
    }
}

void ParticleGridsApp::mouseDown( MouseEvent event )
{
    setup();
}

void ParticleGridsApp::update()
{

    
}

void ParticleGridsApp::draw()
{
    // clear out the window with black
    gl::clear( Color( 0, 0, 0 ) );
    
    for( int i = 0; i < particles.size(); i++ ) {
        particles[i].draw();
    }
}

CINDER_APP_BASIC( ParticleGridsApp, RendererGl )
