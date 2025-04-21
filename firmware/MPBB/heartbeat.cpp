/****************************************************************************
 * MPBB Heartbeat	    						                         	*
 * Steve Martin                                                            	*
 * April 21, 2025                                                            	*
 ****************************************************************************/
#include "heartbeat.h"

#define HALF_SECOND 512
#define EIGHTH_SECOND 128

void heartbeat()
{
    uint32_t time_ms;
    time_ms = millis();
    if (!(time_ms & (HALF_SECOND | EIGHTH_SECOND))) digitalWrite(HEARTBEAT_LED, HIGH);
    else if (time_ms & EIGHTH_SECOND)               digitalWrite(HEARTBEAT_LED, LOW);
}
