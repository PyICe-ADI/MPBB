/****************************************************************************
 * MPBB LEDs                                                                *
 * Steve Martin                                                            	*
 * April 21, 2025                                                           *
 ****************************************************************************/
#include "set_leds.h"

void set_leds()
{
    digitalWrite(PGOOD_LED, digitalRead(PGOOD_PIN));
    digitalWrite(FAULTB_LED, !digitalRead(FAULTB_PIN));
}