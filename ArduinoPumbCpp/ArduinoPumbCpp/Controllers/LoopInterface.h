//
//  LoopInterface.h
//  ArduinoPumpCpp
//
//  Created by Andriy Zhuk on 11/3/19.
//  Copyright © 2019 azhuk. All rights reserved.
//

#ifndef LoopInterface_h
#define LoopInterface_h

class LoopInterface
{
public:
//    LoopInterface(){}
//    virtual ~LoopInterface(){}
    virtual void tick() = 0;
};

#endif /* LoopInterface_h */
