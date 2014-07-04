#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Vehicle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex102SeekingNeuralApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
    void setup();
    void mouseDown( MouseEvent event ); 
    void update();
    void draw();
    
  private:
    unique_ptr< Vehicle > v;
    vector< Vec2f > targets;
    shared_ptr< Rand > random;
    void make_targets();

};

void Ex102SeekingNeuralApp::prepareSettings( Settings* settings )
{
    settings->setWindowSize( 640, 360 );
    settings->setResizable( false );
}

void Ex102SeekingNeuralApp::setup()
{
    random = make_shared< Rand >();
    random->randomize();
    make_targets();
    v = unique_ptr< Vehicle >( new Vehicle( targets.size(), random->randFloat( getWindowWidth() ), random->randFloat( getWindowHeight() ), random ) );
    gl::enableAlphaBlending();
}

void Ex102SeekingNeuralApp::mouseDown( MouseEvent event )
{
    make_targets();
}

void Ex102SeekingNeuralApp::update()
{
    v->steer( targets );
    v->update();
}

void Ex102SeekingNeuralApp::draw()
{
    gl::clear( Color( 0.878f, 0.878f, 0.878f ) );
    gl::color( 0.f, 0.787f, 0.f, 0.5f );
    gl::drawSolidCircle( getWindowCenter(), 18.f );
    gl::color( 0.f, 0.f, 0.f );
    for ( auto& t : targets ) {
        gl::drawStrokedCircle( t, 8.f );
        gl::drawLine( Vec2f( t.x, t.y - 16.f ), Vec2f( t.x, t.y + 16.f ) );
        gl::drawLine( Vec2f( t.x - 16.f, t.y ), Vec2f( t.x + 16.f, t.y ) );
    }
    v->draw();
}

void Ex102SeekingNeuralApp::make_targets()
{
    targets.clear();
    for ( auto i = 0; i < 8; ++i ) {
        targets.push_back( Vec2f( random->randFloat( getWindowWidth() ), random->randFloat( getWindowHeight() ) ) );
    }
}

CINDER_APP_NATIVE( Ex102SeekingNeuralApp, RendererGl )
