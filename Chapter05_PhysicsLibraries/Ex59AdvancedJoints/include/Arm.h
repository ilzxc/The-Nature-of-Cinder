//
//  Arm.h
//  Ex59AdvancedJoints
//
//  Created by Ilya Rostovtsev on 8/14/13.
//
//

#ifndef Ex59AdvancedJoints_Arm_h
#define Ex59AdvancedJoints_Arm_h

#include "Box2D/Box2D.h"
#include "ArmComponent.h"

class Arm {
public:
    Arm( b2World *world );
    ~Arm();
    void update( const Vec2f &mouse );
    void draw() const;
    
private:
    std::vector< std::unique_ptr< ArmComponent > > FullArm;
};

#endif
