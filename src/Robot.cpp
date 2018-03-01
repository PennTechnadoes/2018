/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Drive/DifferentialDrive.h>
#include <IterativeRobot.h>
#include <Joystick.h>
#include <Spark.h>
#include <WPILib.h>

/**
 * This is a demo program showing the use of the DifferentialDrive class.
 * Runs the motors with arcade steering.
 */
class Robot : public IterativeRobot {

	frc::Spark leftone{2};
	frc::Spark lefttwo{3};

	SpeedControllerGroup leftwheels{leftone,lefttwo};

	frc::Spark rightone{0};
	frc::Spark righttwo{1};
	SpeedControllerGroup rightwheels{rightone,righttwo};
Joystick Operator{1};
	frc::Joystick Driver{0};
	Spark Roller1{8};
	Spark Roller2{9};
SpeedControllerGroup Rollers{Roller1,Roller2};

	JoystickButton OpRB{&Operator,6};

	JoystickButton OpLB{&Operator,5};



	JoystickButton OpLs{&Operator,1};




	frc::DifferentialDrive Tornadoes{leftwheels, rightwheels};

	Spark LeftLauncher{6};
	Spark RightLauncher{7};
	SpeedControllerGroup Launchers{LeftLauncher,RightLauncher};


	Spark LeftIntake{4};
	Spark RightIntake{5};

	int LX=0;
	int LY=1;
	int LT=2;
	int RT=3;
	int RX=4;
	int RY=5;


	SpeedControllerGroup Intake{LeftIntake,RightIntake};




public:
	void RobotInit(){
		RightIntake.SetInverted(true);
	//	leftwheels.SetInverted(true);
//		rightwheels.SetInverted(true);
	//	CameraServer::GetInstance()->StartAutomaticCapture(0);


	}

	void AutonomousInit(){
		for(int i = 1000; i>0; i-=1)//another example
		{
		Tornadoes.TankDrive(.8,.7);
		Wait(5.0/1000);

		}

		Tornadoes.TankDrive(0,0);


	}
// insert lenny face here

	void TeleopPeriodic() {

		// drive with arcade style
		double IntakeSpeed=Operator.GetRawAxis(RT)-Operator.GetRawAxis(LT);
		double RollerSpeed=Operator.GetRawAxis(LY);
		if(OpRB.Get()) {Launchers.Set(1);}
		Rollers.Set(RollerSpeed);
		double newmotorspeed = Driver.GetRawAxis(RY) / 2;
		Tornadoes.TankDrive(-Driver.GetRawAxis(LY), -Driver.GetRawAxis(RY));

	}

};

START_ROBOT_CLASS(Robot)
