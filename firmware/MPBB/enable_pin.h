/****************************************************************************
 * MPBB ENABLE Pin                                                          *
 * Steve Martin                                                             *
 * April 21, 2025                                                           *
 ****************************************************************************/
#ifndef ENABLE_PIN_H
#define ENABLE_PIN_H

#include "labcomm.h"        // Gets mailbox ENUMS and types
#include "postoffice.h"     // Gets inbox and outbox sizes
#include "board.h"

void process_enable_pin();
void get_enable_pin_state();

#endif