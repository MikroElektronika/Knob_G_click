_systemInit:
;Click_KnobG_STM.c,41 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_KnobG_STM.c,43 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
MOVS	R2, #1
MOVS	R1, #7
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_KnobG_STM.c,44 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );
MOVS	R2, #1
MOVS	R1, #0
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_KnobG_STM.c,45 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_INPUT );
MOVS	R2, #1
MOVS	R1, #2
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_KnobG_STM.c,46 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #1
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_KnobG_STM.c,47 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_PWM_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #6
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_KnobG_STM.c,49 :: 		mikrobus_i2cInit( _MIKROBUS1, &_KNOBG_I2C_CFG[0] );
MOVW	R0, #lo_addr(__KNOBG_I2C_CFG+0)
MOVT	R0, #hi_addr(__KNOBG_I2C_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_i2cInit+0
;Click_KnobG_STM.c,50 :: 		mikrobus_logInit( _LOG_USBUART_A, 9600 );
MOVW	R1, #9600
MOVS	R0, #32
BL	_mikrobus_logInit+0
;Click_KnobG_STM.c,51 :: 		mikrobus_logWrite("--- System Init ---", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr1_Click_KnobG_STM+0)
MOVT	R0, #hi_addr(?lstr1_Click_KnobG_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_KnobG_STM.c,52 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_KnobG_STM.c,53 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_KnobG_STM.c,55 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_KnobG_STM.c,57 :: 		knobg_i2cDriverInit( (T_KNOBG_P)&_MIKROBUS1_GPIO, (T_KNOBG_P)&_MIKROBUS1_I2C, _KNOBG_DEF_SLAVE_ADDRESS );
MOVS	R2, #112
MOVW	R1, #lo_addr(__MIKROBUS1_I2C+0)
MOVT	R1, #hi_addr(__MIKROBUS1_I2C+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_knobg_i2cDriverInit+0
;Click_KnobG_STM.c,58 :: 		knobg_reset();
BL	_knobg_reset+0
;Click_KnobG_STM.c,59 :: 		Delay_ms( 300 );
MOVW	R7, #61055
MOVT	R7, #54
NOP
NOP
L_applicationInit2:
SUBS	R7, R7, #1
BNE	L_applicationInit2
NOP
NOP
NOP
;Click_KnobG_STM.c,61 :: 		knobg_ledOutputEnable( _KNOBG_ENABLE_LED_OUTPUTS );
MOVS	R0, #0
BL	_knobg_ledOutputEnable+0
;Click_KnobG_STM.c,62 :: 		knobg_setOutputGain(_KNOBG_OUTPUT_GAIN_ALL_LED, _KNOBG_FULL_OUTPUT_CURRENT_GAIN);
MOVS	R1, #255
MOVS	R0, #64
BL	_knobg_setOutputGain+0
;Click_KnobG_STM.c,63 :: 		knobg_encoderNewStartPosition( 1 );
MOVS	R0, #1
BL	_knobg_encoderNewStartPosition+0
;Click_KnobG_STM.c,64 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_KnobG_STM.c,66 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_KnobG_STM.c,68 :: 		knobg_getEncoderPosition(&encoder_newPosition, &direction);
MOVW	R1, #lo_addr(_direction+0)
MOVT	R1, #hi_addr(_direction+0)
MOVW	R0, #lo_addr(_encoder_newPosition+0)
MOVT	R0, #hi_addr(_encoder_newPosition+0)
BL	_knobg_getEncoderPosition+0
;Click_KnobG_STM.c,70 :: 		if(knobg_getSWButtonState() == 0)
BL	_knobg_getSWButtonState+0
CMP	R0, #0
IT	NE
BNE	L_applicationTask4
;Click_KnobG_STM.c,72 :: 		SW_state++;
MOVW	R1, #lo_addr(_SW_State+0)
MOVT	R1, #hi_addr(_SW_State+0)
LDRB	R0, [R1, #0]
ADDS	R0, R0, #1
UXTB	R0, R0
STRB	R0, [R1, #0]
;Click_KnobG_STM.c,73 :: 		if(SW_State >= 3) SW_State = 0;
CMP	R0, #3
IT	CC
BCC	L_applicationTask5
MOVS	R1, #0
MOVW	R0, #lo_addr(_SW_State+0)
MOVT	R0, #hi_addr(_SW_State+0)
STRB	R1, [R0, #0]
L_applicationTask5:
;Click_KnobG_STM.c,75 :: 		knobg_setBrightness(_KNOBG_BRIGHTNESS_ALL_LED, 0x00);
MOVS	R1, #0
MOVS	R0, #48
BL	_knobg_setBrightness+0
;Click_KnobG_STM.c,76 :: 		Delay_ms( 300 );
MOVW	R7, #61055
MOVT	R7, #54
NOP
NOP
L_applicationTask6:
SUBS	R7, R7, #1
BNE	L_applicationTask6
NOP
NOP
NOP
;Click_KnobG_STM.c,77 :: 		}
L_applicationTask4:
;Click_KnobG_STM.c,80 :: 		if(encoder_newPosition != encoder_oldPosition)
MOVW	R0, #lo_addr(_encoder_oldPosition+0)
MOVT	R0, #hi_addr(_encoder_oldPosition+0)
LDR	R1, [R0, #0]
MOVW	R0, #lo_addr(_encoder_newPosition+0)
MOVT	R0, #hi_addr(_encoder_newPosition+0)
LDR	R0, [R0, #0]
CMP	R0, R1
IT	EQ
BEQ	L_applicationTask8
;Click_KnobG_STM.c,82 :: 		LongToStr(encoder_newPosition, demoText);
MOVW	R0, #lo_addr(_encoder_newPosition+0)
MOVT	R0, #hi_addr(_encoder_newPosition+0)
LDR	R0, [R0, #0]
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_LongToStr+0
;Click_KnobG_STM.c,83 :: 		mikrobus_logWrite(" EnCoder position : ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr2_Click_KnobG_STM+0)
MOVT	R0, #hi_addr(?lstr2_Click_KnobG_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_KnobG_STM.c,84 :: 		mikrobus_logWrite(demoText, _LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_KnobG_STM.c,85 :: 		}
L_applicationTask8:
;Click_KnobG_STM.c,86 :: 		encoder_oldPosition = encoder_newPosition;
MOVW	R0, #lo_addr(_encoder_newPosition+0)
MOVT	R0, #hi_addr(_encoder_newPosition+0)
LDR	R1, [R0, #0]
MOVW	R0, #lo_addr(_encoder_oldPosition+0)
MOVT	R0, #hi_addr(_encoder_oldPosition+0)
STR	R1, [R0, #0]
;Click_KnobG_STM.c,88 :: 		switch(SW_State)
IT	AL
BAL	L_applicationTask9
;Click_KnobG_STM.c,91 :: 		case 0:
L_applicationTask11:
;Click_KnobG_STM.c,93 :: 		cnt++;
MOVW	R1, #lo_addr(_cnt+0)
MOVT	R1, #hi_addr(_cnt+0)
LDRB	R0, [R1, #0]
ADDS	R0, R0, #1
UXTB	R0, R0
STRB	R0, [R1, #0]
;Click_KnobG_STM.c,94 :: 		if(cnt > 127) cnt = 0;
CMP	R0, #127
IT	LS
BLS	L_applicationTask12
MOVS	R1, #0
MOVW	R0, #lo_addr(_cnt+0)
MOVT	R0, #hi_addr(_cnt+0)
STRB	R1, [R0, #0]
L_applicationTask12:
;Click_KnobG_STM.c,95 :: 		knobg_setBrightness(_KNOBG_BRIGHTNESS_ALL_LED, cnt);
MOVW	R0, #lo_addr(_cnt+0)
MOVT	R0, #hi_addr(_cnt+0)
LDRB	R0, [R0, #0]
UXTB	R1, R0
MOVS	R0, #48
BL	_knobg_setBrightness+0
;Click_KnobG_STM.c,96 :: 		Delay_ms( 15 );
MOVW	R7, #48927
MOVT	R7, #2
NOP
NOP
L_applicationTask13:
SUBS	R7, R7, #1
BNE	L_applicationTask13
NOP
NOP
NOP
;Click_KnobG_STM.c,97 :: 		break;
IT	AL
BAL	L_applicationTask10
;Click_KnobG_STM.c,100 :: 		case 1:
L_applicationTask15:
;Click_KnobG_STM.c,102 :: 		if(encoder_newPosition > 24) knobg_encoderNewStartPosition( 1 );
MOVW	R0, #lo_addr(_encoder_newPosition+0)
MOVT	R0, #hi_addr(_encoder_newPosition+0)
LDR	R0, [R0, #0]
CMP	R0, #24
IT	LE
BLE	L_applicationTask16
MOVS	R0, #1
BL	_knobg_encoderNewStartPosition+0
L_applicationTask16:
;Click_KnobG_STM.c,103 :: 		if(encoder_newPosition < 1) knobg_encoderNewStartPosition( 24 );
MOVW	R0, #lo_addr(_encoder_newPosition+0)
MOVT	R0, #hi_addr(_encoder_newPosition+0)
LDR	R0, [R0, #0]
CMP	R0, #1
IT	GE
BGE	L_applicationTask17
MOVS	R0, #24
BL	_knobg_encoderNewStartPosition+0
L_applicationTask17:
;Click_KnobG_STM.c,105 :: 		if(direction == 1)
MOVW	R0, #lo_addr(_direction+0)
MOVT	R0, #hi_addr(_direction+0)
LDRB	R0, [R0, #0]
CMP	R0, #1
IT	NE
BNE	L_applicationTask18
;Click_KnobG_STM.c,107 :: 		knobg_setLedState(encoder_newPosition, _KNOBG_LED_ON);
MOVW	R0, #lo_addr(_encoder_newPosition+0)
MOVT	R0, #hi_addr(_encoder_newPosition+0)
LDR	R0, [R0, #0]
MOVS	R1, #255
BL	_knobg_setLedState+0
;Click_KnobG_STM.c,108 :: 		knobg_setLedState(encoder_newPosition - 1, _KNOBG_LED_OFF);
MOVW	R0, #lo_addr(_encoder_newPosition+0)
MOVT	R0, #hi_addr(_encoder_newPosition+0)
LDR	R0, [R0, #0]
SUBS	R0, R0, #1
MOVS	R1, #0
UXTB	R0, R0
BL	_knobg_setLedState+0
;Click_KnobG_STM.c,109 :: 		}
IT	AL
BAL	L_applicationTask19
L_applicationTask18:
;Click_KnobG_STM.c,112 :: 		knobg_setLedState(encoder_newPosition, _KNOBG_LED_ON);
MOVW	R0, #lo_addr(_encoder_newPosition+0)
MOVT	R0, #hi_addr(_encoder_newPosition+0)
LDR	R0, [R0, #0]
MOVS	R1, #255
BL	_knobg_setLedState+0
;Click_KnobG_STM.c,113 :: 		knobg_setLedState(encoder_newPosition + 1, _KNOBG_LED_OFF);
MOVW	R0, #lo_addr(_encoder_newPosition+0)
MOVT	R0, #hi_addr(_encoder_newPosition+0)
LDR	R0, [R0, #0]
ADDS	R0, R0, #1
MOVS	R1, #0
UXTB	R0, R0
BL	_knobg_setLedState+0
;Click_KnobG_STM.c,114 :: 		}
L_applicationTask19:
;Click_KnobG_STM.c,115 :: 		Delay_1ms();
BL	_Delay_1ms+0
;Click_KnobG_STM.c,116 :: 		break;
IT	AL
BAL	L_applicationTask10
;Click_KnobG_STM.c,119 :: 		case 2:
L_applicationTask20:
;Click_KnobG_STM.c,121 :: 		if(encoder_newPosition > 24) knobg_encoderNewStartPosition( 1 );
MOVW	R0, #lo_addr(_encoder_newPosition+0)
MOVT	R0, #hi_addr(_encoder_newPosition+0)
LDR	R0, [R0, #0]
CMP	R0, #24
IT	LE
BLE	L_applicationTask21
MOVS	R0, #1
BL	_knobg_encoderNewStartPosition+0
L_applicationTask21:
;Click_KnobG_STM.c,122 :: 		if(encoder_newPosition < 1) knobg_encoderNewStartPosition( 24 );
MOVW	R0, #lo_addr(_encoder_newPosition+0)
MOVT	R0, #hi_addr(_encoder_newPosition+0)
LDR	R0, [R0, #0]
CMP	R0, #1
IT	GE
BGE	L_applicationTask22
MOVS	R0, #24
BL	_knobg_encoderNewStartPosition+0
L_applicationTask22:
;Click_KnobG_STM.c,124 :: 		if(direction == 1)
MOVW	R0, #lo_addr(_direction+0)
MOVT	R0, #hi_addr(_direction+0)
LDRB	R0, [R0, #0]
CMP	R0, #1
IT	NE
BNE	L_applicationTask23
;Click_KnobG_STM.c,126 :: 		knobg_setLedState(encoder_newPosition, _KNOBG_LED_ON);
MOVW	R0, #lo_addr(_encoder_newPosition+0)
MOVT	R0, #hi_addr(_encoder_newPosition+0)
LDR	R0, [R0, #0]
MOVS	R1, #255
BL	_knobg_setLedState+0
;Click_KnobG_STM.c,127 :: 		}
IT	AL
BAL	L_applicationTask24
L_applicationTask23:
;Click_KnobG_STM.c,130 :: 		knobg_setLedState(encoder_newPosition + 1, _KNOBG_LED_OFF);
MOVW	R0, #lo_addr(_encoder_newPosition+0)
MOVT	R0, #hi_addr(_encoder_newPosition+0)
LDR	R0, [R0, #0]
ADDS	R0, R0, #1
MOVS	R1, #0
UXTB	R0, R0
BL	_knobg_setLedState+0
;Click_KnobG_STM.c,131 :: 		}
L_applicationTask24:
;Click_KnobG_STM.c,132 :: 		Delay_1ms();
BL	_Delay_1ms+0
;Click_KnobG_STM.c,133 :: 		break;
IT	AL
BAL	L_applicationTask10
;Click_KnobG_STM.c,135 :: 		}
L_applicationTask9:
MOVW	R0, #lo_addr(_SW_State+0)
MOVT	R0, #hi_addr(_SW_State+0)
LDRB	R0, [R0, #0]
CMP	R0, #0
IT	EQ
BEQ	L_applicationTask11
MOVW	R0, #lo_addr(_SW_State+0)
MOVT	R0, #hi_addr(_SW_State+0)
LDRB	R0, [R0, #0]
CMP	R0, #1
IT	EQ
BEQ	L_applicationTask15
MOVW	R0, #lo_addr(_SW_State+0)
MOVT	R0, #hi_addr(_SW_State+0)
LDRB	R0, [R0, #0]
CMP	R0, #2
IT	EQ
BEQ	L_applicationTask20
L_applicationTask10:
;Click_KnobG_STM.c,136 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_KnobG_STM.c,139 :: 		void main()
;Click_KnobG_STM.c,141 :: 		systemInit();
BL	_systemInit+0
;Click_KnobG_STM.c,142 :: 		applicationInit();
BL	_applicationInit+0
;Click_KnobG_STM.c,144 :: 		while (1)
L_main25:
;Click_KnobG_STM.c,146 :: 		applicationTask();
BL	_applicationTask+0
;Click_KnobG_STM.c,147 :: 		}
IT	AL
BAL	L_main25
;Click_KnobG_STM.c,148 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
