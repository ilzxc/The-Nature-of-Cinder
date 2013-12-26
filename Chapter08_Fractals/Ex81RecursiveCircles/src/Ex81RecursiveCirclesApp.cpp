#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex81RecursiveCirclesApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );
 	void draw();
    
  private:
    short mode;
    void drawCircle( const Vec2f& _center, const float _radius );
};

void Ex81RecursiveCirclesApp::setup()
{
    gl::enableAlphaBlending();
    gl::clear( Color{ 1.f, 1.f, 1.f } );
    gl::color( 0.f, 0.f, 0.f, 0.8f );
    mode = 0;
}

void Ex81RecursiveCirclesApp::mouseDown( MouseEvent event )
{
    ++mode;
    mode %= 3;
}

void Ex81RecursiveCirclesApp::draw()
{
 gl::clear( Color{ 1.f, 1.f, 1.f } );
 drawCircle( app::getWindowCenter(), 400 );
}


void Ex81RecursiveCirclesApp::drawCircle( const Vec2f& _center, const float _radius )
{
    gl::drawStrokedCircle( _center, _radius );
    if ( mode == 0 ) {
        if ( _radius > 8 ) {
            float r = _radius * 0.75f;
            drawCircle( _center, r );
        }
    } else if ( mode == 1 ) {
        if ( _radius > 8 ) {
            float r = _radius / 2;
            Vec2f c = { _center.x + r, _center.y };
            drawCircle( c, r );
            c.x = _center.x - r;
            drawCircle( c, r );
        }
    } else {
        if ( _radius > 8 ) {
            float r = _radius / 2;
            Vec2f c = { _center.x + r, _center.y };
            drawCircle( c, r );
            c.x = _center.x - r;
            drawCircle( c, r );
            c.x = _center.x;
            c.y = _center.y + r;
            drawCircle( c, r );
            c.y = _center.y - r;
            drawCircle( c, r );
        }
    }
    
}

CINDER_APP_NATIVE( Ex81RecursiveCirclesApp, RendererGl )
