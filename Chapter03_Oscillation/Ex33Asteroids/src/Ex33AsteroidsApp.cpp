#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "SpaceShip.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex33AsteroidsApp : public AppNative {
  public:
    // void prepareSettings ( Settings *settings );
	void setup();
    void keyDown( KeyEvent event );
    void keyUp( KeyEvent event );
    void setKeysTo( const KeyEvent event, const bool what );
	void update();
	void draw();
    
    int definedKeys[3];
    bool keys[3];
    SpaceShip ship;
};

void Ex33AsteroidsApp::setup() {
    definedKeys[0] = KeyEvent::KEY_LEFT;
    definedKeys[1] = KeyEvent::KEY_RIGHT;
    definedKeys[2] = KeyEvent::KEY_UP;
    
    keys[0] = keys[1] = keys[2] = false;
    
    ship = SpaceShip( getWindowWidth() / 2, getWindowHeight() / 2 );
}

void Ex33AsteroidsApp::keyDown( KeyEvent event ) {
    setKeysTo( event, true );
}

void Ex33AsteroidsApp::keyUp( KeyEvent event ) {
    setKeysTo( event, false );
}

void Ex33AsteroidsApp::setKeysTo(const KeyEvent event, const bool what) {
    for (int i = 0; i < 3; i++) {
        if ( (what && !keys[i]) || (!what && keys[i]) ) { // only update if setting != what
            if(event.getCode() == definedKeys[i]) {
                keys[i] = what;
            }
        }
    }
}

void Ex33AsteroidsApp::update() {
    ship.update( keys );
}

void Ex33AsteroidsApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    ship.draw();
}

CINDER_APP_NATIVE( Ex33AsteroidsApp, RendererGl )
