/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions
 * related to it.
 *
 * Copyright (c) 2011-2014, Purdue University ACM SIG BOTS.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Purdue University ACM SIG BOTS nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL PURDUE UNIVERSITY ACM SIG BOTS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Purdue Robotics OS contains FreeRTOS (http://www.freertos.org) whose source
 * code may be obtained from http://sourceforge.net/projects/freertos/files/ or
 * on request.
 */

#include "main.h"
#include "movement.h"
#include "hardwareSetup.h"

/*
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via the
 * Field Management System or the VEX Competition Switch in the autonomous mode.
 * If the robot is disabled or communications is lost, the autonomous task will
 * be stopped by the kernel. Re-enabling the robot will restart the task, not
 * re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX
 * Joystick. However, the autonomous function can be invoked from another task if
 * a VEX Competition Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never
 * exit. If it does so, the robot will await a switch to another mode or
 * disable/enable cycle.
 */

const int MOVE_LEFT = 900;
const int MOVE_RIGHT = 3750;
const int BACK_TO_TILE = 900;
const int HALF_BACK_TO_TILE = 3750;

void autonomous()
{
    printf("testing1");
    //if the power expander has a battery plugged in
    //or the check is overriden with a jumper clip
    if(getSensor(powerExpand) > 1000 || getSensor(powerExpandJumper))
    {
        printf("testing2");
        //if we are using puncher(s)
        if(!useRamp)
        {
            printf("testing3");
            //if potentiometer is not set to disable autonomous
            if(getSensor(tileSelect) > MOVE_RIGHT ||
               getSensor(tileSelect) < MOVE_LEFT)
            {
                printf("testing4");
                setMotor(puncher1, 127);
                printf("testing5");
                setMotor(puncher2, 127);
                printf("testing6");
            }
        }

        //if we are using the ramp.
        else
        {
            //if potentiometer is not set to disable autonomous
            if(getSensor(tileSelect) > MOVE_RIGHT ||
               getSensor(tileSelect) < MOVE_LEFT)

                //move out to avoid hitting partner
                driveMoveTo(BACKWARD, 50, RFenc, 700);

            //if we need to move left
            if(getSensor(tileSelect) < MOVE_LEFT)
                //move left
                driveMoveTo(LEFT, 65, RFenc, -600);
        
            //if we need to move right
            else if(getSensor(tileSelect) > MOVE_RIGHT)
                //move right
                driveMoveTo(RIGHT, 65, RFenc, 580);

            //if potentiometer is not set to disable autonomous
            if(getSensor(tileSelect) > MOVE_RIGHT ||
               getSensor(tileSelect) < MOVE_LEFT)
            {
                //score preloads and hopefully pyramids
                driveMoveTo(BACKWARD, 127, RFenc, 7200);

                //push any balls that are almost scored into low scoring
                driveMoveTo(RIGHT, 127, RFenc, 1100);
                driveMoveTo(LEFT, 127, RFenc, -1900);

                //if we need to go all the way back
                if(getSensor(movementSelect) < BACK_TO_TILE)
                {
                    //move so that we are in line with the starting tile
                    driveMoveTo(RIGHT, 127, RFenc, 750);

                    //go back to the starting tile
                    driveMoveTo(FORWARD, 127, RFenc, -7000);
                }

                //if we need to go halfway back to the starting tile
                else if(getSensor(movementSelect) > BACK_TO_TILE &&
                        getSensor(movementSelect) < HALF_BACK_TO_TILE)

                    //go about halfway back to the tile
                    driveMoveTo(FORWARD, 127, RFenc, -4510);
            }
        }
    }
}
