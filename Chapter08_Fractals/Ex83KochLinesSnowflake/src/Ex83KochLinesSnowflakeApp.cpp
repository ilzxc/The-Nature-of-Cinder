#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include <vector>
#include "KochLine.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex83KochLinesSnowflakeApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
	void setup();
	void draw();
    
  private:
    std::vector< KochLine > lines;
    void generate();
};

void Ex83KochLinesSnowflakeApp::prepareSettings( Settings* settings )
{
    settings->setWindowSize( 600, 693 );
}

void Ex83KochLinesSnowflakeApp::setup()
{
    gl::color( 0.f, 0.f, 0.f );
    
    auto a = Vec2f{ 0, 173 };
    auto b = Vec2f{ app::getWindowWidth(), 173 };
    auto c = Vec2f{ app::getWindowWidth() / 2, 173 + app::getWindowWidth() * cos( toRadians( 30.f ) ) };
    
    lines.push_back( KochLine( a, b ) );
    lines.push_back( KochLine( b, c ) );
    lines.push_back( KochLine( c, a ) );
    
    for ( auto i = 0; i < 4; ++i ) {
        generate();
    }
}

void Ex83KochLinesSnowflakeApp::draw()
{
	gl::clear( Color{ 1.f, 1.f, 1.f } );
    for ( auto& l : lines ) {
        l.draw();
    }
}

void Ex83KochLinesSnowflakeApp::generate()
{
    std::vector< KochLine > next;
    for ( auto& l : lines ) {
        auto a = l.kochA();
        auto b = l.kochB();
        auto c = l.kochC();
        auto d = l.kochD();
        auto e = l.kochE();
        next.push_back( KochLine( a, b ) );
        next.push_back( KochLine( b, c ) );
        next.push_back( KochLine( c, d ) );
        next.push_back( KochLine( d, e ) );
    }
    lines.clear();
    lines = next;
}

CINDER_APP_NATIVE( Ex83KochLinesSnowflakeApp, RendererGl )
