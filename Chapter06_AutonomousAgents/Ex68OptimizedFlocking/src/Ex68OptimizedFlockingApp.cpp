#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Boid.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex68OptimizedFlockingApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
    void setup();
    void resize();
    void update();
    void draw();
    
  private:
    vector< std::shared_ptr< Boid > > flock;
    vector< vector< vector< std::shared_ptr< Boid > > > > binLatticeSpatialSubdivision; // optimization - divide the screen into a grid
    const int scale = 5;
    int cols, rows;
};

void Ex68OptimizedFlockingApp::prepareSettings( Settings* settings )
{
    settings->setWindowSize( 800, 600 );
}

void Ex68OptimizedFlockingApp::setup()
{
    gl::enableAlphaBlending();
    Rand random;
    random.randomize();
    for ( auto i = 0; i < 5000; ++i ) { // 10000 boids test (build release to see the full effect)
        if ( random.randBool() ) {
            flock.push_back( shared_ptr< Boid > ( new Boid( random, 0 ) ) );
        } else {
            flock.push_back( shared_ptr< Boid > ( new Boid( random, 1 ) ) );
        }
    }
    cols = getWindowWidth() / scale;
    rows = getWindowHeight() / scale;

    // instantiate the multidimensional vector:
    binLatticeSpatialSubdivision = vector< vector< vector< std::shared_ptr< Boid > > > >( cols, vector< vector< std::shared_ptr< Boid > > >( rows ) );
}

void Ex68OptimizedFlockingApp::resize()
{
    app::setWindowSize( getWindowWidth() - ( getWindowWidth() % 5 ), getWindowHeight() - ( getWindowHeight() % 5 ) );
    binLatticeSpatialSubdivision.clear();
    
    cols = getWindowWidth() / scale;
    rows = getWindowHeight() / scale;
    
    // instantiate the multidimensional vector:
    binLatticeSpatialSubdivision = vector< vector< vector< std::shared_ptr< Boid > > > >( cols, vector< vector< std::shared_ptr< Boid > > >( rows ) );
}

void Ex68OptimizedFlockingApp::update()
{
    // clear the lattice:
    for ( auto& cols : binLatticeSpatialSubdivision ) {
        for ( auto& square : cols ) {
            square.clear();
        }
    }
    
    // update location:
    for ( auto& boid : flock ) {
        boid->updateLocation();
    }
    
    // put boids into bins:
    for ( auto& boid : flock ) {
        auto x = static_cast< int >( boid->getLocation().x ) / scale;
        auto y = static_cast< int >( boid->getLocation().y ) / scale;
        for ( auto n = -1; n <= 1; ++n ) {
            for ( auto m = -1; m <= 1; ++m ) {
                if ( ( x + n >= 0 ) && ( x + n < cols ) && ( y + m >= 0 ) && ( y + m < rows ) ) {
                    binLatticeSpatialSubdivision[ x + n ][ y + m ].push_back( boid );
                }
            }
        }
    }

    // update boids in bins:
    for ( auto& cols : binLatticeSpatialSubdivision ) {
        for ( auto& rows : cols ) {
            for ( auto& boid : rows ) {
                boid->update( rows );
            }
        }
    }
}

void Ex68OptimizedFlockingApp::draw()
{
    gl::clear( Color{ 1.f, 1.f, 1.f } );
    for ( const auto& boid : flock ) {
        boid->draw();
    }
}

CINDER_APP_NATIVE( Ex68OptimizedFlockingApp, RendererGl )
