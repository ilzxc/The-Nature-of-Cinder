#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "SpaceShip.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex33AsteroidsApp : public AppNative {
  public:
	void setup();
    void keyDown( KeyEvent event );
    void keyUp( KeyEvent event );
    void setKeysTo( const KeyEvent event, const bool setTo );
	void update();
	void draw();
    
    int definedKeys[3];
    bool keys[3];
    std::unique_ptr< SpaceShip > ship;
};

void Ex33AsteroidsApp::setup() {
    definedKeys[0] = KeyEvent::KEY_LEFT;
    definedKeys[1] = KeyEvent::KEY_RIGHT;
    definedKeys[2] = KeyEvent::KEY_UP;
    keys[0] = keys[1] = keys[2] = false;
    ship = std::unique_ptr< SpaceShip > ( new SpaceShip( getWindowWidth() / 2, getWindowHeight() / 2 ) );
}

void Ex33AsteroidsApp::keyDown( KeyEvent event ) {
    setKeysTo( event, true );
}

void Ex33AsteroidsApp::keyUp( KeyEvent event ) {
    setKeysTo( event, false );
}

void Ex33AsteroidsApp::setKeysTo( const KeyEvent event, const bool setTo ) {
    for ( int i = 0; i < 3; ++i ) {
        if ( ( setTo && !keys[i] ) || ( !setTo && keys[i] ) ) { // only update if setting != setTo
            if( event.getCode() == definedKeys[i] ) {
                keys[i] = setTo;
            }
        }
    }
}

void Ex33AsteroidsApp::update() {
    ship->update( keys );
}

void Ex33AsteroidsApp::draw() {
	gl::clear( Color( 0.0f, 0.0f, 0.0f ) );
    ship->draw();
}

CINDER_APP_NATIVE( Ex33AsteroidsApp, RendererGl )
