#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex1_1_BallWithoutVectorsApp : public AppBasic {
  public:
    void prepareSettings(Settings *settings);
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    float x, y;
    float xspeed, yspeed;
    float cRadius;
    bool squish;
    float squishx, squishy;
};

void Ex1_1_BallWithoutVectorsApp::prepareSettings(Settings *settings) {
    settings -> setWindowSize(900, 300);
    settings -> setFrameRate(25.0f);
}

void Ex1_1_BallWithoutVectorsApp::setup()
{
    x = getWindowWidth()   / 2.0f;
    y = getWindowHeight()  / 2.0f;
    
    float maximum = 90.0f;
    squish = false; squishx = squishy = 0;
    
    Rand::randomize();
    
    xspeed = randFloat(maximum) - (maximum / 2.0f);
    yspeed = randFloat(maximum) - (maximum / 2.0f);
    
    cRadius = 20.0f;
}

void Ex1_1_BallWithoutVectorsApp::mouseDown( MouseEvent event )
{
}

void Ex1_1_BallWithoutVectorsApp::update()
{
    
    if (squish) {
        if(squishx != 0) {
            xspeed *= -1.0f;
        }
        
        if(squishy != 0) {
            yspeed *= -1.0f;
        }
        
        squishx = squishy = 0.0f;
        squish = false;
    }
    
    x += xspeed;
    y += yspeed;
    
    if (!squish){
        if ( (x < cRadius) || (x > (getWindowWidth() - cRadius) ) ) {
            squish = true;
            squishx = (x < cRadius) ? cRadius - x : (cRadius - (getWindowWidth() - x));
        }        
        if ( (y < cRadius) || (y > (getWindowHeight() - cRadius)) ) {
            squish = true;
            squishy = (y < cRadius) ? cRadius - y : (cRadius - (getWindowHeight() - y));
        }
    }
}

void Ex1_1_BallWithoutVectorsApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
    gl::color(0.0f, 0.5f, 1.0f, 1.0f);
    if (!squish) {
        gl::drawSolidCircle( Vec2f(x, y), cRadius, 0);
    } else {
        gl::drawSolidEllipse( Vec2f(x, y), cRadius - squishx + squishy, cRadius - squishy + squishx);
    }
}

CINDER_APP_BASIC( Ex1_1_BallWithoutVectorsApp, RendererGl )
