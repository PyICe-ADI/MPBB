/****************************************************************************
 * MPBB Soft I²C port                                                       *
 * Steve Martin                                                             *
 * April 21, 2025                                                           *
 ****************************************************************************/
#ifndef SOFTPORT_B
#define SOFTPORT_B

#include <SoftWire.h>
#include "board.h"
#include "smbus.h"  // Gets the return data structure

void setup_softport();
SMBUS_reply softport_SMBUS_write_register(uint8_t address, uint8_t command_code, bool use_pec, uint8_t data_size, uint8_t lo_byte, uint8_t hi_byte);
SMBUS_reply softport_SMBUS_read_register(uint8_t address, uint8_t command_code, bool use_pec, uint8_t data_size);
SMBUS_reply softport_SMBUS_receive_byte(uint8_t address, bool use_pec);

#endif