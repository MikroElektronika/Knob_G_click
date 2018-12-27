/*
    __knobg_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __knobg_driver.h
@brief    KnobG Driver
@mainpage KnobG Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   KNOBG
@brief      KnobG Click Driver
@{

| Global Library Prefix | **KNOBG** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **okt 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _KNOBG_H_
#define _KNOBG_H_

/** 
 * @macro T_KNOBG_P
 * @brief Driver Abstract type 
 */
#define T_KNOBG_P    const uint8_t*

/** @defgroup KNOBG_COMPILE Compilation Config */              /** @{ */

//  #define   __KNOBG_DRV_SPI__                            /**<     @macro __KNOBG_DRV_SPI__  @brief SPI driver selector */
   #define   __KNOBG_DRV_I2C__                            /**<     @macro __KNOBG_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __KNOBG_DRV_UART__                           /**<     @macro __KNOBG_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup KNOBG_VAR Variables */                           /** @{ */

/* Register */
extern const uint8_t _KNOBG_REG_MODE_1                         ;
extern const uint8_t _KNOBG_REG_MODE_2                         ;
extern const uint8_t _KNOBG_REG_LED_OUTPUT_STATE_0             ;
extern const uint8_t _KNOBG_REG_LED_OUTPUT_STATE_1             ;
extern const uint8_t _KNOBG_REG_LED_OUTPUT_STATE_2             ;
extern const uint8_t _KNOBG_REG_LED_OUTPUT_STATE_3             ;
extern const uint8_t _KNOBG_REG_LED_OUTPUT_STATE_4             ;
extern const uint8_t _KNOBG_REG_LED_OUTPUT_STATE_5             ;
extern const uint8_t _KNOBG_REG_GROUP_DUTY_CYCLE_CONTROL       ;
extern const uint8_t _KNOBG_REG_GROUP_FREQUENCY                ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_0       ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_1       ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_2       ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_3       ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_4       ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_5       ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_6       ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_7       ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_8       ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_9       ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_10      ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_11      ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_12      ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_13      ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_14      ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_15      ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_16      ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_17      ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_18      ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_19      ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_20      ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_21      ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_22      ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_23      ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_0          ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_1          ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_2          ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_3          ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_4          ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_5          ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_6          ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_7          ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_8          ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_9          ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_10         ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_11         ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_12         ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_13         ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_14         ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_15         ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_16         ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_17         ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_18         ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_19         ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_20         ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_21         ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_22         ;
extern const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_23         ;
extern const uint8_t _KNOBG_REG_OFFSET                         ;
extern const uint8_t _KNOBG_REG_I2C_BUS_SUBADDRESS_1           ;
extern const uint8_t _KNOBG_REG_I2C_BUS_SUBADDRESS_2           ;
extern const uint8_t _KNOBG_REG_I2C_BUS_SUBADDRESS_3           ;
extern const uint8_t _KNOBG_REG_ALL_CALL_I2C_BUS_ADDRESS       ;
extern const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_FOR_ALL_LED ;
extern const uint8_t _KNOBG_REG_GAIN_CONTROL_FOR_ALL_LED       ;
extern const uint8_t _KNOBG_REG_OUTPUT_ERROR_FLAG_0            ;
extern const uint8_t _KNOBG_REG_OUTPUT_ERROR_FLAG_1            ;
extern const uint8_t _KNOBG_REG_OUTPUT_ERROR_FLAG_2            ;
extern const uint8_t _KNOBG_REG_OUTPUT_ERROR_FLAG_3            ;
extern const uint8_t _KNOBG_REG_OUTPUT_ERROR_FLAG_4            ;
extern const uint8_t _KNOBG_REG_OUTPUT_ERROR_FLAG_5            ;

/* Mode register 1 */
extern const uint8_t _KNOBG_M1_AUTO_INCREMENT_BIT_1_TO_0     ;
extern const uint8_t _KNOBG_M1_AUTO_INCREMENT_BIT_1_TO_1     ;
extern const uint8_t _KNOBG_M1_AUTO_INCREMENT_BIT_0_TO_0     ;
extern const uint8_t _KNOBG_M1_AUTO_INCREMENT_BIT_0_TO_1     ;
extern const uint8_t _KNOBG_M1_SET_NORMAL_MODE               ;
extern const uint8_t _KNOBG_M1_SET_LOW_POWER_MODE            ;
extern const uint8_t _KNOBG_M1_USES_I2C_BUS_SUBADDRESS_1     ;
extern const uint8_t _KNOBG_M1_USES_I2C_BUS_SUBADDRESS_2     ;
extern const uint8_t _KNOBG_M1_USES_I2C_BUS_SUBADDRESS_3     ;
extern const uint8_t _KNOBG_M1_USES_ALL_CALL_I2C_BUS_ADDRESS ;

/* Mode register 2 */
extern const uint8_t _KNOBG_M2_GROUP_CONTROL_DIMMING ;
extern const uint8_t _KNOBG_M2_GROUP_CONTROL_BLINKING;
extern const uint8_t _KNOBG_M2_CHANGE_ON_STOP_CMD;
extern const uint8_t _KNOBG_M2_CHANGE_ON_ACK     ;

extern const uint8_t _KNOBG_BRIGHTNESS_ALL_LED  ;
extern const uint8_t _KNOBG_OUTPUT_GAIN_ALL_LED ;

