#line 1 "D:/Clicks_git/K/Knob_G_Click/SW/example/c/ARM/STM/Click_KnobG_STM.c"
#line 1 "d:/clicks_git/k/knob_g_click/sw/example/c/arm/stm/click_knobg_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/k/knob_g_click/sw/example/c/arm/stm/click_knobg_config.h"
#line 1 "d:/clicks_git/k/knob_g_click/sw/example/c/arm/stm/click_knobg_types.h"
#line 3 "d:/clicks_git/k/knob_g_click/sw/example/c/arm/stm/click_knobg_config.h"
const uint32_t _KNOBG_I2C_CFG[ 1 ] =
{
 100000
};
#line 33 "D:/Clicks_git/K/Knob_G_Click/SW/example/c/ARM/STM/Click_KnobG_STM.c"
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
 mikrobus_logInit( _LOG_USBUART_A, 9600 );
 mikrobus_logWrite("--- System Init ---", _LOG_LINE);
 Delay_ms( 100 );
}

void applicationInit()
{
 knobg_i2cDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_I2C, _KNOBG_DEF_SLAVE_ADDRESS );
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
 SW_state++;
 if(SW_State >= 3) SW_State = 0;

 knobg_setBrightness(_KNOBG_BRIGHTNESS_ALL_LED, 0x00);
 Delay_ms( 300 );
 }


 if(encoder_newPosition != encoder_oldPosition)
 {
 LongToStr(encoder_newPosition, demoText);
 mikrobus_logWrite(" EnCoder position : ", _LOG_TEXT);
 mikrobus_logWrite(demoText, _LOG_LINE);
 }
 encoder_oldPosition = encoder_newPosition;

 switch(SW_State)
 {

 case 0:
 {
 cnt++;
 if(cnt > 127) cnt = 0;
 knobg_setBrightness(_KNOBG_BRIGHTNESS_ALL_LED, cnt);
 Delay_ms( 15 );
 break;
 }

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
