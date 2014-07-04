#include <vector>
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "FlowField.h"
#include "Vehicle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex64FlowFieldFollowingApp : public AppNative {
public:
    void setup();
    void resize();
    void mouseDown( MouseEvent event );
    void update();
    void draw();
    
    unique_ptr< FlowField > flowfield;
    std::vector< unique_ptr< Vehicle > > vehicles;
};

void Ex64FlowFieldFollowingApp::setup()
{
    flowfield = unique_ptr< FlowField > ( new FlowField{ 20 } );
    for ( auto i = 0; i < 1000; ++i ) {
        vehicles.push_back( unique_ptr< Vehicle > ( new Vehicle( Vec2f( Rand::randFloat( getWindowWidth() ), Rand::randFloat( getWindowHeight() ) ), Rand::randFloat( 0.03f, 0.09f ), Rand::randFloat( 2.0f, 5.0f ) ) ) );
    }
}

void Ex64FlowFieldFollowingApp::resize()
{
    flowfield = unique_ptr < FlowField > ( new FlowField{ 20 } );
}

void Ex64FlowFieldFollowingApp::mouseDown( MouseEvent event )
{
    flowfield->init();
}

void Ex64FlowFieldFollowingApp::update()
{
    for ( auto& v : vehicles ) {
        v->update( *flowfield );
    }
}

void Ex64FlowFieldFollowingApp::draw()
{
    gl::clear( Color{ 1.f, 1.f, 1.f } );
    flowfield->draw();
    for ( auto& v : vehicles ) {
        v->draw();
    }
}

CINDER_APP_NATIVE( Ex64FlowFieldFollowingApp, RendererGl )
