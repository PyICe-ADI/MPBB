/****************************************************************************
 * MPBB Identify Onseself                                                   *
 * Steve Martin                                                             *
 * April 21, 2025                                                           *
 ****************************************************************************/
#ifndef IDENTIFY_B
#define IDENTIFY_B

#include "postoffice.h"  // Gets Mailbox
#include "idstring.h"    // Gets Identify message and sizes

void identify();
void send_identity();
void write_scratchpad();
void read_scratchpad();
void get_serialnum();

#endif