extern const uint8_t _KNOBG_LED_ON ;
extern const uint8_t _KNOBG_LED_OFF;

extern const uint8_t _KNOBG_DEF_SLAVE_ADDRESS;
extern const uint8_t _KNOBG_FULL_OUTPUT_CURRENT_GAIN;

extern const uint8_t _KNOBG_ENABLE_LED_OUTPUTS  ;
extern const uint8_t _KNOBG_DISABLE_LED_OUTPUTS ;


                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup KNOBG_INIT Driver Initialization */              /** @{ */

#ifdef   __KNOBG_DRV_SPI__
void knobg_spiDriverInit(T_KNOBG_P gpioObj, T_KNOBG_P spiObj);
#endif
#ifdef   __KNOBG_DRV_I2C__
void knobg_i2cDriverInit(T_KNOBG_P gpioObj, T_KNOBG_P i2cObj, uint8_t slave);
#endif
#ifdef   __KNOBG_DRV_UART__
void knobg_uartDriverInit(T_KNOBG_P gpioObj, T_KNOBG_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void knobg_gpioDriverInit(T_KNOBG_P gpioObj);
                                                                       /** @} */
/** @defgroup KNOBG_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Functions for write one byte in register
 *
 * @param[in] reg    Register in which the data will be written
 * @param[in] _data  Data which be written in the register
 */
void knobg_writeByte(uint8_t reg, uint8_t _data);

/**
 * @brief Functions for read byte from register
 *
 * @param[in] reg    Register which will be read
 * @retval one byte data which is read from the register
 */
uint8_t knobg_readByte(uint8_t reg);

/**
 * @brief Functions for reset device
 */
void knobg_reset();

/**
 * @brief Functions for enable Led Output
 */
void knobg_ledOutputEnable(uint8_t state);

/**
 * @brief Functions for get ENA pin state
 */
uint8_t knobg_getENAState();

/**
 * @brief Functions for get ENB pin state
 */
uint8_t knobg_getENBState();

/**
 * @brief Functions for get SW pin(switch button) state
 */
uint8_t knobg_getSWButtonState();

/**
 * @brief Functions for get Encoder position
 *
 * @param[out] position    Encoder position (counter)
 * @param[out] dir         Encoder direction
 */
void knobg_getEncoderPosition(int32_t *position, uint8_t *dir);

/**
 * @brief Functions for set new start encoder position
 *
 * @param[in] position     Start encoder position
 */
void knobg_encoderNewStartPosition(int32_t position);

/**
 * @brief Functions for set led state(PWM on the LED)
 *
 * @param[in] led       LEDs
 * @param[in] value     PWM(state)
 */
void knobg_setLedState(uint8_t led, uint8_t state);

/**
 * @brief Functions for set Brightness
 *
 * @param[in] led       LEDs
 * @param[in] value     PWM(state)
 *
 * @note:
     For Led you can choose to set all LEDs(_KNOBG_BRIGHTNESS_ALL_LED) or
     set one LED(_KNOBG_REG_BRIGHTNESS_CONTROL_LED_0 to _KNOBG_REG_BRIGHTNESS_CONTROL_LED_23) to the desired state
 */
void knobg_setBrightness(uint8_t led, uint8_t value);

/**
 * @brief Functions for set Brightness
 *
 * @param[in] led       LEDs
 * @param[in] value     PWM(state)
 *
 * @note:
     For Led you can choose to set all LEDs(_KNOBG_OUTPUT_GAIN_ALL_LED) or
     set one LED(_KNOBG_REG_OUTPUT_GAIN_CONTROL_0 to _KNOBG_REG_OUTPUT_GAIN_CONTROL_1) to the desired state
 */
void knobg_setOutputGain(uint8_t led, uint8_t value);









                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_KnobG_STM.c
    @example Click_KnobG_TIVA.c
    @example Click_KnobG_CEC.c
    @example Click_KnobG_KINETIS.c
    @example Click_KnobG_MSP.c
    @example Click_KnobG_PIC.c
    @example Click_KnobG_PIC32.c
    @example Click_KnobG_DSPIC.c
    @example Click_KnobG_AVR.c
    @example Click_KnobG_FT90x.c
    @example Click_KnobG_STM.mbas
    @example Click_KnobG_TIVA.mbas
    @example Click_KnobG_CEC.mbas
    @example Click_KnobG_KINETIS.mbas
    @example Click_KnobG_MSP.mbas
    @example Click_KnobG_PIC.mbas
    @example Click_KnobG_PIC32.mbas
    @example Click_KnobG_DSPIC.mbas
    @example Click_KnobG_AVR.mbas
    @example Click_KnobG_FT90x.mbas
    @example Click_KnobG_STM.mpas
    @example Click_KnobG_TIVA.mpas
    @example Click_KnobG_CEC.mpas
    @example Click_KnobG_KINETIS.mpas
    @example Click_KnobG_MSP.mpas
    @example Click_KnobG_PIC.mpas
    @example Click_KnobG_PIC32.mpas
    @example Click_KnobG_DSPIC.mpas
    @example Click_KnobG_AVR.mpas
    @example Click_KnobG_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __knobg_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */