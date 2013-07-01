//
//  OSCInterface.h
//  CinderOSCDemo
//
//  Created by Ilya Rostovtsev on 5/14/13.
//
//

#ifndef CinderOSCDemo_OSCInterface_h
#define CinderOSCDemo_OSCInterface_h

#include <vector>
#include <string>
#include "cinder/System.h"
#include "OscListener.h"
#include "OscSender.h"
#include "OscBundle.h"

class OSCInterface {

public:
    OSCInterface();
    
    void setup(int port);
    void update();
    void unfoldAddresses(const std::string address);
    void appendMessage(const float       argument,  const std::string address);
    void appendMessage(const int         argument,  const std::string address);
    void appendMessage(const std::string argument,  const std::string address);
    void sendMessage();
    void packageBundle(std::string address);
    
    
    // OSC-definitions:
    float rotation;
    const std::string rotationAddress = "/square/rotation";
    
    cinder::Vec3f color;
    const std::string colorAddress = "/square/color";
    
    
    int port;
    std::string host;
    cinder::osc::Listener   listener;
    cinder::osc::Sender     sender;
    cinder::osc::Message    message;
    cinder::osc::Bundle     bundle;
};

#endif
