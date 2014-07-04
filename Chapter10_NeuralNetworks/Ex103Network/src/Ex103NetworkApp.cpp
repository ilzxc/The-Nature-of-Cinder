#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Network.h"
#include "Neuron.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex103NetworkApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
    void setup();
    void update();
    void draw();
    
  private:
    unique_ptr< Network > network;
    unique_ptr< Rand > random;
};

void Ex103NetworkApp::prepareSettings( Settings* settings )
{
    settings->setWindowSize( 640, 360 );
}

void Ex103NetworkApp::setup()
{
    gl::enableAlphaBlending();
    
    random = unique_ptr< Rand >( new Rand() );
    random->randomize();
    
    network = unique_ptr< Network >( new Network( getWindowCenter().x, getWindowCenter().y ) );
    shared_ptr< Neuron > a = make_shared< Neuron >( -275.f,   0.f );
    shared_ptr< Neuron > b = make_shared< Neuron >( -150.f,   0.f );
    shared_ptr< Neuron > c = make_shared< Neuron >(    0.f,  75.f );
    shared_ptr< Neuron > d = make_shared< Neuron >(    0.f, -75.f );
    shared_ptr< Neuron > e = make_shared< Neuron >(  150.f,   0.f );
    shared_ptr< Neuron > f = make_shared< Neuron >(  275.f,   0.f );
    network->addNeuron( a );
    network->addNeuron( b );
    network->addNeuron( c );
    network->addNeuron( d );
    network->addNeuron( e );
    network->addNeuron( f );
    network->connect( a, b, 1 );
    network->connect( b, c, random->randFloat() );
    network->connect( b, d, random->randFloat() );
    network->connect( c, e, random->randFloat() );
    network->connect( d, e, random->randFloat() );
    network->connect( e, f, 1 );
}

void Ex103NetworkApp::update()
{
    network->update();
    if ( getElapsedFrames() % 30 == 0 ) {
        network->feedforward( random->randFloat() );
    }
}

void Ex103NetworkApp::draw()
{
    gl::clear( Color( 1.f, 1.f, 1.f ) );
    network->draw();
}

CINDER_APP_NATIVE( Ex103NetworkApp, RendererGl )
