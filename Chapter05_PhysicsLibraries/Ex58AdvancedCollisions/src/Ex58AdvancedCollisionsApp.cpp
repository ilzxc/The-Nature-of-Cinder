#include "Box2D/Box2d.h"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Boundary.h"
#include "Square.h"
#include "Circle.h"
#include "Triugolnik.h"
#include "CollisionDetection.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex58AdvancedCollisionsApp : public AppNative {
  public:
	void setup();
	void update();
	void draw();
    void shutdown();
    
    b2World *world;
    float32 timeStep;
    int32 velocityIterations;
    int32 positionIterations;
    
    vector< Square* > squares;
    vector< Triugolnik* > triangles;
    vector< Circle* > circles;
    
    Boundary* floor;
    
    CollisionDetection collisions;
};

void Ex58AdvancedCollisionsApp::setup() {
    world = new b2World( b2Vec2( 0.0f, 10.0f ) );
    timeStep = 1.0f / 60.0f;
    velocityIterations = 8;
    positionIterations = 3;
    
    world->SetContactListener( &collisions );
    
    floor = new Boundary( world, 0.0f, getWindowHeight() - 50.0f, getWindowWidth(), 10.0f );
    
    Rand::randomize();
}

void Ex58AdvancedCollisionsApp::update() {
    if ( Rand::randInt( 100 ) == 90 ) {
        squares.push_back( new Square( world, Vec2f( Rand::randFloat( getWindowWidth() ), -10.0f ), 0.0f, 10.0f ) );
    }
    if ( Rand::randInt( 100 ) == 90 ) {
    circles.push_back( new Circle( world, Vec2f( Rand::randFloat( getWindowWidth() ), -10.0f ), 0.0f, 10.0f ) );
    }
    if ( Rand::randInt( 100 ) == 90 ) {
    triangles.push_back( new Triugolnik( world, Vec2f( Rand::randFloat( getWindowWidth() ), -10.0f ), 0.0f, 10.0f ) );
    }
    
    world->Step( timeStep, velocityIterations, positionIterations );
    
    for ( auto& s : squares ) {
        s->update();
    }
    
    for ( auto& t : triangles ) {
        t->update();
    }
    
    for ( auto& c : circles ) {
        c->update();
    }
    
}

void Ex58AdvancedCollisionsApp::draw() {
	gl::clear( Color( 0.888f, 0.888f, 0.888f ) );
    for ( auto&  s : squares ) {
        s->draw();
    }
    
    for ( auto& t : triangles ) {
        t->draw();
    }
    
    for ( auto& c : circles ) {
        c->draw();
    }
    
    floor->draw();
}

void Ex58AdvancedCollisionsApp::shutdown()  {
    for ( auto&  s : squares ) {
        s->killBody( world );
        delete s;
    }
    
    for ( auto& t : triangles ) {
        t->killBody( world );
        delete t;
    }
    
    for ( auto& c : circles ) {
        c->killBody( world );
        delete c;
    }
    
    delete floor;
    delete world;
}

CINDER_APP_NATIVE( Ex58AdvancedCollisionsApp, RendererGl )
