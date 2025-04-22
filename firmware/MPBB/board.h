/****************************************************************************
 * MPBB Board Definition                                                    *
 * Steve Martin                                                             *
 * April 21, 2025                                                           *
 ****************************************************************************/
#ifndef BOARD_H
#define BOARD_H

// #define SDAPIN          20
// #define SCLPIN          21
#define AUX_SDA         6
#define AUX_SCL         7

// Inputs
#define PUSHBUTTON_PIN  23
#define PGOOD_PIN       17
#define FAULTB_PIN      18

// Outputs
#define PGOOD_LED       19 // D5 PB02 GREEN
#define FAULTB_LED      31 // D6 PB23 RED
#define HEARTBEAT_LED   25 // D3 PB03 ORANGE
#define ENABLEB_PIN     8
#define MCUERRB_PIN     5
#define WDDISB_PIN      2
#define TESTHOOK_PIN    41
#define REMOTE_ATH_PIN  38

#endif