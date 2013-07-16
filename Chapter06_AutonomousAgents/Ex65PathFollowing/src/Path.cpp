#include "Path.h"

void Path::addPoint( float x, float y ) {
	points.push_back( Vec2f( x, y ) );
}

Vec2f Path::getStart() const {
	return points[0];
}

Vec2f Path::getEnd() const {
	return points[points.size() - 1];
}

float Path::getRadius(void) const {
	return radius / 2.0f;
}

std::vector< Vec2f > Path::getPoints() const {
	return points;
}

void Path::reset() {
	points.clear();
}

void Path::draw() const {
	gl::color( 0.777f, 0.777f, 0.777f );
	gl::lineWidth( radius );
	gl::begin(GL_LINE_STRIP);
    for (auto& p : points) {
        gl::vertex( p );
    }
    gl::end();

	for (auto& p : points) {
		gl::drawSolidCircle( p, radius * 0.75f );
	}

	gl::color( 0.777f, 0.0f, 0.0f );
	gl::lineWidth( 1.0f );
	gl::begin(GL_LINE_STRIP);
    for (auto& p : points) {
        gl::vertex( p );
    }
    gl::end();
}