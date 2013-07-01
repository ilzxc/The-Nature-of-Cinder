#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class UnderstandingImagesApp : public AppNative {
  public:
	void setup();
	void mouseUp( MouseEvent event );
	void update();
	void draw();
    
    Surface spriteSheetSurface;
    gl::Texture spriteSheetTexture;
    gl::Texture frames[9][2];
    
    gl::Texture::Format fmt;
    float angle = 0.0f;
};

void UnderstandingImagesApp::setup() {
    gl::enableAlphaBlending();
    // fmt.setWrap( GL_REPEAT, GL_REPEAT );
    fmt.enableMipmapping( false );
    fmt.setMinFilter( GL_NEAREST );
    fmt.setMagFilter( GL_NEAREST );
    
    
    spriteSheetSurface = loadImage( loadAsset("NESS_allWalk.png") );
    spriteSheetTexture = gl::Texture( spriteSheetSurface, fmt );
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 2; j++) {
            frames[i][j] = gl::Texture( spriteSheetSurface.clone( Area(16 * i, 24 * j, 16 * i + 16, 24 * j + 24) ), fmt );
        }
    }
}

void UnderstandingImagesApp::mouseUp( MouseEvent event )
{
}

void UnderstandingImagesApp::update()
{
    angle += 0.2;
}

void UnderstandingImagesApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 2; j++) {
            gl::pushMatrices();
            gl::translate(Vec2f( 50 + 70 * i, 50 + 100 * j));
            gl::rotate(angle);
            gl::draw( frames[i][j], Area(-8 * 4, -12 * 4, 8 * 4, 12 * 4) );
            gl::popMatrices();
        }
    }
}

CINDER_APP_NATIVE( UnderstandingImagesApp, RendererGl )
