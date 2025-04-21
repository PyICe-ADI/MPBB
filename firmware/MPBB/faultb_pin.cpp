/****************************************************************************
 * MPBB FAULTB Pin                                                          *
 * Steve Martin                                                            	*
 * April 21, 2025                                                           *
 ****************************************************************************/
#include "faultb_pin.h"

/****************************************************************************
 * Get the RST pin state                                                    *
 ****************************************************************************/
void get_faultb_pin()
{
    if (faultb_pin_mailbox.inbox_status == PACKET_PRESENT)
    {
        faultb_pin_mailbox.to_id = faultb_pin_mailbox.from_id;
        faultb_pin_mailbox.outbox[0] = digitalRead(FAULTB_PIN);
        faultb_pin_mailbox.outbox_msg_size = FAULTB_PIN_OUTBOX_SIZE;
        faultb_pin_mailbox.inbox_status = PACKET_ABSENT;
        faultb_pin_mailbox.outbox_status = PACKET_PRESENT;
    }
}