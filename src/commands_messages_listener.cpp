/**
 *  Fontana Francesco vr081502
 *  Laboratorio Ciberfisico 2018
 *  Informatica
 *	Università di Verona
 */

// %Tag(FULLTEXT)%
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "homework1/Student.h"
#include "homework1/Command.h"

char carattereLetto; // carattere letto da tastiera

// setta il carattere letto da tastiera
void setChar(char command)
{

    carattereLetto = command;
}  

// ritorna il carattere letto da tastiera
char getChar()
{

  return carattereLetto;
}

/**
 * 
 */
// %Tag(CALLBACK)%
void messageCallback(const homework1::Student::ConstPtr& text)
{
  //ROS_INFO("I heard: [%s]", text->name.c_str());

  char c;

  c = getChar();

  if (c == 'a')
  {
    
    ROS_INFO("Print all: [%s]", text->text.c_str());

    setChar('\0');
  
  }
  else if (c == 'n')
  {

    ROS_INFO("Print name: [%s]", text->name.c_str());

    setChar('\0');

  }
  else if (c == 'e')
  {
    
    ROS_INFO("Print age: [%i]", (int) text->age);

    setChar('\0');

  }
  else if (c == 'c')
  { 

    ROS_INFO("Print course: [%s]", text->course.c_str());

    setChar('\0');
  }


}
// %EndTag(CALLBACK)%

// %Tag(CALLBACK)%
void commandCallback(const homework1::Command::ConstPtr& character)
{
  //ROS_INFO("I heard: [%c]", character->command);

  if (character->command == 'a')
  {
        
    setChar('a'); 
  }
  else if (character->command == 'n')
  {

    setChar('n');
  }
  else if (character->command == 'e')
  {

    setChar('e');
  }
  else if (character->command == 'c')
  {
    setChar('c');
  }
}
// %EndTag(CALLBACK)%

/*
* Il nodo commands_messages_listener mostra a video la parte del messaggio selezionata
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
  ros::init(argc, argv, "commands_messages_listener");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;

  /**
   * The subscribe() call is how you tell ROS that you want to receive messages
   * on a given topic.  This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing.  Messages are passed to a callback function, here
   * called chatterCallback.  subscribe() returns a Subscriber object that you
   * must hold on to until you want to unsubscribe.  When all copies of the Subscriber
   * object go out of scope, this callback will automatically be unsubscribed from
   * this topic.
   *
   * The second parameter to the subscribe() function is the size of the message
   * queue.  If messages are arriving faster than they are being processed, this
   * is the number of messages that will be buffered up before beginning to throw
   * away the oldest ones.
   */
// %Tag(SUBSCRIBER)%
  ros::Subscriber sub1 = n.subscribe("messages", 1000, messageCallback);
  ros::Subscriber sub2 = n.subscribe("commands", 1000, commandCallback);

// %EndTag(SUBSCRIBER)%

  /**
   * ros::spin() will enter a loop, pumping callbacks.  With this version, all
   * callbacks will be called from within this thread (the main one).  ros::spin()
   * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   */
// %Tag(SPIN)%
  ros::spin();
// %EndTag(SPIN)%

  return 0;
}
// %EndTag(FULLTEXT)%
