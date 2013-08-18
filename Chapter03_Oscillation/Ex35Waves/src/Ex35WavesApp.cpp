#include <vector>
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Wave.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex35WavesApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
	void setup();
	void mouseDown( MouseEvent event );
    void mouseUp( MouseEvent e );
	void update();
	void draw();
    
    vector< Wave > waves;
};

void Ex35WavesApp::prepareSettings( Settings* settings ) {
    settings->setWindowSize( 900, 300 );
    settings->setResizable( false );
}

void Ex35WavesApp::setup() {
    gl::enableAlphaBlending();
    float gutter = 10.0f;
    float xMult = ( getWindowWidth() - ( 2.0 * gutter ) ) / 3.0f;
    float angleVelocities[] = { 0.02f, 0.06f, 0.1f };
    for ( int i = 0; i < 3; ++i ) {
        float useGutter = ( i == 0 ) ? 0.0f : gutter;
        waves.push_back( Wave( xMult + 1, getWindowHeight(), Vec2f( ( xMult + useGutter ) * i , 0.0f ), 25, angleVelocities[i] ) );
    }
}

void Ex35WavesApp::mouseDown( MouseEvent event ) {
    gl::enableWireframe();
}

void Ex35WavesApp::mouseUp( MouseEvent e ) {
    gl::disableWireframe();
}

void Ex35WavesApp::update() {
    for ( auto& wave : waves ) {
        wave.update();
    }
}

void Ex35WavesApp::draw()
{
	gl::clear( Color( 0.222f, 0.222f, 0.222f ) );
    for ( auto& wave : waves ) {
        wave.draw();
    }
}

CINDER_APP_NATIVE( Ex35WavesApp, RendererGl )
