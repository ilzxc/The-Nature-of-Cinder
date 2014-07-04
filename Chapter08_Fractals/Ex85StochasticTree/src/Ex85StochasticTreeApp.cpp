#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "cinder/Perlin.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex85StochasticTreeApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
    void setup();
    void mouseDown( MouseEvent event ); 
    void update();
    void draw();
    
  private:
    float yoff;
    int   seed;
    Rand  random;
    Perlin perlin;
    
    void  branch( const float h, const float xoff );
    
};

void Ex85StochasticTreeApp::prepareSettings( Settings* settings )
{
    settings->setWindowSize( 800, 200 );
}

void Ex85StochasticTreeApp::setup()
{
    gl::color( 0.f, 0.f, 0.f );
}

void Ex85StochasticTreeApp::mouseDown( MouseEvent event )
{
    yoff = random.nextFloat( 1000.f );
    seed = getElapsedSeconds() * 1000;
}

void Ex85StochasticTreeApp::update()
{
    yoff += 0.005f;
    random.seed( seed );
}

void Ex85StochasticTreeApp::draw()
{
    gl::clear( Color{ 1.f, 1.f, 1.f } );
    gl::pushMatrices();
    gl::translate( Vec2f( getWindowCenter().x, app::getWindowHeight() ) );
    branch( 60, 0 );
    gl::popMatrices();
}

void Ex85StochasticTreeApp::branch( const float h, const float xoff )
{
    auto endpoint = Vec2f{ 0.f, -h };
    gl::drawLine( Vec2f::zero(), endpoint );
    gl::translate( endpoint );
    
    auto new_h = h * 0.7f;
    auto new_xoff = xoff + 0.1f;
    
    if ( h > 4 ) {
        auto n = random.nextInt( 1, 5 );
        for ( auto i = 0; i < n; ++i ) {
            auto theta = ( perlin.noise( xoff + i, yoff ) * 60 - 30 );
            if ( ( n % 2 ) == 0 ) { theta *= -1; }
            
            gl::pushMatrices();
            gl::rotate( theta );
            branch( new_h, new_xoff );
            gl::popMatrices();
        }
    }
}

CINDER_APP_NATIVE( Ex85StochasticTreeApp, RendererGl )
