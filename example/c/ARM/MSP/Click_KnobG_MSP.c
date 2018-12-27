/*
Example for KnobG Click

    Date          : okt 2018.
    Author        : Katarina Perendic

Test configuration MSP :
    
    MCU              : MSP432
    Dev. Board       : Clicker 2 for MSP432
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes I2C module, sets INT pin, AN pin and CS pin as INPUT and sets RST pin and PWM pin as OUTPUT
- Application Initialization - Initialization driver init, reset device, enable led output, 
                               set output gain on maximum and sets new start position of the encoder.
- Application Task - (code snippet) - The Task application has 3 test modes:
                                      * The first example is setting BRIGHTNESS on all LEDs.
                                      * Other examples put the LED in the position read from the encoder.
                                      * The third example sets the LED to be read while the encoder registers the clockwise movement
                                      and turn off those LEDs that the encoder reads when moving in a counterclockwise direction.
                                      * The example is changed by pressing the SW button
*/

#include "Click_KnobG_types.h"
#include "Click_KnobG_config.h"

int32_t encoder_newPosition = 0;
int32_t encoder_oldPosition = 0;
uint8_t direction;
char demoText[ 100 ];
uint8_t SW_State = 0;
uint8_t cnt;


void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_INPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
    
    mikrobus_i2cInit( _MIKROBUS1, &_KNOBG_I2C_CFG[0] );
    mikrobus_logInit( _MIKROBUS2, 9600 );
    mikrobus_logWrite("--- System Init ---", _LOG_LINE);
    Delay_ms( 100 );
}

void applicationInit()
{
    knobg_i2cDriverInit( (T_KNOBG_P)&_MIKROBUS1_GPIO, (T_KNOBG_P)&_MIKROBUS1_I2C, _KNOBG_DEF_SLAVE_ADDRESS );
    knobg_reset();
    Delay_ms( 300 );

    knobg_ledOutputEnable( _KNOBG_ENABLE_LED_OUTPUTS );
    knobg_setOutputGain(_KNOBG_OUTPUT_GAIN_ALL_LED, _KNOBG_FULL_OUTPUT_CURRENT_GAIN);
    knobg_encoderNewStartPosition( 1 );
}

void applicationTask()
{
    knobg_getEncoderPosition(&encoder_newPosition, &direction);
    
    if(knobg_getSWButtonState() == 0)
    {
        SW_State++;
        if(SW_State >= 3) SW_State = 0;
        
        knobg_setBrightness(_KNOBG_BRIGHTNESS_ALL_LED, 0x00);
        Delay_ms( 300 );
    }
    
    /* Logs position */
    if(encoder_newPosition != encoder_oldPosition)
    {
        WordToStr(encoder_newPosition, demoText);
        mikrobus_logWrite(" EnCoder position : ", _LOG_TEXT);
        mikrobus_logWrite(demoText, _LOG_LINE);
    }
    encoder_oldPosition = encoder_newPosition;
    
    switch(SW_State)
    {
        /* Brightness */
        case 0:
        {
            cnt++;
            if(cnt > 127) cnt = 0;
            knobg_setBrightness(_KNOBG_BRIGHTNESS_ALL_LED, cnt);
            Delay_ms( 15 );
            break;
        }
        /* Encoder with one led*/
        case 1:
        {
            if(encoder_newPosition > 24) knobg_encoderNewStartPosition( 1 );
            if(encoder_newPosition < 1) knobg_encoderNewStartPosition( 24 );

            if(direction == 1)
            {
                knobg_setLedState(encoder_newPosition, _KNOBG_LED_ON);
                knobg_setLedState(encoder_newPosition - 1, _KNOBG_LED_OFF);
            }
            else
            {
                knobg_setLedState(encoder_newPosition, _KNOBG_LED_ON);
                knobg_setLedState(encoder_newPosition + 1, _KNOBG_LED_OFF);
            }
            Delay_1ms();
            break;
        }
        /* Encoder with all led */
        case 2:
        {
            if(encoder_newPosition > 24) knobg_encoderNewStartPosition( 1 );
            if(encoder_newPosition < 1) knobg_encoderNewStartPosition( 24 );
            
            if(direction == 1)
            {
                knobg_setLedState(encoder_newPosition, _KNOBG_LED_ON);
            }
            else
            {
                knobg_setLedState(encoder_newPosition + 1, _KNOBG_LED_OFF);
            }
            Delay_1ms();
            break;
        }
    }
}


void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}