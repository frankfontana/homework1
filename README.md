# homework1

E' stato creato il package ROS "homework1" contenente 3 nodi:
- Il nodo student pubblica, 1 volta al secondo un messaggio contenente un nome, un età, e un corso di laurea.
- Il nodo key_input_node permette di selezionare da tastiera quale parte del messaggio verrà mostrata a video.
- Il nodo commands_messages_listener mostra a video la parte del messaggio selezionata.<br>
Digitando 'a' verrà stampato tutto il messaggio.<br>
Digitando 'n' verrà stampato solo il nome.<br>
Digitando 'e' verrà stampata solo l'età.<br>
Digitando 'c' verrà stampato solo il corso.<br>

Il codice sorgente per implementare il nodo publisher "key_input_node" è stato implementato seguendo
il link:<br>
https://github.com/sdipendra/ros-projects/blob/master/src/keyboard_non_blocking_input/src/keyboard_non_blocking_input_node.cpp

E' stato creato un launch file di nome "homework1.launch" in modo da semplificare l'esecuzione del codice implementato.
E' possibile lanciare i nodi con il comando: <b>"roslaunch homework1 homework1.launch"</b>

Sono stati creati 2 file .msg all'interno della cartella msg/ relativi ai topic "commands" e "messages".
Il primo file Student.msg contiene i dati relativi ad uno studente:<br>
-string name<br>
-uint8 age<br>
-string course<br>
-string text<br>
Il campo text permette di concatenare i 3 campi precendeti.

Il secondo file Command.msg contiene un campo uint8 command per gestire i caratteri letti da tastiera.<br>
-uint8 command<br>

![alt text](https://raw.githubusercontent.com/frankfontana/homework1/master/images/rosgraph.jpg)
