/****************************************************************************
 * MPBB ENABLE Pin                                                          *
 * Steve Martin                                                             *
 * April 21, 2025                                                           *
 ****************************************************************************/
#ifndef ENABLE_PIN
#define ENABLE_PIN

#include "labcomm.h"        // Gets mailbox ENUMS and types
#include "postoffice.h"     // Gets inbox and outbox sizes
#include "board.h"

void set_enable_pin_state();
void get_enable_pin_state();

#endif