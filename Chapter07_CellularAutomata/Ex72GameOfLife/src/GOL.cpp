//
//  GOL.cpp
//  Ex72GameOfLife
//
//  Created by Ilya Rostovtsev on 11/11/13.
//
//

#include "GOL.h"

GOL::GOL()
: columns{ app::getWindowWidth() / w },
rows{ app::getWindowHeight() / w },
board{ vector< vector< Cell > >( columns, vector< Cell >( rows ) ) }
{
    cout << "grid is " << columns << "x" << rows << endl;
    random.randomize();
    init();
}
    
GOL::~GOL()
{
    board.clear();
}
    
void GOL::init()
{
    for ( auto x = 0; x < board.size(); ++x ) {
        for ( auto y = 0; y < board[x].size(); ++y ) {
            auto rState = random.nextInt( 2 );
            auto xVal = x * w;
            auto yVal = y * w;
            board[ x ][ y ].set( xVal, yVal, w, rState );
        }
    }
}

void GOL::generate()
{
    // create a new generation:
    for ( auto& cols : board ) {
        for ( auto& cell : cols ) {
            cell.savePrevious();
        }
    }
    
    // loop through every cell in our 2D vector and check neighbors:
    for ( int x = 0; x < board.size(); ++x ) {
        for ( int y = 0; y < board[ x ].size(); ++y ) {
            int neighbors = 0;
            for ( auto i = -1; i <= 1; ++i ) {
                for ( auto j = -1; j <= 1; ++j ) {
                    neighbors += board[ ( x + i + columns ) % columns ][ ( y + j + rows ) % rows ].getPrevious();
                    
                }
            }
            
            // subtract the current cell's state (since we added it in the above loop)
            neighbors -= board[x][y].getPrevious();
            
            // rules of life:
            if ( ( board[ x ][ y ].getState() == 1 ) && ( neighbors < 2 ) ) {
                board[ x ][ y ].newState( 0 );
            } else if ( ( board[x][y].getState() == 1 ) && ( neighbors > 3 ) ) {
                board[ x ][ y ].newState( 0 );
            } else if ( ( board[x][y].getState() == 0 ) && ( neighbors == 3 ) ) {
                board[ x ][ y ].newState( 1 );
            }
        }
    }
    
}

void GOL::draw() const
{
    for ( int x = 0; x < board.size(); ++x ) {
        for ( int y = 0; y < board[ x ].size(); ++y ) {
            board[ x ][ y ].draw();
        }
    }    
}