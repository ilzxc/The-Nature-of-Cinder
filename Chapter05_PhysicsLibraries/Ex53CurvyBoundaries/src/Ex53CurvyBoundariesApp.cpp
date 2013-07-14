#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Box2D/Box2D.h"
#include "Particle.h"
#include "GroundSurface.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex53CurvyBoundariesApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );
    void mouseUp( MouseEvent event );
	void update();
	void draw();
    
    std::vector<Particle> particles;
    GroundSurface ground;
    b2World * world;
    float32 timeStep;
    int32 velocityIterations;
    int32 positionIterations;
};

void Ex53CurvyBoundariesApp::setup() {
    b2Vec2 gravity = b2Vec2(0.0, 10.0f);
    world = new b2World( gravity );
    timeStep = 1.0f / 60.0f;
    velocityIterations = 8;
    positionIterations = 3;
    
    Rand::randomize();
    
    std::vector<Vec2f> groundPoints;
    groundPoints.push_back( Vec2f( getWindowWidth(), 3.0f * getWindowHeight() / 4.0f) );
    groundPoints.push_back( Vec2f( getWindowWidth() / 2.0f, 3.0f * getWindowHeight() / 4.0f - 100.0f) );
    groundPoints.push_back( Vec2f( 0.0f, 3.0f * getWindowHeight() / 4.0f) );
    
    std::vector<Vec2f> screenPoints;
    screenPoints.push_back( Vec2f( 0.0f, 3.0f * getWindowHeight() / 4.0f) );
    screenPoints.push_back( Vec2f( getWindowWidth() / 2.0f, 3.0f * getWindowHeight() / 4.0f - 100.0f) );
    screenPoints.push_back( Vec2f( 0.0f, getWindowHeight() ) );
    screenPoints.push_back( Vec2f( getWindowWidth(), 3.0f * getWindowHeight() / 4.0f) );
    screenPoints.push_back( Vec2f( getWindowWidth(), getWindowHeight() ) );

    ground = GroundSurface( world, groundPoints, screenPoints );
}

void Ex53CurvyBoundariesApp::mouseDown( MouseEvent event ) {
    gl::enableWireframe();
}

void Ex53CurvyBoundariesApp::mouseUp( MouseEvent event ) {
    gl::disableWireframe();
}

void Ex53CurvyBoundariesApp::update() {
    
    particles.push_back( Particle( world, Rand::randFloat( getWindowWidth() ), -20.0f, Rand::randFloat(8.0f, 12.0f) ) );
    
    world->Step( timeStep, velocityIterations, positionIterations );
    
    for (std::vector<Particle>::iterator iter = particles.begin(); iter != particles.end();) {
        iter->update( world );
        if ( iter->isDead() ) {
            iter->killBody( world );
            iter = particles.erase( iter );
        } else {
            ++iter;
        }
    }
    
    cout << world->GetBodyCount() << endl;
}

void Ex53CurvyBoundariesApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 1, 1, 1 ) );
    
    ground.draw();
    
    for ( auto& p : particles) {
        p.draw();
    }
}

CINDER_APP_NATIVE( Ex53CurvyBoundariesApp, RendererGl )
