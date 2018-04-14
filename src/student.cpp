/**
 *  Fontana Francesco vr081502
 *  Laboratorio Ciberfisico 2018
 *  Informatica
 *  Università di Verona
 */
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "homework1/Student.h"
#include <stdio.h>
#include <sstream>
#include <string>
#include <iostream>

/**
 * Il nodo student pubblica, 1 volta al secondo, un messaggio
 * contenente un nome, un età, e un corso di laurea.
 *
 */
int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "student");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;

  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing. After this advertise() call is made, the master
   * node will notify anyone who is trying to subscribe to this topic name,
   * and they will in turn negotiate a peer-to-peer connection with this
   * node.  advertise() returns a Publisher object which allows you to
   * publish messages on that topic through a call to publish().  Once
   * all copies of the returned Publisher object are destroyed, the topic
   * will be automatically unadvertised.
   *
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages.  If messages are published more quickly
   * than we can send them, the number here specifies how many messages to
   * buffer up before throwing some away.
   */
  ros::Publisher student_pub = n.advertise<homework1::Student>("messages", 1000);

  // create a rate
  ros::Rate rate(1); // 1 message per second

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
  int count = 0;
  while (ros::ok())
  {
    /**
     * 
     */

    homework1::Student student_info;

    student_info.name = "Francesco";
    student_info.age = (uint8_t) 29;
    student_info.course = "Informatica";

    std::stringstream ss;
    
    ss << student_info.name + " " << (int) student_info.age << " " + student_info.course + " " << count;

    student_info.text = ss.str();

    ROS_INFO("%s", student_info.text.c_str());

    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
    student_pub.publish(student_info);

    ros::spinOnce();

    rate.sleep();
    ++count;
  }


  return 0;
}
