/****************************************************************************
 * MPBB PEC                                                                 *
 * Steve Martin                                                             *
 * April 21, 2025                                                           *
 ****************************************************************************/

#ifndef PEC_H
#define PEC_H

#include <stdint.h>
#include <avr/pgmspace.h> // For PEC table storage

//Uncomment following line to switch from bitwise runtime computation to table lookup.
#define CRC_TABLE

  /*! Computes CRC-8 using x^8 + X^2 + X + 1 polynomial with most-significant-bit first endianness.
   *  SMBUs computes the PEC over all bytes of the transaction with initialization value 0 and no
   *  pre or post XOR operations.
   *
   *  More efficient execution can be achieved by calling the crc8 function repeatedly from within
   *  the user-supplied, hardware-specific read and write functions rather than using the functions below
   *  with additional stack operations.
   */
  uint8_t crc8(uint8_t data, //!< Byte over which to compute updated CRC.
               uint8_t crc   //!< Previous remainder, or initialization value for first byte. PEC initializes to 0.
              );

  /*! Computes Packet Error Check byte to be sent at end of SMBus write_word transaction. */
  uint8_t pec_write_word(uint8_t address,      //!< 7-bit SMBus slave address
                         uint8_t command_code, //!< SMBus command code (slave memory address)
                         uint16_t data         //!< Data to be written to slave
                        );

  /*! Computes expected Packet Error Check byte from read_word transaction*/
  uint8_t pec_read_word(uint8_t address,      //!< 7-bit SMBus slave address
                        uint8_t command_code, //!< SMBus command code (slave memory address)
                        uint16_t data         //!< Data read from slave
                       );

  /*! Computes Packet Error Check result over completed SMBus read_word transaction.
   *  Returns 0 for no errors.
   */
  uint8_t pec_read_word_test(uint8_t address,      //!< 7-bit SMBus slave address
                             uint8_t command_code, //!< SMBus command code (slave memory address)
                             uint16_t data,        //!< Data read from slave
                             uint8_t pec           //!< Packet error check byte read from slave
                            );

  /*! Computes Packet Error Checking byte to be sent at end of SMBus write_byte transaction. */
  uint8_t pec_write_byte(uint8_t address,      //!< 7-bit SMBus slave address
                         uint8_t command_code, //!< SMBus command code (slave memory address)
                         uint8_t data          //!< Data to be written to slave
                        );

  /*! Computes expected Packet Error Check byte from read_byte transaction*/
  uint8_t pec_read_byte(uint8_t address,      //!< 7-bit SMBus slave address
                        uint8_t command_code, //!< SMBus command code (slave memory address)
                        uint8_t data          //!< Data read from slave
                       );

  /*! Computes Packet Error Checking result over completed SMBus read_byte transaction.
   *  Returns 0 for no errors.
   */
  uint8_t pec_read_byte_test(uint8_t address,      //!< 7-bit SMBus slave address
                             uint8_t command_code, //!< SMBus command code (slave memory address)
                             uint8_t data,         //!< Data read from slave
                             uint8_t pec           //!< Packet error check byte read from slave
                            );

#endif