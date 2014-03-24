#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Fbo.h"
#include "LSystem.h"
#include "Turtle.h"
#include "Rule.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex86LSystemApp : public AppNative {
  public:
    void prepareSettings( Settings* settings );
    void setup();
    void mouseDown( MouseEvent event );	
    void draw();
    void redraw();
    
  private:
    unique_ptr< LSystem > lsys;
    unique_ptr< Turtle > turtle;
    int counter;
    unique_ptr< gl::Fbo > result;
};

void Ex86LSystemApp::prepareSettings( Settings* settings )
{
    settings->setWindowSize( 600, 600 );
}

void Ex86LSystemApp::setup()
{
    result = unique_ptr< gl::Fbo >( new gl::Fbo( getWindowWidth(), getWindowHeight() ) );
    result->bindFramebuffer();
    gl::clear( Color( 1.f, 1.f, 1.f ) );
    result->unbindFramebuffer();
    vector< Rule > ruleset;
    ruleset.push_back( Rule( 'F', "FF+[+F-F-F]-[-F+F+F]" ) );
    lsys = unique_ptr< LSystem >( new LSystem( "F", ruleset ) );
    turtle = unique_ptr< Turtle >( new Turtle( lsys->getSentence(), getWindowHeight() / 3.f, toRadians( 25.f ) ) );
    counter = 0;
}

void Ex86LSystemApp::mouseDown( MouseEvent event )
{
    if ( counter < 6 ) {
        result->bindFramebuffer();
        gl::pushMatrices();
        lsys->generate();
        turtle->setToDo( lsys->getSentence() );
        turtle->changeLen( 0.5f );
        gl::popMatrices();
        redraw();
        ++counter;
        result->unbindFramebuffer();
    }
}

void Ex86LSystemApp::draw()
{
    gl::clear( Color( 0.f, 0.f, 0.f ) );
    gl::color( 1.f, 1.f, 1.f );
    gl::draw( result->getTexture() );
}

void Ex86LSystemApp::redraw()
{
	gl::clear( Color( 1.f, 1.f, 1.f ) );
    gl::pushMatrices();
    gl::translate( Vec2f( getWindowCenter().x, 0.f ) );
    gl::rotate( 90.f );
    gl::color( 0.f, 0.f, 0.f );
    turtle->render();
    gl::popMatrices();
}

CINDER_APP_NATIVE( Ex86LSystemApp, RendererGl )
