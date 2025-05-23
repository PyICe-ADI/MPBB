/****************************************************************************
 * MPBB Post Office                                                         *
 * Steve Martin                                                             *
 * April 21, 2025                                                           *
 ****************************************************************************/
#include "postoffice.h"

/****************************************************************************
 * Create Mailboxes                                                         *
 ****************************************************************************/
Mailbox<ID_INBOX_SIZE, ID_OUTBOX_SIZE>                  identify_mailbox        = {.my_id=IDENTIFY_ADDRESS,         .to_id=0, .from_id=0, .inbox_msg_size=0, .outbox_msg_size=0, .inbox_status=PACKET_ABSENT, .outbox_status=PACKET_ABSENT, .inbox_overflow=false, .inbox={0}, .outbox={0}};
Mailbox<SMBUS_INBOX_SIZE, SMBUS_OUTBOX_SIZE>            smbus_services_mailbox  = {.my_id=SMBUS_SERVICES_ADDRESS,   .to_id=0, .from_id=0, .inbox_msg_size=0, .outbox_msg_size=0, .inbox_status=PACKET_ABSENT, .outbox_status=PACKET_ABSENT, .inbox_overflow=false, .inbox={0}, .outbox={0}};
Mailbox<WDDIS_PIN_INBOX_SIZE, WDDIS_PIN_OUTBOX_SIZE>    wd_dis_pin_mailbox      = {.my_id=WD_DIS_PIN_ADDRESS,       .to_id=0, .from_id=0, .inbox_msg_size=0, .outbox_msg_size=0, .inbox_status=PACKET_ABSENT, .outbox_status=PACKET_ABSENT, .inbox_overflow=false, .inbox={0}, .outbox={0}};
Mailbox<ENABLE_PIN_INBOX_SIZE, ENABLE_PIN_OUTBOX_SIZE>  enable_pin_mailbox      = {.my_id=ENABLE_PIN_ADDRESS,       .to_id=0, .from_id=0, .inbox_msg_size=0, .outbox_msg_size=0, .inbox_status=PACKET_ABSENT, .outbox_status=PACKET_ABSENT, .inbox_overflow=false, .inbox={0}, .outbox={0}};
Mailbox<MCUERR_PIN_INBOX_SIZE, MCUERR_PIN_OUTBOX_SIZE>  mcuerr_pin_mailbox      = {.my_id=MCUERR_PIN_ADDRESS,       .to_id=0, .from_id=0, .inbox_msg_size=0, .outbox_msg_size=0, .inbox_status=PACKET_ABSENT, .outbox_status=PACKET_ABSENT, .inbox_overflow=false, .inbox={0}, .outbox={0}};
Mailbox<REM_ATH_PIN_INBOX_SIZE, REM_ATH_PIN_OUTBOX_SIZE>rem_ath_pin_mailbox     = {.my_id=REM_ATH_PIN_ADDRESS,      .to_id=0, .from_id=0, .inbox_msg_size=0, .outbox_msg_size=0, .inbox_status=PACKET_ABSENT, .outbox_status=PACKET_ABSENT, .inbox_overflow=false, .inbox={0}, .outbox={0}};
Mailbox<PGOOD_PIN_INBOX_SIZE, PGOOD_PIN_OUTBOX_SIZE>    pgood_pin_mailbox       = {.my_id=PGOOD_PIN_ADDRESS,        .to_id=0, .from_id=0, .inbox_msg_size=0, .outbox_msg_size=0, .inbox_status=PACKET_ABSENT, .outbox_status=PACKET_ABSENT, .inbox_overflow=false                         };
Mailbox<FAULTB_PIN_INBOX_SIZE, PGOOD_PIN_OUTBOX_SIZE>   faultb_pin_mailbox      = {.my_id=FAULTB_PIN_ADDRESS,       .to_id=0, .from_id=0, .inbox_msg_size=0, .outbox_msg_size=0, .inbox_status=PACKET_ABSENT, .outbox_status=PACKET_ABSENT, .inbox_overflow=false                         };
Mailbox<WATCHDOG_INBOX_SIZE, WATCHDOG_OUTBOX_SIZE>      watchdog_mailbox        = {.my_id=WATCHDOG_ADDRESS,         .to_id=0, .from_id=0, .inbox_msg_size=0, .outbox_msg_size=0, .inbox_status=PACKET_ABSENT, .outbox_status=PACKET_ABSENT, .inbox_overflow=false, .inbox={0}, .outbox={0}};
Mailbox<EEPROM_INBOX_SIZE, EEPROM_OUTBOX_SIZE>          eeprom_mailbox          = {.my_id=EEPROM_ADDRESS,           .to_id=0, .from_id=0, .inbox_msg_size=0, .outbox_msg_size=0, .inbox_status=PACKET_ABSENT, .outbox_status=PACKET_ABSENT, .inbox_overflow=false, .inbox={0}, .outbox={0}};
Mailbox<TMP117_INBOX_SIZE, TMP117_OUTBOX_SIZE>          tmp117_mailbox          = {.my_id=TMP117_ADDRESS,           .to_id=0, .from_id=0, .inbox_msg_size=0, .outbox_msg_size=0, .inbox_status=PACKET_ABSENT, .outbox_status=PACKET_ABSENT, .inbox_overflow=false, .inbox={0}, .outbox={0}};
/****************************************************************************
 *                                                                          *
 ****************************************************************************/

