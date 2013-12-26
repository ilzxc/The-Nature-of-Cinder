#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex84TreeApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
    void mouseMove( MouseEvent event );
	void draw();
    
  private:
    float theta;
    void branch( const float length );
    
};

void Ex84TreeApp::prepareSettings( Settings* settings )
{
    settings->setWindowSize( 640, 360 );
}

void Ex84TreeApp::mouseMove( MouseEvent event )
{
    theta = ( event.getPos().x / ( 1.f * app::getWindowWidth() ) ) * 90;
}

void Ex84TreeApp::draw()
{
	gl::clear( Color{ 1.f, 1.f, 1.f } );
    gl::color( 0.f, 0.f, 0.f );
    gl::pushMatrices();
    gl::translate( app::getWindowCenter().x, app::getWindowHeight() );
    branch( 120.f );
    gl::popMatrices();
}

void Ex84TreeApp::branch( const float length )
{
    auto endpoint = Vec2f{ 0.f, -length };
    gl::drawLine( Vec2f::zero(), endpoint );
    gl::translate( endpoint );
    float next_length = length * 0.66f;     // Each branch to be 2/3rds of the previous size:
    
    if ( length > 2 ) {
        gl::pushMatrices();
        gl::rotate( theta );
        branch( next_length );
        gl::popMatrices();
        
        gl::pushMatrices();
        gl::rotate( -theta );
        branch( next_length );
        gl::popMatrices();
    }
    
}

CINDER_APP_NATIVE( Ex84TreeApp, RendererGl )
