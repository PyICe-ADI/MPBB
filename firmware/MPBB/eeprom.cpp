/****************************************************************************
 * MPBB EEPROM                                                              *
 * Steve Martin                                                             *
 * April 21, 2025                                                           *
 ****************************************************************************/
#include "eeprom.h"

/****************************************************************************
 * Set and Get EEPROM Data                                                  *
 ****************************************************************************/
void eeprom_services()
{
    SMBUS_reply reply={.status=0, .lo_byte=0, .hi_byte=0};
    if (eeprom_mailbox.inbox_status == PACKET_PRESENT)
    {
        switch(eeprom_mailbox.inbox[TRANSACTION_TYPE])
        {
            case SMBUS_WRITE_REGISTER:
                 reply = softport_SMBUS_write_register( eeprom_mailbox.inbox[ADDR7],
                                                        eeprom_mailbox.inbox[COMMAND_CODE],
                                                        eeprom_mailbox.inbox[DATA_SIZE],
                                                        eeprom_mailbox.inbox[USE_PEC],
                                                        eeprom_mailbox.inbox[START_OF_SMBUS_DATA_IN],
                                                        eeprom_mailbox.inbox[START_OF_SMBUS_DATA_IN + 1]);
                 eeprom_mailbox.outbox[START_OF_DATA_OUT] = reply.status;
                 eeprom_mailbox.outbox_msg_size = 1;
                 eeprom_mailbox.outbox_status = PACKET_PRESENT;
                 break;
            case SMBUS_RECEIVE_BYTE:
                 eeprom_mailbox.to_id = eeprom_mailbox.from_id;
                 eeprom_mailbox.outbox_msg_size = EEPROM_OUTBOX_SIZE;
                 reply = softport_SMBUS_receive_byte(   eeprom_mailbox.inbox[ADDR7],
                                                        eeprom_mailbox.inbox[USE_PEC]);
                 eeprom_mailbox.outbox[START_OF_DATA_OUT] = reply.status;
                 eeprom_mailbox.outbox[START_OF_DATA_OUT + 1] = reply.lo_byte;
                 eeprom_mailbox.outbox_msg_size = 2;
                 eeprom_mailbox.outbox_status = PACKET_PRESENT;
                 break;
        }
        eeprom_mailbox.inbox_status = PACKET_ABSENT;
    }
}