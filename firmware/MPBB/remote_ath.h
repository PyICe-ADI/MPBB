/****************************************************************************
 * Remote ATH Control Pin                                                   *
 * Steve Martin                                                             *
 * April 21, 2025                                                           *
 ****************************************************************************/
#ifndef REMOTE_ATH_PIN_H
#define REMOTE_ATH_PIN_H

#include "labcomm.h"        // Gets mailbox ENUMS and types
#include "postoffice.h"     // Gets inbox and outbox sizes
#include "board.h"

void process_remote_ath_pin();
void get_remote_ath_pin_state();

#endif