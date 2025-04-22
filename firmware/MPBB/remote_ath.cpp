/****************************************************************************
 * Remote ATH Control Pin                                                   *
 * Steve Martin                                                            	*
 * April 21, 2025                                                           *
 ****************************************************************************/
#include "remote_ath.h"

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
void process_remote_ath_pin()
{
	if (rem_ath_pin_mailbox.inbox_status == PACKET_PRESENT)
    {
        switch(rem_ath_pin_mailbox.inbox[COMMAND_BYTE])
        {
            case SET_STATE:
            {
                switch(rem_ath_pin_mailbox.inbox[DATA_BYTE_IN])
                {
                    case OFF:  digitalWrite(REMOTE_ATH_PIN, LOW);  break; 
                    case ON:   digitalWrite(REMOTE_ATH_PIN, HIGH); break; 
                }
            }break;
            case GET_STATE: get_remote_ath_pin_state(); break;
        }
        rem_ath_pin_mailbox.inbox_status = PACKET_ABSENT;
    }
}
/****************************************************************************
 * Get the pin state                                                        *
 ****************************************************************************/
void get_remote_ath_pin_state()
{
    rem_ath_pin_mailbox.to_id = rem_ath_pin_mailbox.from_id;
    rem_ath_pin_mailbox.outbox_msg_size = REM_ATH_PIN_OUTBOX_SIZE;
    rem_ath_pin_mailbox.outbox[DATA_BYTE_OUT] = digitalRead(REMOTE_ATH_PIN);
    rem_ath_pin_mailbox.outbox_status = PACKET_PRESENT;
}