/****************************************************************************
 * MPBB Temperature Sensor                                                  *
 * Steve Martin                                                             *
 * April 21, 2025                                                           *
 ****************************************************************************/
#include "temp_sensor.h"

/****************************************************************************
 * Set the pin state                                                        *
 ****************************************************************************/
void get_temperature_sensor()
{
    SMBUS_reply reply={.status=0, .lo_byte=0, .hi_byte=0};
    if (tmp117_mailbox.inbox_status == PACKET_PRESENT)
    {
        switch(tmp117_mailbox.inbox[TRANSACTION_TYPE])
        {
            case SMBUS_WRITE_REGISTER:
                reply = softport_SMBUS_write_register(  tmp117_mailbox.inbox[ADDR7],
                                                        tmp117_mailbox.inbox[COMMAND_CODE],
                                                        tmp117_mailbox.inbox[USE_PEC],
                                                        tmp117_mailbox.inbox[DATA_SIZE],
                                                        tmp117_mailbox.inbox[START_OF_SMBUS_DATA_IN + 0],
                                                        tmp117_mailbox.inbox[START_OF_SMBUS_DATA_IN + 1]);
                tmp117_mailbox.outbox[START_OF_DATA_OUT] = reply.status;
                tmp117_mailbox.outbox_msg_size = 1;
                tmp117_mailbox.outbox_status = PACKET_PRESENT;
                break;
            case SMBUS_READ_REGISTER:
                reply = softport_SMBUS_read_register(   tmp117_mailbox.inbox[ADDR7],
                                                        tmp117_mailbox.inbox[COMMAND_CODE],
                                                        tmp117_mailbox.inbox[USE_PEC],
                                                        tmp117_mailbox.inbox[DATA_SIZE]);
                tmp117_mailbox.to_id = tmp117_mailbox.from_id;
                tmp117_mailbox.outbox_msg_size = TMP117_OUTBOX_SIZE;
                tmp117_mailbox.outbox[START_OF_DATA_OUT + 0] = reply.status;
                tmp117_mailbox.outbox[START_OF_DATA_OUT + 1] = reply.lo_byte;   // TMP117 is *NOT* SMBus Endianness
                tmp117_mailbox.outbox[START_OF_DATA_OUT + 2] = reply.hi_byte;   // Swapping is done in the PyICe driver however
                tmp117_mailbox.outbox_msg_size = 3;
                tmp117_mailbox.outbox_status = PACKET_PRESENT;
                break;
        }
        tmp117_mailbox.inbox_status = PACKET_ABSENT;
    }
}