/****************************************************************************
 * MCUERR Pin                                                               *
 * Steve Martin                                                             *
 * April 21, 2025                                                           *
 ****************************************************************************/
#ifndef MCUERR_PIN_H
#define MCUERR_PIN_H

#include "labcomm.h"        // Gets mailbox ENUMS and types
#include "postoffice.h"     // Gets inbox and outbox sizes
#include "board.h"

void process_mcuerr_pin();
void get_mcuerr_pin_state();

#endif