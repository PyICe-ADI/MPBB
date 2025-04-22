/****************************************************************************
 * MCUERR Pin                                                               *
 * Steve Martin                                                            	*
 * April 21, 2025                                                           *
 ****************************************************************************/
#include "mcuerr_pin.h"

#define COMMAND_BYTE    0
#define DATA_BYTE_OUT   0
#define DATA_BYTE_IN    1
#define SET_STATE       1
#define GET_STATE       2
#define OFF             0
#define ON              1

/****************************************************************************
 * Set the pin state                                                        *
 ****************************************************************************/
void process_mcuerr_pin()
{
	if (mcuerr_pin_mailbox.inbox_status == PACKET_PRESENT)
    {
        switch(mcuerr_pin_mailbox.inbox[COMMAND_BYTE])
        {
            case SET_STATE:
            {
                switch(mcuerr_pin_mailbox.inbox[DATA_BYTE_IN])
                {
                    case OFF:  digitalWrite(MCUERRB_PIN, LOW);  break; // It's inverted
                    case ON:   digitalWrite(MCUERRB_PIN, HIGH); break; // in hardware
                }
            }break;
            case GET_STATE: get_mcuerr_pin_state(); break;
        }
        mcuerr_pin_mailbox.inbox_status = PACKET_ABSENT;
    }
}
/****************************************************************************
 * Get the pin state                                                        *
 ****************************************************************************/
void get_mcuerr_pin_state()
{
    mcuerr_pin_mailbox.to_id = mcuerr_pin_mailbox.from_id;
    mcuerr_pin_mailbox.outbox_msg_size = MCUERR_PIN_OUTBOX_SIZE;
    mcuerr_pin_mailbox.outbox[DATA_BYTE_OUT] = digitalRead(MCUERRB_PIN); // Pin is inverted in hardware
    mcuerr_pin_mailbox.outbox_status = PACKET_PRESENT;
}