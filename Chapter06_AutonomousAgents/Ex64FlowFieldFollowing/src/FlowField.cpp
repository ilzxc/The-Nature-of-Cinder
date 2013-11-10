//
//  FlowField.cpp
//  Ex64FlowFieldFollowing
//
//  Created by Ilya Rostovtsev on 7/16/13.
//
//

#include "FlowField.h"

FlowField::FlowField( int r )
: resolution{ r }
{
    auto cols = app::getWindowWidth() / resolution;
    auto rows = app::getWindowHeight() / resolution;
    field.resize( cols, std::vector< Vec2f > ( rows, Vec2f::zero() ) );
    init();
}

void FlowField::init()
{
	Rand::randomize();
	perlin.setSeed( Rand::randFloat( 10000.f ) );
	float xoff = 0.f;
	for ( auto i = 0; i < field.size(); ++i ) {
		auto yoff = 0.f;
		for ( auto j = 0; j < field[ i ].size(); ++j ) {
			auto theta = perlin.fBm( xoff, yoff ) * 2 * M_PI;
			field[ i ][ j ] = Vec2f{ cosf( theta ), sinf( theta ) };
			yoff += 0.1f;
		}
		xoff += 0.1f;
	}
}

void FlowField::drawVector( const Vec2f& vec, const Vec2f& position, const float scale ) const
{
	gl::pushMatrices();
	gl::translate( position );
	gl::color( 0.666f, 0.666f, 0.666f );
	gl::drawLine( Vec2f::zero(), vec * scale );
	gl::popMatrices();

}

Vec2f FlowField::lookup( const Vec2f& lookUp ) const {
	auto column = int( constrain<float>( lookUp.x / resolution, 0, field.size() - 1 ) );
	auto row = int( constrain<float>( lookUp.y / resolution, 0, field[ column ].size() - 1 ) );
	return field[ column ][ row ];
}

void FlowField::draw() const {
	for ( auto i = 0; i < field.size(); ++i ) {
		for ( auto j = 0; j < field[ i ].size(); ++j ) {
			drawVector( field[ i ][ j ], Vec2f{ i * resolution, j * resolution }, resolution - 5 );
		}
	}
}