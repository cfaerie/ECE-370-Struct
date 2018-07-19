# ECE-370-Struct
Assignment 1 from ECE 370 course. Utilization of struct in C/C++.
The original code was for Assignment 1 for my ECE 370 course. 
I plan to make some improvements to my original code.

The assignment details were as follows:
---------------------
In this program, you are required to read in from a text file a list of persons, 
display their information, add new persons, and do a search for certain persons. 
The information of each person consists of:
 
ID (int)
Last_Name,First_Name (25 chars, max)
Address (60 chars, max)
 
Your program will open a file a1.txt and read one person’s info at a time, 
and you may assume the entries in the file are all in correct forms.
 
Each person’s information is collected, in sequence, as ID, name, address.
 You can assume the maximum number of people in a1.txt is 20
 
Read from a1.txt the information. Each person should take one structure. 
The structure should be defined as to hold name, ID, and address.
 
Your program prints the information of all people according the ID numbers in ascending order. 
The information (ID, name, address) should be identical to the information your program read from txt 
(see sample a1.txt as in the same folder of this assignment; you need to follow the same formatting as defined in a1.txt)
 
Your program then asks the user if there is additional person to add. 
If so, the fields of information on this new person are the same format as in a1.txt,
in sequence of ID, name, address, and your program asks the user to enter one entry at a time. 
Your program should continue to ask if additional person is to be added, and the user decides whether or not to add a new one.
 
Your program asks the user to search for a person by last name. 
The user will enter the name and your program should print out the information: 
ID, name, address, in sequence and one line per field (e.g. name takes one line).   
Your program should continuously ask the user if to search a new person, and stop only if the user chooses so.   
If there are two or more people with identical last name, each of them should be listed. 
Your program prints out the information immediately after the person is found.
 
Your program should have a function to print out all people who are “searched and found”, 
in the order of first searched and first printed. The standard printed (on screen) information consists: 
ID, name, address, in sequence and one line per field.  
