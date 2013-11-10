//
//  OSCInterface.cpp
//  CinderOSCDemo
//
//  Created by Ilya Rostovtsev on 5/14/13.
//
//

#include "OSCInterface.h"


OSCInterface::OSCInterface() {
    port = 2222;
}


void OSCInterface::setup(int aPort) {
    port = aPort;
    listener.setup(aPort);
    
    host = cinder::System::getIpAddress();
    std::cout << "host is " << host << std::endl;
    sender.setup( host, port + 1, true );
}


void OSCInterface::update()
{
    while( listener.hasWaitingMessages() ) {
        cinder::osc::Message message;
		listener.getNextMessage( &message );
        
        std::vector< std::string > addressVector;

        
        if( message.getAddress() == rotationAddress ) {
            rotation = message.getArgAsFloat( 0 );
        }
        
        if ( message.getAddress() == colorAddress ) {
            color.set( message.getArgAsInt32( 0 ), message.getArgAsInt32( 1 ), message.getArgAsInt32( 2 ) );
            color.normalize();
        }
        
        /*
		cinder::app::console() << "New message received" << std::endl;
		cinder::app::console() << "Address: " << message.getAddress() << std::endl;
		cinder::app::console() << "Num Arg: " << message.getNumArgs() << std::endl;
		for (int i = 0; i < message.getNumArgs(); i++) {
			cinder::app::console() << "-- Argument " << i << std::endl;
			cinder::app::console() << "---- type: " << message.getArgTypeName(i) << std::endl;
			if( message.getArgType(i) == cinder::osc::TYPE_INT32 ) {
				try {
					cinder::app::console() << "------ value: " << message.getArgAsInt32(i) << std::endl;
				}
				catch (...) {
					cinder::app::console() << "Exception reading argument as int32" << std::endl;
				}
			}
			else if( message.getArgType(i) == cinder::osc::TYPE_FLOAT ) {
				try {
					cinder::app::console() << "------ value: " << message.getArgAsFloat(i) << std::endl;
				}
				catch (...) {
					cinder::app::console() << "Exception reading argument as float" << std::endl;
				}
			}
			else if( message.getArgType(i) == cinder::osc::TYPE_STRING) {
				try {
					cinder::app::console() << "------ value: " << message.getArgAsString(i).c_str() << std::endl;
				}
				catch (...) {
					cinder::app::console() << "Exception reading argument as string" << std::endl;
				}
			}
		}
        
        if ( message.getNumArgs() != 0 && message.getArgType( 0 ) == cinder::osc::TYPE_FLOAT ) {
            // positionX = message.getArgAsFloat(0);
        }
         */
	}
}

void OSCInterface::unfoldAddresses(const std::string address) {
    unsigned lastSlash = address.find('/');
    unsigned nextSlash;
    while (lastSlash < address.length()) {
        nextSlash = address.find('/', lastSlash + 1);
        // result.push_back( address.substr( lastSlash + 1, nextSlash - 1 ) );
        cinder::app::console() << address.substr(lastSlash + 1, nextSlash - 1) << std::endl;
        cinder::app::console() << lastSlash + 1 << "to" << nextSlash - 1 << std::endl;
        lastSlash = nextSlash;
    }
}


void OSCInterface::sendMessage() {
    sender.sendBundle( bundle );
    bundle.clear();
}

void OSCInterface::appendMessage(const float argument, const std::string address) {
    message.addFloatArg(argument);
    packageBundle( address );
}

void OSCInterface::appendMessage(const int argument, const std::string address) {
    message.addIntArg(argument);
    packageBundle( address );
}

void OSCInterface::appendMessage(const std::string argument, const std::string address) {
    message.addStringArg(argument);
    packageBundle(address);
}

void OSCInterface::packageBundle( const std::string address ) {
    message.setAddress( address );
    // message.setRemoteEndpoint( host, port );
    try {
        bundle.addMessage( message );
        message.clear();
    } catch (...) { cinder::app::console() << "Can not add message to the bundle" << std::endl; }
}



