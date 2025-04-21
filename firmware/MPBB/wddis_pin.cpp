/****************************************************************************
 * MPBB WD_DISABLE Pin                                                      *
 * Steve Martin                                                            	*
 * April 21, 2025                                                           *
 ****************************************************************************/
#include "wddis_pin.h"

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
void set_wd_dis_pin_state()
{
	if (wd_dis_pin_mailbox.inbox_status == PACKET_PRESENT)
    {        
        switch(wd_dis_pin_mailbox.inbox[COMMAND_BYTE])
        {
            case SET_STATE:
            {
                switch(wd_dis_pin_mailbox.inbox[DATA_BYTE_IN])
                {
                    case ON:    digitalWrite(WDDISB_PIN, LOW);   break; // It's inverted
                    case OFF:   digitalWrite(WDDISB_PIN, HIGH);  break; // in hardware
                }
            }break;
            case GET_STATE: get_wd_dis_pin_state(); break;
        }
        wd_dis_pin_mailbox.inbox_status = PACKET_ABSENT;
    }
}
/****************************************************************************
 * Get the pin state                                                        *
 ****************************************************************************/
void get_wd_dis_pin_state()
{
    wd_dis_pin_mailbox.to_id = wd_dis_pin_mailbox.from_id;
    wd_dis_pin_mailbox.outbox_msg_size = WDDIS_PIN_OUTBOX_SIZE;
    wd_dis_pin_mailbox.outbox[DATA_BYTE_OUT] = !digitalRead(WDDISB_PIN); // Inverted in hardware
    wd_dis_pin_mailbox.outbox_status = PACKET_PRESENT;
}