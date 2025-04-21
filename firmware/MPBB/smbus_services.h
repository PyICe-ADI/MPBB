/****************************************************************************
 * MPBB SMBus Services                                                      *
 * Steve Martin                                                             *
 * April 21, 2025                                                           *
 ****************************************************************************/
#ifndef SMBUS_SERVICES_H
#define SMBUS_SERVICES_H

#include "postoffice.h"         // Gets Mailbox
#include "smbus_comnd_struct.h" // Defines SMBus payload menu structure
#include "smbus.h"

void service_smbus();
void set_register_list();
void read_register_list();
void enable_stream_mode(); 
void disable_stream_mode();
void write_register_list();
void smbus_read_register();
void smbus_write_register();
void set_reg_list_and_stream();
void set_reg_list_and_read_list();

#endif