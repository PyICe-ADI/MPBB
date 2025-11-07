/****************************************************************************
 * Demo Board for the Morpheus Family of Products                           *
 * Steve Martin                                                            	*
 * April 21, 2025                                                           *
 ****************************************************************************/
#include "MPBB.h"

/****************************************************************************
 * Setup                                                                    *
 ****************************************************************************/
void setup()
{
    // TwoWire aux_i2C(&sercom1, 11, 13); // started adding second I2C port
    Wire.begin();
    SerialUSB.begin(115200);
    pinMode(REMOTE_ATH_PIN, OUTPUT);
    pinMode(HEARTBEAT_LED, OUTPUT);
    pinMode(TESTHOOK_PIN, OUTPUT);
    pinMode(ENABLEB_PIN, OUTPUT);
    pinMode(MCUERRB_PIN, OUTPUT);
    pinMode(WDDISB_PIN, OUTPUT);
    pinMode(FAULTB_LED, OUTPUT);
    pinMode(PGOOD_LED, OUTPUT);
    pinMode(FAULTB_PIN, INPUT);
    pinMode(PGOOD_PIN, INPUT);
    /**********************************************
    * Have D.U.T. default to off                  *
    ***********************************************/
    digitalWrite(WDDISB_PIN, HIGH);
    digitalWrite(ENABLEB_PIN, HIGH);
    digitalWrite(MCUERRB_PIN, LOW);
    digitalWrite(REMOTE_ATH_PIN, LOW);

    setup_softport();
}
/****************************************************************************
 * Loop                                                                     *
 ****************************************************************************/
void loop() // Simple and fast round robin operating system
{
    process_serial();
    identify();
    set_leds();
    heartbeat();
    process_mail();
    service_smbus();
    get_pgood_pin();
    get_faultb_pin();
    get_push_button();
    eeprom_services();
    watchdog_services();
    process_wddis_pin();
    process_enable_pin();
    process_mcuerr_pin();
    process_remote_ath_pin();
    get_temperature_sensor();
}
