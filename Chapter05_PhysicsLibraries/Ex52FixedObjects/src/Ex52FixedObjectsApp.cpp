#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Conversions.h"
#include <Box2D/Box2D.h>
#include "Box.h"
#include "Boundary.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex52FixedObjectsApp : public AppNative {
  public:
    void setup();
    void mouseMove( MouseEvent event );
    void mouseDrag( MouseEvent event );
    void mouseDown( MouseEvent event );
    void mouseUp( MouseEvent event );
    void update();
    void draw();
    void shutdown();
    
    b2World* world;
    
    Vec2f mousePosition;
    bool addBoxes;
    vector<Box> boxes;
    vector<Boundary> boundaries;
};

void Ex52FixedObjectsApp::setup() {
    // world:
    b2Vec2 gravity = b2Vec2( 0.0f, 10.0f );
    world = new b2World( gravity );
    addBoxes = false;
    
    boundaries.push_back( Boundary( world, 10.0f, getWindowHeight()-5, getWindowWidth() / 2 - 50, 5) );
    boundaries.push_back( Boundary( world, 3 * getWindowWidth() / 4, getWindowHeight() - 50, getWindowWidth() / 4 - 50, 5 ) );
}

void Ex52FixedObjectsApp::mouseDown( MouseEvent event ) {
    addBoxes = true;
}

void Ex52FixedObjectsApp::mouseUp( MouseEvent event ) {
    addBoxes = false;
}

void Ex52FixedObjectsApp::mouseMove( MouseEvent event ) {
    mousePosition = event.getPos();
}

void Ex52FixedObjectsApp::mouseDrag( MouseEvent event ) {
    mouseMove( event );
}

void Ex52FixedObjectsApp::update() {
    
    if (addBoxes) {
        boxes.push_back( Box( world, mousePosition.x, mousePosition.y, Rand::randFloat(5.0f, 20.0f), Rand::randFloat(5.0f, 20.0f) ) );
    }
    
    // World step:
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 8;
    int32 positionIterations = 3;
    world->Step( timeStep, velocityIterations, positionIterations );
    
    for ( std::vector<Box>::iterator iter = boxes.begin(); iter != boxes.end(); ) {
        iter->update( world );
        if (iter->isDead()) {
            world->DestroyBody( iter->getBody() );
            boxes.erase( iter );
        } else {
            ++iter;
        }
    }
}

void Ex52FixedObjectsApp::draw()
{
    // clear out the window with black
    gl::clear( Color( 0, 0, 0 ) );
    for ( auto& b : boxes ) {
        b.draw();
    }
    
    for ( auto& boundary : boundaries ) {
        boundary.draw();
    }
}

void Ex52FixedObjectsApp::shutdown() {
    for (auto& b : boxes) {
        world->DestroyBody( b.getBody() );
    }
    delete world;
}

CINDER_APP_NATIVE( Ex52FixedObjectsApp, RendererGl )
