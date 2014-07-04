#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Population.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex91ShakespeareApp : public AppNative {
  public:
    void setup();
    void mouseDown( MouseEvent event ); 
    void update();
    void draw();
    
    int population_max;
    float mutation_rate;
    unique_ptr < Population > population;
    shared_ptr< Rand > random;
};

void Ex91ShakespeareApp::setup()
{
    string text = "To be or not to be?";
    vector< char > target( text.size() );
    copy( text.begin(), text.end(), target.begin() );

    population_max = 1000;
    mutation_rate = 0.149f;
    random = make_shared< Rand >();
    random->randomize();
    population = unique_ptr< Population > ( new Population{ target, mutation_rate, population_max, random } );
}

void Ex91ShakespeareApp::mouseDown( MouseEvent event )
{
}

void Ex91ShakespeareApp::update()
{
    population->natural_selection();
    
    std::vector< char > answer = population->get_best();
    cout << "Current answer: ";
    for ( auto& letter : answer ) {
        cout << letter;
    }
    cout << endl;
    
    if ( population->is_finished() ) {
        cout << "Finished in " << app::getElapsedSeconds() << " seconds." << endl;
        quit();
    }
}

void Ex91ShakespeareApp::draw()
{
    // clear out the window with black
    gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( Ex91ShakespeareApp, RendererGl )
