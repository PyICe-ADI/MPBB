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
    pinMode(HEARTBEAT_LED, OUTPUT);
    pinMode(TESTHOOK_PIN, OUTPUT);
    pinMode(ENABLEB_PIN, OUTPUT);
    pinMode(WDDISB_PIN, OUTPUT);
    pinMode(FAULTB_PIN, INPUT);
    pinMode(PGOOD_PIN, INPUT);
    /**********************************************
    * Have D.U.T. default to off                  *
    ***********************************************/
    digitalWrite(WDDISB_PIN, HIGH);
    digitalWrite(ENABLEB_PIN, HIGH);

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
    get_pgood_pin();
    service_smbus();
    get_faultb_pin();
    get_push_button();
    eeprom_services();
    watchdog_services();
    set_wd_dis_pin_state();
    set_enable_pin_state();
    get_temperature_sensor();
}
