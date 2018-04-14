# homework1

E' stato creato il package ROS "homework1" contenente 3 nodi:
- Il nodo student pubblica, 1 volta al secondo un messaggio contenente un nome, un età, e un corso di laurea.
- Il nodo key_input_node permette di selezionare da tastiera quale parte del messaggio verrà mostrata a video.
- Il nodo commands_messages_listener mostra a video la parte del messaggio selezionata.
Digitando 'a' verrà stampato tutto il messaggio.
Digitando 'n' verrà stampato solo il nome.
Digitando 'e' verrà stampata solo l'età.
Digitando 'c' verrà stampato solo il corso.

Il codice sorgente per implementare il nodo publisher "key_input_node" è stato implementato seguendo
il seguente linK: https://github.com/sdipendra/ros-projects/blob/master/src/keyboard_non_blocking_input/src/keyboard_non_blocking_input_node.cpp

![alt text](https://raw.githubusercontent.com/frankfontana/homework1/master/images/rosgraph.jpg)
