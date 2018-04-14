/**
 *  Fontana Francesco vr081502
 *  Laboratorio Ciberfisico 2018
 *  Informatica
 *  Università di Verona 
 */

/*
Code to get keyboard inputs without blocking the loop and without pressing enter
*
*author:https://github.com/sdipendra/ros-projects/blob/master/src/keyboard_non_blocking_input/src/keyboard_non_blocking_input_node.cpp
*
*/

#include <ros/ros.h>
#include <termios.h>
#include "homework1/Command.h"

char getch()
{
	fd_set set;
	struct timeval timeout;
	int rv;
	char buff = 0;
	int len = 1;
	int filedesc = 0;
	FD_ZERO(&set);
	FD_SET(filedesc, &set);
	
	timeout.tv_sec = 0;
	timeout.tv_usec = 1000;

	rv = select(filedesc + 1, &set, NULL, NULL, &timeout);

	struct termios old = {0};
	if (tcgetattr(filedesc, &old) < 0)
		ROS_ERROR("tcsetattr()");
	old.c_lflag &= ~ICANON;
	old.c_lflag &= ~ECHO;
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;
	if (tcsetattr(filedesc, TCSANOW, &old) < 0)
		ROS_ERROR("tcsetattr ICANON");

	if(rv == -1)
		ROS_ERROR("select");
	//else if(rv == 0)
		//ROS_INFO("no_key_pressed");
	else
		read(filedesc, &buff, len );

	old.c_lflag |= ICANON;
	old.c_lflag |= ECHO;
	if (tcsetattr(filedesc, TCSADRAIN, &old) < 0)
		ROS_ERROR ("tcsetattr ~ICANON");
	return (buff);
}

/*
* Il nodo key_input_node permette di selezionare da tastiera quale
* parte del messaggio verrà mostrata a video.
*/
int main(int argc, char **argv)
{
	ros::init(argc, argv, "key_input_node");
	ros::NodeHandle n;

	ros::Publisher keyboard_pub = n.advertise<homework1::Command>("commands", 1000);

	ros::Rate loop_rate(10);
	while (ros::ok())
	{

		homework1::Command keyboard_command;

		int c = 0;
		c=getch();
		
		if (c == 'a')
		{	
			ROS_INFO("%c", c);
			keyboard_command.command = c;

		}
		else if (c == 'n')
		{	
			ROS_INFO("%c", c);
			keyboard_command.command = c;
		}
		else if (c == 'e')
		{
			ROS_INFO("%c", c);
			keyboard_command.command = c;
		}
		else if (c == 'c')
		{	
			ROS_INFO("%c", c);
			keyboard_command.command = c;
		}	

		keyboard_pub.publish(keyboard_command);

		ros::spinOnce();

		loop_rate.sleep();
	}

	return 0;
}