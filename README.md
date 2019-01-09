![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# KnobG Click

- **CIC Prefix**  : KNOBG
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : okt 2018.

---

### Software Support

We provide a library for the KnobG Click on our [LibStock](https://libstock.mikroe.com/projects/view/2600/knob-g-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes and defines the I2C bus driver and drivers that offer a choice for writing data in register and reads data form register.
The library includes function for read Encoder position and sets new start position.
The user also has the functions for full control LEDs.

Key functions :

- ``` void knobg_setLedState(uint8_t led, uint8_t state) ``` - Functions for set led state
- ``` void knobg_getEncoderPosition(int32_t *position, uint8_t *dir) ``` - Functions for get Encoder position
- ``` void knobg_encoderNewStartPosition(int32_t position) ``` - Functions for set new start encoder position

**Examples Description**

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


```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2600/knob-g-click) page.

Other mikroE Libraries used in the example:

- I2C

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
