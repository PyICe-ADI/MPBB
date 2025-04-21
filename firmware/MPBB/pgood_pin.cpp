/****************************************************************************
 * MPBB RST Pin                                                             *
 * Steve Martin                                                            	*
 * April 21, 2025                                                           *
 ****************************************************************************/
#include "pgood_pin.h"

/****************************************************************************
 * Get the RST pin state                                                    *
 ****************************************************************************/
void get_pgood_pin()
{
    if (pgood_pin_mailbox.inbox_status == PACKET_PRESENT)
    {
        pgood_pin_mailbox.to_id = pgood_pin_mailbox.from_id;
        pgood_pin_mailbox.outbox[0] = digitalRead(PGOODPIN);
        pgood_pin_mailbox.outbox_msg_size = PGOOD_PIN_OUTBOX_SIZE;
        pgood_pin_mailbox.inbox_status = PACKET_ABSENT;
        pgood_pin_mailbox.outbox_status = PACKET_PRESENT;
    }
}