/*
* Brief - Exposes a function that is used to get all the necessary data,
*         that needs to be tramsmitted, from the user
*
* Author - Deekshith Reddy Patil, patil.deekshithreddy@colorado.edu
*/

#include <stdio.h> 

#ifndef __USER_INTERFACE_H__
#define __USER_INTERFACE_H__


/*
* Brief - This function gets the data from that is to be transmitted over the network to the Rpi
*       - The frame is as follows, "<load_number>, <mode> , <set / reset> , <duration / instant>;"
*       - The data obtained from the user is placed in @param transmit_buffer
*/
void get_user_data(char *transmit_buffer);

#endif