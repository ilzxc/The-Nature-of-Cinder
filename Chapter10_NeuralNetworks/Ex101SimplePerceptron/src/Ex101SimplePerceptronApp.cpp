#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Trainer.h"
#include "Perceptron.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex101SimplePerceptronApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
    void setup();
    void update();
    void draw();
    
  private:
    shared_ptr< Rand > random;
    unique_ptr< Perceptron > ptron;
    vector< unique_ptr< Trainer > > training;
    vector< float > weights;
    int count;
    float xmin, ymin, xmax, ymax; // coordinate space
    Vec2f line_start, line_end;
    Vec2f train_start, train_end;
    float f( const float x ) { return 0.4f * x + 1; }
    const int NUM_TRAINERS = 2000;
};

void Ex101SimplePerceptronApp::prepareSettings( Settings* settings )
{
    settings->setWindowSize( 820, 320 );
}

void Ex101SimplePerceptronApp::setup()
{
    random = make_shared< Rand >();
    random->randomize();
    ptron = unique_ptr< Perceptron>( new Perceptron( 3, 0.0001f, random ) ); // low learning constant, see Shiffman for details
    count = 0;
    xmin = -400;
    ymin = -100;
    xmax =  400;
    ymax =  100;
    
    line_start.set( xmin, f( xmin ) );
    line_end.set( xmax, f( xmax ) );
    train_start = Vec2f( xmin, ymin );
    train_end = Vec2f( xmax, ymax );
    
    Rand::randomize();
    
    for ( auto i = 0; i < NUM_TRAINERS; ++i ) {
        float x = Rand::randFloat( xmin, xmax );
        float y = Rand::randFloat( ymin, ymax );
        int answer = 1;
        if ( y < f( x ) ) {
            answer = -1;
        }
        training.push_back( unique_ptr< Trainer >( new Trainer( x, y, answer ) ) );
    }
    
    gl::enableAlphaBlending();
}

void Ex101SimplePerceptronApp::update()
{
    weights = ptron->getWeights();
    train_start.y = ( -weights[ 2 ] - weights[ 0 ] * train_start.x ) / weights[ 1 ];
    train_end.y = ( -weights[ 2 ] - weights[ 0 ] * train_end.x ) / weights[ 1 ];
    ptron->train( training[ count ]->inputs, training[ count ]->answer );
    count = ( count + 1 ) % training.size();
}

void Ex101SimplePerceptronApp::draw()
{
    gl::clear( Color( 0.888f, 0.888f, 0.888f ) );
    gl::color( 0.f, 0.f, 0.f );
    gl::pushMatrices();
    gl::translate( getWindowCenter() );
    for ( auto i = 0; i < count; ++i ) {
        int guess = ptron->feedforward( training[ i ]->inputs );
        if ( guess > 0 ) {
            gl::drawStrokedCircle( Vec2f( training[ i ]->inputs[ 0 ], training[ i ]->inputs[ 1 ] ), 4.f );
            
        } else {
            gl::drawSolidCircle( Vec2f( training[ i ]->inputs[ 0 ], training[ i ]->inputs[ 1 ] ), 4.f );
        }
    }
    gl::lineWidth( 4 );
    gl::color( 0., 0.444f, 0.f, 0.5f );
    gl::drawLine( line_start, line_end );
    gl::lineWidth( 1 );
    gl::color( 0.f, 0.f, 0.f );
    gl::drawLine( train_start, train_end );
    gl::popMatrices();
}

CINDER_APP_NATIVE( Ex101SimplePerceptronApp, RendererGl )