/****************************************************************************
 * Process incoming and outgoing mail                                       *
 ****************************************************************************/
void process_mail()
{
   /********************************
    * Incoming Mail                *
    ********************************/
    if(labcomm_packet.available)
        switch(labcomm_packet.destination_id)
        {
            case SMBUS_SERVICES_ADDRESS:    smbus_services_mailbox.get_packet(&labcomm_packet); break;
            case REM_ATH_PIN_ADDRESS:       rem_ath_pin_mailbox.get_packet(&labcomm_packet);    break;
            case FAULTB_PIN_ADDRESS:        faultb_pin_mailbox.get_packet(&labcomm_packet);     break;
            case WD_DIS_PIN_ADDRESS:        wd_dis_pin_mailbox.get_packet(&labcomm_packet);     break;
            case ENABLE_PIN_ADDRESS:        enable_pin_mailbox.get_packet(&labcomm_packet);     break;
            case MCUERR_PIN_ADDRESS:        mcuerr_pin_mailbox.get_packet(&labcomm_packet);     break;
            case PGOOD_PIN_ADDRESS:         pgood_pin_mailbox.get_packet(&labcomm_packet);      break;
            case IDENTIFY_ADDRESS:          identify_mailbox.get_packet(&labcomm_packet);       break;
            case WATCHDOG_ADDRESS:          watchdog_mailbox.get_packet(&labcomm_packet);       break;
            case EEPROM_ADDRESS:            eeprom_mailbox.get_packet(&labcomm_packet);         break;
            case TMP117_ADDRESS:            tmp117_mailbox.get_packet(&labcomm_packet);         break;
        }
   /********************************
    * Outgoing Mail                *
    ********************************/
    if(tmp117_mailbox.outbox_status == PACKET_PRESENT)          tmp117_mailbox.send_packet();
    if(eeprom_mailbox.outbox_status == PACKET_PRESENT)          eeprom_mailbox.send_packet();
    if(identify_mailbox.outbox_status == PACKET_PRESENT)        identify_mailbox.send_packet();
    if(watchdog_mailbox.outbox_status == PACKET_PRESENT)        watchdog_mailbox.send_packet();
    if(pgood_pin_mailbox.outbox_status == PACKET_PRESENT)       pgood_pin_mailbox.send_packet();
    if(faultb_pin_mailbox.outbox_status == PACKET_PRESENT)      faultb_pin_mailbox.send_packet();
    if(enable_pin_mailbox.outbox_status == PACKET_PRESENT)      enable_pin_mailbox.send_packet();
    if(mcuerr_pin_mailbox.outbox_status == PACKET_PRESENT)      mcuerr_pin_mailbox.send_packet();
    if(rem_ath_pin_mailbox.outbox_status == PACKET_PRESENT)     rem_ath_pin_mailbox.send_packet();
    if(wd_dis_pin_mailbox.outbox_status == PACKET_PRESENT)      wd_dis_pin_mailbox.send_packet();
    if(smbus_services_mailbox.outbox_status == PACKET_PRESENT)  smbus_services_mailbox.send_packet();
    if(labcomm_mailbox.outbox_status == PACKET_PRESENT)         labcomm_mailbox.send_packet();
}