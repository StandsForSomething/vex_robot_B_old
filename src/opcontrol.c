/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions
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
 * AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL PURDUE UNIVERSITY ACM SIG BOTS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL,a EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Purdue Robotics OS contains FreeRTOS (http://www.freertos.org) whose source
 * code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

//the main header file for every file in a PROS project
#include "main.h"

/*
 * Runs the user operator control code. This function will be started in its own
 * task with the default priority and stack size whenever the robot is enabled
 * via the Field Management System or the VEX Competition Switch in the operator
 * control mode. If the robot is disabled or communications is lost, the operator
 * control task will be stopped by the kernel. Re-enabling the robot will restart
 * the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX
 * Cortex will run the operator control task. Be warned that this will also occur
 * if the VEX Cortex is tethered directly to a computer via the USB A to A cable
 * without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is
 * available and the scheduler is operational. However, proper use of delay() or
 * taskDelayUntil() is highly recommended to give other tasks (including system
 * tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop,
 * even if empty.
 */


void operatorControl()
{
    printf("opcontrol started\n\r");
    //used in a switch for different control modes.
    typedef enum DriveMode {FRONT, BACK}DriveMode;
    DriveMode DriverMode = FRONT;
    bool clawClosed = false;

    //in the case that the power expander isn't plugged in don't continue until
    //it's plugged in or overriden by placeing a jumper in digital pin 2.
    //this makes sure the robot can't move unless the issue is fixed becuase once
    //the robot moves it can't legally be fixed.  The option of using a jumper to
    //continue is incase the issue can't be fixed.
    //while(getSensor(powerExpand) < 1000 && getSensor(powerExpandJumper)){delay(20);}

    //control loop
    while (1)
    {
        printf("test\n\r");
        /////////
        //Drive//
        //////////////////////////////////////////////////////////////////////
        //I debounce buttons in button group 8.  It has occured to be that  //
        //there probally is no reason for debounce.  I have no idea why they//
        //are debounced so I will probally remove it later when I can make  //
        //sure it isn't needed.                                             //
        //////////////////////////////////////////////////////////////////////

        //if button 8U is pressed and has been debounced
        if (C1_8U)
        {
            DriverMode = FRONT;        //Change mode to FRONT
        }

        //if button 8D is pressed and has been debounced
        if(C1_8D)
        {
            DriverMode = BACK;         //Change mode to BACK
        }
        //deadzones for each of the joysticks to prevent motor whine
        if (abs(C1LY) > 15 || abs(C1LX) >15 || abs(C1RX) > 15)
        {
            //switch to change driver configuration
            switch (DriverMode)
            {

            case FRONT: //First Mode (8U)
                //pressing the left joystick forward
                //will move the robot forward
                setMotor(LFDrive,  C1LY + C1LX);
                setMotor(LBDriveO,  C1LY + C1LX);
                setMotor(LBDriveI,  C1LY + C1LX);
                setMotor(RFDrive,  C1LY - C1LX);
                setMotor(RBDriveO,  C1LY - C1LX);
                setMotor(RBDriveI,  C1LY - C1LX);
                break;
            case BACK: // Fourth Mode (8D)
                //pressing the left joystick forward
                //will move the robot backward
                setMotor(LFDrive, -C1LY + C1LX);
                setMotor(LBDriveO, -C1LY + C1LX);
                setMotor(LBDriveI, -C1LY + C1LX);
                setMotor(RFDrive, -C1LY - C1LX);
                setMotor(RBDriveO, -C1LY - C1LX);
                setMotor(RBDriveI, -C1LY - C1LX);
                break;
            }
        }

        //if joysticks are within deadzones set all drive motors to 0
        else
        {
            setMotor(LFDrive, 0);
            setMotor(LBDriveO, 0);
            setMotor(LBDriveI, 0);
            setMotor(RFDrive, 0);
            setMotor(RBDriveO, 0);
            setMotor(RBDriveI, 0);
        }

        ////////
        //lift//
        ////////
        if(abs(C1RY) > 15)
        {
            setMotor(liftLeft, -C1RY);
            setMotor(liftRight1, -C1RY);
            setMotor(liftRight2, -C1RY);
        }

        else
        {
            setMotor(liftLeft, 0);
            setMotor(liftRight1, 0);
            setMotor(liftRight2, 0);
        }

        ////////
        //claw//
        ////////
        if(C1_5D)
        {
            setMotor(claw, 127);
            clawClosed = true;
        }

        else if(C1_5U)
        {
            setMotor(claw, -127);
            clawClosed = false;
        }

        else if(clawClosed)
        {
            setMotor(claw, 25);
        }

        else
        {
            setMotor(claw, 0);
        }

        //motors can only be updated every 20 milliseconds
        delay(20);
    }
}
