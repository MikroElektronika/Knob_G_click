/*
    __knobg_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__knobg_driver.h"
#include "__knobg_hal.c"

/* ------------------------------------------------------------------- MACROS */

/* Register */

const uint8_t _KNOBG_REG_MODE_1                          = 0x00;
const uint8_t _KNOBG_REG_MODE_2                          = 0x01;
const uint8_t _KNOBG_REG_LED_OUTPUT_STATE_0              = 0x02;
const uint8_t _KNOBG_REG_LED_OUTPUT_STATE_1              = 0x03;
const uint8_t _KNOBG_REG_LED_OUTPUT_STATE_2              = 0x04;
const uint8_t _KNOBG_REG_LED_OUTPUT_STATE_3              = 0x05;
const uint8_t _KNOBG_REG_LED_OUTPUT_STATE_4              = 0x06;
const uint8_t _KNOBG_REG_LED_OUTPUT_STATE_5              = 0x07;
const uint8_t _KNOBG_REG_GROUP_DUTY_CYCLE_CONTROL        = 0x08;
const uint8_t _KNOBG_REG_GROUP_FREQUENCY                 = 0x09;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_0        = 0x0A;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_1        = 0x0B;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_2        = 0x0C;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_3        = 0x0D;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_4        = 0x0E;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_5        = 0x0F;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_6        = 0x10;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_7        = 0x11;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_8        = 0x12;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_9        = 0x13;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_10       = 0x14;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_11       = 0x15;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_12       = 0x16;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_13       = 0x17;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_14       = 0x18;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_15       = 0x19;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_16       = 0x1A;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_17       = 0x1B;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_18       = 0x1C;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_19       = 0x1D;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_20       = 0x1E;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_21       = 0x1F;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_22       = 0x20;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_LED_23       = 0x21;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_0           = 0x22;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_1           = 0x23;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_2           = 0x24;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_3           = 0x25;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_4           = 0x26;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_5           = 0x27;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_6           = 0x28;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_7           = 0x29;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_8           = 0x2A;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_9           = 0x2B;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_10          = 0x2C;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_11          = 0x2D;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_12          = 0x2E;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_13          = 0x2F;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_14          = 0x30;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_15          = 0x31;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_16          = 0x32;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_17          = 0x33;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_18          = 0x34;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_19          = 0x35;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_20          = 0x36;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_21          = 0x37;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_22          = 0x38;
const uint8_t _KNOBG_REG_OUTPUT_GAIN_CONTROL_23          = 0x39;
const uint8_t _KNOBG_REG_OFFSET                          = 0x3A;
const uint8_t _KNOBG_REG_I2C_BUS_SUBADDRESS_1            = 0x3B;
const uint8_t _KNOBG_REG_I2C_BUS_SUBADDRESS_2            = 0x3C;
const uint8_t _KNOBG_REG_I2C_BUS_SUBADDRESS_3            = 0x3D;
const uint8_t _KNOBG_REG_ALL_CALL_I2C_BUS_ADDRESS        = 0x3E;
const uint8_t _KNOBG_REG_BRIGHTNESS_CONTROL_FOR_ALL_LED  = 0x3F;
const uint8_t _KNOBG_REG_GAIN_CONTROL_FOR_ALL_LED        = 0x40;
const uint8_t _KNOBG_REG_OUTPUT_ERROR_FLAG_0             = 0x41;
const uint8_t _KNOBG_REG_OUTPUT_ERROR_FLAG_1             = 0x42;
const uint8_t _KNOBG_REG_OUTPUT_ERROR_FLAG_2             = 0x43;
const uint8_t _KNOBG_REG_OUTPUT_ERROR_FLAG_3             = 0x44;
const uint8_t _KNOBG_REG_OUTPUT_ERROR_FLAG_4             = 0x45;
const uint8_t _KNOBG_REG_OUTPUT_ERROR_FLAG_5             = 0x46;

/* Mode register 1 */
const uint8_t _KNOBG_M1_AUTO_INCREMENT_BIT_1_TO_0     = 0x00;
const uint8_t _KNOBG_M1_AUTO_INCREMENT_BIT_1_TO_1     = 0x40;
const uint8_t _KNOBG_M1_AUTO_INCREMENT_BIT_0_TO_0     = 0x00;
const uint8_t _KNOBG_M1_AUTO_INCREMENT_BIT_0_TO_1     = 0x20;
const uint8_t _KNOBG_M1_SET_NORMAL_MODE               = 0x00;
const uint8_t _KNOBG_M1_SET_LOW_POWER_MODE            = 0x10;
const uint8_t _KNOBG_M1_USES_I2C_BUS_SUBADDRESS_1     = 0x08;
const uint8_t _KNOBG_M1_USES_I2C_BUS_SUBADDRESS_2     = 0x04;
const uint8_t _KNOBG_M1_USES_I2C_BUS_SUBADDRESS_3     = 0x02;
const uint8_t _KNOBG_M1_USES_ALL_CALL_I2C_BUS_ADDRESS = 0x01;

