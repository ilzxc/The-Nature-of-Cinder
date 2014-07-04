#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex82CantorLinesApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
    void setup();
    void draw();
    
private:
    void drawLines( const Vec2f& p1, const Vec2f& p2 );
};

void Ex82CantorLinesApp::prepareSettings( Settings* settings )
{
    settings->setWindowSize( 800, 400 );
}

void Ex82CantorLinesApp::setup()
{
    gl::color( 0.f, 0.f, 0.f );
}

void Ex82CantorLinesApp::draw()
{
    gl::clear( Color{ 1.f, 1.f, 1.f } );
    drawLines( Vec2f{ 100, 200 }, Vec2f{ 700, 200 } );
}

void  Ex82CantorLinesApp::drawLines( const Vec2f& p1, const Vec2f& p2 )
{
    gl::drawLine( p1, p2 );
    auto dx = p2.x - p1.x;
    auto dy = p2.y - p1.y;
    if ( ( dx == 0 ) && ( dy > 4 ) ) {
        auto diff = dy / 3;
        drawLines( Vec2f{ p1.x - diff, p1.y }, Vec2f{ p1.x + diff, p1.y } );
        drawLines( Vec2f{ p1.x - diff, p2.y }, Vec2f{ p1.x + diff, p2.y } );
    } else if ( ( dy == 0 ) && ( dx > 4 ) ) {
        auto diff = dx / 3;
        drawLines( Vec2f{ p1.x, p1.y - diff }, Vec2f{ p1.x, p1.y + diff } );
        drawLines( Vec2f{ p2.x, p1.y - diff }, Vec2f{ p2.x, p1.y + diff } );
    }
}

CINDER_APP_NATIVE( Ex82CantorLinesApp, RendererGl )
