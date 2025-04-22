/****************************************************************************
 * MPBB Post Office                                                         *
 * Steve Martin                                                             *
 * April 21, 2025                                                           *
 ****************************************************************************/
#ifndef POSTOFFICE_H
#define POSTOFFICE_H

#include "labcomm.h"                // Gets incoming_packet and MAX_BUFFER_SIZE_MESSAGE_SIZE
#include "idstring.h"               // Gets IDENTIFICATION string
#include "smbus_comnd_struct.h"     // Gets start of SMBus register as proxy for command size.

/****************************************************************************
 * Mail Box Addresses                                                       *
 ****************************************************************************/
#define PyICe_GUI                   1
#define ENABLE_PIN_ADDRESS          2
#define PGOOD_PIN_ADDRESS           3
#define WD_DIS_PIN_ADDRESS          4
#define SMBUS_SERVICES_ADDRESS      5
#define IDENTIFY_ADDRESS            6
#define WATCHDOG_ADDRESS            7
#define EEPROM_ADDRESS              8
#define TMP117_ADDRESS              9
#define FAULTB_PIN_ADDRESS          10
#define MCUERR_PIN_ADDRESS          11

/****************************************************************************
 * Mail Box Sizes                                                           *
 ****************************************************************************/
#define LABCOMM_INBOX_SIZE          0
#define LABCOMM_OUTBOX_SIZE         MAX_BUFFER_SIZE_MESSAGE_SIZE

#define ID_INBOX_SIZE               1 + IDENTIFY_PAYLOAD_SIZE
#define ID_OUTBOX_SIZE              IDENTIFY_PAYLOAD_SIZE

#define SMBUS_INBOX_SIZE            START_OF_SMBUS_DATA_IN + 3 * 256    // Write list will have: [ADDR|DATA|ADDR|DATA....] where size(data) can be 16
#define SMBUS_OUTBOX_SIZE           3 * 256                             // Supports read word plus 1 status byte per read word

#define WDDIS_PIN_INBOX_SIZE        2
#define WDDIS_PIN_OUTBOX_SIZE       1

#define ENABLE_PIN_INBOX_SIZE       2
#define ENABLE_PIN_OUTBOX_SIZE      1

#define MCUERR_PIN_INBOX_SIZE       2
#define MCUERR_PIN_OUTBOX_SIZE      1

#define PGOOD_PIN_INBOX_SIZE        0
#define PGOOD_PIN_OUTBOX_SIZE       1

#define FAULTB_PIN_INBOX_SIZE       0
#define FAULTB_PIN_OUTBOX_SIZE      1

#define WATCHDOG_INBOX_SIZE         5
#define WATCHDOG_OUTBOX_SIZE        4

#define EEPROM_INBOX_SIZE           START_OF_SMBUS_DATA_IN + 2 // Must support Write Word
#define EEPROM_OUTBOX_SIZE          1 + 1 // + 1 byte for status

#define TMP117_INBOX_SIZE           START_OF_SMBUS_DATA_IN + 2 // Must support Write Word
#define TMP117_OUTBOX_SIZE          2 + 1 // + 1 byte for status

/****************************************************************************
 * Mailbox Externs for the clients to find                                  *
 ****************************************************************************/
extern Mailbox<ID_INBOX_SIZE,           ID_OUTBOX_SIZE>             identify_mailbox;
extern Mailbox<SMBUS_INBOX_SIZE,        SMBUS_OUTBOX_SIZE>          smbus_services_mailbox;
extern Mailbox<WDDIS_PIN_INBOX_SIZE,    WDDIS_PIN_OUTBOX_SIZE>      wd_dis_pin_mailbox;
extern Mailbox<ENABLE_PIN_INBOX_SIZE,   ENABLE_PIN_OUTBOX_SIZE>     enable_pin_mailbox;
extern Mailbox<MCUERR_PIN_INBOX_SIZE,   MCUERR_PIN_OUTBOX_SIZE>     mcuerr_pin_mailbox;
extern Mailbox<PGOOD_PIN_INBOX_SIZE,    PGOOD_PIN_OUTBOX_SIZE>      pgood_pin_mailbox;
extern Mailbox<FAULTB_PIN_INBOX_SIZE,   FAULTB_PIN_OUTBOX_SIZE>     faultb_pin_mailbox;
extern Mailbox<WATCHDOG_INBOX_SIZE,     WATCHDOG_OUTBOX_SIZE>       watchdog_mailbox;
extern Mailbox<EEPROM_INBOX_SIZE,       EEPROM_OUTBOX_SIZE>         eeprom_mailbox;
extern Mailbox<TMP117_INBOX_SIZE,       TMP117_OUTBOX_SIZE>         tmp117_mailbox;

void process_mail();

#endif