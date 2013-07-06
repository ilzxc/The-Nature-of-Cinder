#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Character.h"
#include "NPC.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NessBox2DApp : public AppNative {
  public:
    void prepareSettings(Settings *Settings);
	void setup();
    void keyDown(KeyEvent event);
    void keyUp(KeyEvent event);
	void update();
	void draw();
    
    Character ness;
    NPC jeff;
    gl::Texture::Format _fmt;
    bool keys[5];
    int definedKeys[5];
    
private:
    void setKeysTo(const KeyEvent event, const bool what);
};

void NessBox2DApp::prepareSettings(Settings *Settings) {
    Settings->setTitle("NESS");
    Settings->setFrameRate(60);
    Settings->setWindowSize(800, 600);
    //Settings->setFullScreen(true);
    // Settings->setResizable(false);
}

void NessBox2DApp::setup()
{
    gl::enableAlphaBlending();
    //gl::enableWireframe();
    //fmt.setWrap( GL_REPEAT, GL_REPEAT );
    _fmt.setMinFilter( GL_NEAREST );
    _fmt.setMagFilter( GL_NEAREST );
    int scale = 3;
    Surface walkStuff = Surface( loadImage( loadResource( "NESS_allWalk.png" ) ) );
    ness = Character( &walkStuff, _fmt, 16, 24, 16 * scale, 24 * scale );
    walkStuff = Surface( loadImage( loadResource( "JEFF_allWalk.png" ) ) );
    jeff = NPC( &walkStuff, _fmt, 16, 24, 16 * scale, 24 * scale );
    
    for (int i = 0; i < 5; i++) {
        keys[i] = false;
    }
    
    definedKeys[0] = KeyEvent::KEY_LEFT;
    definedKeys[1] = KeyEvent::KEY_UP;
    definedKeys[2] = KeyEvent::KEY_RIGHT;
    definedKeys[3] = KeyEvent::KEY_DOWN;
    definedKeys[4] = KeyEvent::KEY_LSHIFT;
}

void NessBox2DApp::keyDown(KeyEvent event) {
    setKeysTo(event, true);
}

void NessBox2DApp::keyUp(KeyEvent event) {
    setKeysTo(event, false);
}

void NessBox2DApp::setKeysTo(const KeyEvent event, const bool what) {
    for (int i = 0; i < 5; i++) {
        if ( (what && !keys[i]) || (!what && keys[i]) ) { // only update if setting != what
            if(event.getCode() == definedKeys[i]) {
                keys[i] = what;
            }
        }
    }
}


void NessBox2DApp::update()
{
    ness.update(keys);
    jeff.update();
}

void NessBox2DApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0.2, 0.2, 0.2 ) );
    if( ness.getY() < jeff.getY() ) {
        ness.draw();
        jeff.draw();
    } else {
        jeff.draw();
        ness.draw();
    }
}

CINDER_APP_NATIVE( NessBox2DApp, RendererGl )
