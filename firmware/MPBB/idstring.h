/****************************************************************************
 * MPBB ID String                                                           *
 * Steve Martin                                                             *
 * April 21, 2025                                                           *
 ****************************************************************************/
#ifndef IDSTRING_H
#define IDSTRING_H
#include <avr/pgmspace.h>

const PROGMEM char IDENTIFICATION[] = "MPBB Morpheus Demo Board REV: 0.0";

#define SCRATCHPAD_SIZE         255
#define ID_STRING_MESSAGE_SIZE  sizeof(IDENTIFICATION) - 1 // Omit the string's null character
#define IDENTIFY_PAYLOAD_SIZE   (SCRATCHPAD_SIZE >= ID_STRING_MESSAGE_SIZE) ? SCRATCHPAD_SIZE : ID_STRING_MESSAGE_SIZE

#endif 