/* Mode register 2 */
const uint8_t _KNOBG_M2_GROUP_CONTROL_DIMMING  = 0x00;
const uint8_t _KNOBG_M2_GROUP_CONTROL_BLINKING = 0x20;
const uint8_t _KNOBG_M2_CHANGE_ON_STOP_CMD = 0x00;
const uint8_t _KNOBG_M2_CHANGE_ON_ACK      = 0x10;

const uint8_t _KNOBG_BRIGHTNESS_ALL_LED   = 0x30;
const uint8_t _KNOBG_OUTPUT_GAIN_ALL_LED  = 0x40;

const uint8_t _KNOBG_LED_ON  = 0xFF;
const uint8_t _KNOBG_LED_OFF = 0x00;

const uint8_t _KNOBG_DEF_SLAVE_ADDRESS = 0x70;
const uint8_t _KNOBG_FULL_OUTPUT_CURRENT_GAIN = 0xFF;

const uint8_t _KNOBG_ENABLE_LED_OUTPUTS = 0x00;
const uint8_t _KNOBG_DISABLE_LED_OUTPUTS = 0x01;


/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __KNOBG_DRV_I2C__
static uint8_t _slaveAddress;
#endif

static int32_t _encoderPosition = 0;
static uint8_t _stateOldRotate;
static uint8_t _stateNewRotate;
static uint8_t _startStatus;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __KNOBG_DRV_SPI__

void knobg_spiDriverInit(T_KNOBG_P gpioObj, T_KNOBG_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __KNOBG_DRV_I2C__

void knobg_i2cDriverInit(T_KNOBG_P gpioObj, T_KNOBG_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __KNOBG_DRV_UART__

void knobg_uartDriverInit(T_KNOBG_P gpioObj, T_KNOBG_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

void knobg_writeByte(uint8_t reg, uint8_t _data)
{
    uint8_t writeReg[ 2 ];

    writeReg[ 0 ] = reg;
    writeReg[ 1 ] = _data;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 2, END_MODE_STOP);
}

uint8_t knobg_readByte(uint8_t reg)
{
    uint8_t writeReg[ 1 ];
    uint8_t readReg[ 1 ];
    
    writeReg[ 0 ] = reg;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, writeReg, 1, END_MODE_RESTART);
    hal_i2cRead(_slaveAddress, readReg, 1, END_MODE_STOP);

    return readReg[ 0 ];
}

void knobg_reset()
{
    hal_gpio_rstSet( 0 );
    Delay_10ms();
    hal_gpio_rstSet( 1 );
    Delay_10ms();
    knobg_writeByte(0x40, 0xFF);
}

void knobg_ledOutputEnable(uint8_t state)
{
    hal_gpio_pwmSet(state);
}

uint8_t knobg_getENAState()
{
    return hal_gpio_anGet();
}

uint8_t knobg_getENBState()
{
    return hal_gpio_csGet();
}

uint8_t knobg_getSWButtonState()
{
    return hal_gpio_intGet();
}

void knobg_getEncoderPosition(int32_t *position, uint8_t *dir)
{
    uint8_t ENA;
    uint8_t ENB;

    ENA = knobg_getENAState();
    ENB = knobg_getENBState();
    
    if (ENA == ENB)
    {
        _stateOldRotate = 0;
        _startStatus = ENA && ENB;
    }
     else
     {
         _stateNewRotate = 1;
         if (_stateNewRotate != _stateOldRotate)
         {
             _stateOldRotate = 1;
             if (_startStatus ==  knobg_getENAState())
             {
                 _encoderPosition++;
                 *dir = 1;
             }
             else
             {
                 _encoderPosition--;
                 *dir = 2;
             }
         }
     }
     *position = _encoderPosition;
}

void knobg_encoderNewStartPosition(int32_t position)
{
    _encoderPosition = position;
}

void knobg_setLedState(uint8_t led, uint8_t state)
{
     knobg_writeByte(0x09 + led, state);
}

void knobg_setBrightness(uint8_t led, uint8_t value)
{
    if(led == _KNOBG_BRIGHTNESS_ALL_LED)
    {
         knobg_writeByte(0x3F, value);
    }
    else
    {
         knobg_writeByte(led, value);
    }
}

void knobg_setOutputGain(uint8_t led, uint8_t value)
{
    if(led == _KNOBG_OUTPUT_GAIN_ALL_LED)
    {
         knobg_writeByte(0x3F, value);
    }
    else
    {
         knobg_writeByte(led, value);
    }
}

/* -------------------------------------------------------------------------- */
/*
  __knobg_driver.c

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