_MCU_Init:
;Click_KnobG_PIC32.c,33 :: 		void MCU_Init()
ADDIU	SP, SP, -8
SW	RA, 0(SP)
;Click_KnobG_PIC32.c,35 :: 		CHECON = 0x32;
SW	R25, 4(SP)
ORI	R2, R0, 50
SW	R2, Offset(CHECON+0)(GP)
;Click_KnobG_PIC32.c,36 :: 		AD1PCFG      = 0xFFFFFFFF;
LUI	R2, 65535
ORI	R2, R2, 65535
SW	R2, Offset(AD1PCFG+0)(GP)
;Click_KnobG_PIC32.c,37 :: 		JTAGEN_bit   = 0;
_LX	
INS	R2, R0, BitPos(JTAGEN_bit+0), 1
_SX	
;Click_KnobG_PIC32.c,40 :: 		TRISD0_bit   = 0;
LUI	R2, BitMask(TRISD0_bit+0)
ORI	R2, R2, BitMask(TRISD0_bit+0)
_SX	
;Click_KnobG_PIC32.c,41 :: 		TRISC1_bit   = 0;
LUI	R2, BitMask(TRISC1_bit+0)
ORI	R2, R2, BitMask(TRISC1_bit+0)
_SX	
;Click_KnobG_PIC32.c,42 :: 		TRISE8_bit   = 1;
LUI	R2, BitMask(TRISE8_bit+0)
ORI	R2, R2, BitMask(TRISE8_bit+0)
_SX	
;Click_KnobG_PIC32.c,43 :: 		TRISB8_bit  = 1;
LUI	R2, BitMask(TRISB8_bit+0)
ORI	R2, R2, BitMask(TRISB8_bit+0)
_SX	
;Click_KnobG_PIC32.c,44 :: 		TRISC2_bit   = 1;
LUI	R2, BitMask(TRISC2_bit+0)
ORI	R2, R2, BitMask(TRISC2_bit+0)
_SX	
;Click_KnobG_PIC32.c,46 :: 		TRISD0_bit   = 0;
LUI	R2, BitMask(TRISD0_bit+0)
ORI	R2, R2, BitMask(TRISD0_bit+0)
_SX	
;Click_KnobG_PIC32.c,47 :: 		TRISE3_bit   = 0;
LUI	R2, BitMask(TRISE3_bit+0)
ORI	R2, R2, BitMask(TRISE3_bit+0)
_SX	
;Click_KnobG_PIC32.c,48 :: 		TRISB2_bit   = 0;
LUI	R2, BitMask(TRISB2_bit+0)
ORI	R2, R2, BitMask(TRISB2_bit+0)
_SX	
;Click_KnobG_PIC32.c,49 :: 		TRISA10_bit  = 0;
LUI	R2, BitMask(TRISA10_bit+0)
ORI	R2, R2, BitMask(TRISA10_bit+0)
_SX	
;Click_KnobG_PIC32.c,51 :: 		LATA10_bit   = 0;
LUI	R2, BitMask(LATA10_bit+0)
ORI	R2, R2, BitMask(LATA10_bit+0)
_SX	
;Click_KnobG_PIC32.c,52 :: 		TRISD4_bit   = 0;
LUI	R2, BitMask(TRISD4_bit+0)
ORI	R2, R2, BitMask(TRISD4_bit+0)
_SX	
;Click_KnobG_PIC32.c,53 :: 		LATE3_bit    = 0;
LUI	R2, BitMask(LATE3_bit+0)
ORI	R2, R2, BitMask(LATE3_bit+0)
_SX	
;Click_KnobG_PIC32.c,55 :: 		I2C2_Init(400000);
LUI	R25, 6
ORI	R25, R25, 6784
JAL	_I2C2_Init+0
NOP	
;Click_KnobG_PIC32.c,56 :: 		}
L_end_MCU_Init:
LW	R25, 4(SP)
LW	RA, 0(SP)
ADDIU	SP, SP, 8
JR	RA
NOP	
; end of _MCU_Init
_TW_Wr:
;Click_KnobG_PIC32.c,58 :: 		void TW_Wr(unsigned short _cmdreg, unsigned short _data)
ADDIU	SP, SP, -12
SW	RA, 0(SP)
;Click_KnobG_PIC32.c,60 :: 		I2C2_Start();
SW	R25, 4(SP)
SB	R26, 8(SP)
SB	R25, 9(SP)
JAL	_I2C2_Start+0
NOP	
;Click_KnobG_PIC32.c,61 :: 		I2C2_Write(I2C_SLAVEADDR_W);
ORI	R25, R0, 224
JAL	_I2C2_Write+0
NOP	
LBU	R25, 9(SP)
;Click_KnobG_PIC32.c,62 :: 		I2C2_Write(_cmdreg);
JAL	_I2C2_Write+0
NOP	
LBU	R26, 8(SP)
;Click_KnobG_PIC32.c,63 :: 		I2C2_Write(_data);
ANDI	R25, R26, 255
JAL	_I2C2_Write+0
NOP	
;Click_KnobG_PIC32.c,64 :: 		I2C2_Stop();
JAL	_I2C2_Stop+0
NOP	
;Click_KnobG_PIC32.c,65 :: 		}
L_end_TW_Wr:
LW	R25, 4(SP)
LW	RA, 0(SP)
ADDIU	SP, SP, 12
JR	RA
NOP	
; end of _TW_Wr
_Rst_Chip:
;Click_KnobG_PIC32.c,67 :: 		void Rst_Chip()
ADDIU	SP, SP, -12
SW	RA, 0(SP)
;Click_KnobG_PIC32.c,69 :: 		RST = 0;
SW	R25, 4(SP)
SW	R26, 8(SP)
ORI	R2, R0, 2
SW	R2, Offset(LATC+4)(GP)
;Click_KnobG_PIC32.c,70 :: 		Delay_ms(10);
LUI	R24, 4
ORI	R24, R24, 4522
L_Rst_Chip0:
ADDIU	R24, R24, -1
BNE	R24, R0, L_Rst_Chip0
NOP	
;Click_KnobG_PIC32.c,71 :: 		RST = 1;
ORI	R2, R0, 2
SW	R2, Offset(LATC+8)(GP)
;Click_KnobG_PIC32.c,72 :: 		i=0, pos = 0, prevpos, dir = 0, bkg = 0;
SB	R0, Offset(_i+0)(GP)
SB	R0, Offset(_pos+0)(GP)
SB	R0, Offset(_dir+0)(GP)
SB	R0, Offset(_bkg+0)(GP)
;Click_KnobG_PIC32.c,73 :: 		stateOldRotate = 1;
LBU	R2, Offset(_stateOldRotate+0)(GP)
ORI	R2, R2, BitMask(_stateOldRotate+0)
SB	R2, Offset(_stateOldRotate+0)(GP)
;Click_KnobG_PIC32.c,74 :: 		I2C2_Write(0x00);
MOVZ	R25, R0, R0
JAL	_I2C2_Write+0
NOP	
;Click_KnobG_PIC32.c,75 :: 		I2C2_Write(0x06);
ORI	R25, R0, 6
JAL	_I2C2_Write+0
NOP	
;Click_KnobG_PIC32.c,76 :: 		Delay_ms(10);
LUI	R24, 4
ORI	R24, R24, 4522
L_Rst_Chip2:
ADDIU	R24, R24, -1
BNE	R24, R0, L_Rst_Chip2
NOP	
;Click_KnobG_PIC32.c,77 :: 		TW_Wr(0x40, 0xFF);
ORI	R26, R0, 255
ORI	R25, R0, 64
JAL	_TW_Wr+0
NOP	
;Click_KnobG_PIC32.c,78 :: 		}
L_end_Rst_Chip:
LW	R26, 8(SP)
LW	R25, 4(SP)
LW	RA, 0(SP)
ADDIU	SP, SP, 12
JR	RA
NOP	
; end of _Rst_Chip
_main:
;Click_KnobG_PIC32.c,80 :: 		void main()
;Click_KnobG_PIC32.c,82 :: 		MCU_Init();
JAL	_MCU_Init+0
NOP	
;Click_KnobG_PIC32.c,83 :: 		Rst_Chip();
JAL	_Rst_Chip+0
NOP	
;Click_KnobG_PIC32.c,85 :: 		OE = 0;
ORI	R2, R0, 1
SW	R2, Offset(LATD+4)(GP)
;Click_KnobG_PIC32.c,86 :: 		val = 0x00;
SB	R0, Offset(_val+0)(GP)
;Click_KnobG_PIC32.c,87 :: 		mode = 10;
ORI	R2, R0, 10
SB	R2, Offset(_mode+0)(GP)
;Click_KnobG_PIC32.c,89 :: 		while (1)
L_main4:
;Click_KnobG_PIC32.c,91 :: 		if (SW_pin != 0)
LBU	R2, Offset(PORTE+1)(GP)
EXT	R2, R2, 0, 1
BNE	R2, R0, L__main26
NOP	
J	L_main6
NOP	
L__main26:
;Click_KnobG_PIC32.c,94 :: 		}
L_main6:
;Click_KnobG_PIC32.c,97 :: 		if ( ENA == ENB )
LBU	R2, Offset(PORTC+0)(GP)
EXT	R3, R2, 2, 1
LBU	R2, Offset(PORTB+1)(GP)
EXT	R2, R2, 0, 1
BEQ	R2, R3, L__main27
NOP	
J	L_main7
NOP	
L__main27:
;Click_KnobG_PIC32.c,99 :: 		stateOldRotate = 0;
LBU	R2, Offset(_stateOldRotate+0)(GP)
INS	R2, R0, BitPos(_stateOldRotate+0), 1
SB	R2, Offset(_stateOldRotate+0)(GP)
;Click_KnobG_PIC32.c,100 :: 		startStatus = ENA && ENB;
LBU	R2, Offset(PORTB+1)(GP)
EXT	R2, R2, 0, 1
BNE	R2, R0, L__main29
NOP	
J	L_main9
NOP	
L__main29:
LBU	R2, Offset(PORTC+0)(GP)
EXT	R2, R2, 2, 1
BNE	R2, R0, L__main31
NOP	
J	L_main9
NOP	
L__main31:
ORI	R3, R0, 1
J	L_main8
NOP	
L_main9:
MOVZ	R3, R0, R0
L_main8:
LBU	R2, Offset(_startStatus+0)(GP)
INS	R2, R3, BitPos(_startStatus+0), 1
SB	R2, Offset(_startStatus+0)(GP)
;Click_KnobG_PIC32.c,101 :: 		}
J	L_main10
NOP	
L_main7:
;Click_KnobG_PIC32.c,104 :: 		stateNewRotate = 1;
LBU	R2, Offset(_stateNewRotate+0)(GP)
ORI	R2, R2, BitMask(_stateNewRotate+0)
SB	R2, Offset(_stateNewRotate+0)(GP)
;Click_KnobG_PIC32.c,105 :: 		if ( stateNewRotate != stateOldRotate )
LBU	R2, Offset(_stateOldRotate+0)(GP)
EXT	R3, R2, BitPos(_stateOldRotate+0), 1
LBU	R2, Offset(_stateNewRotate+0)(GP)
EXT	R2, R2, BitPos(_stateNewRotate+0), 1
BNE	R2, R3, L__main33
NOP	
J	L_main11
NOP	
L__main33:
;Click_KnobG_PIC32.c,107 :: 		stateOldRotate = 1;
LBU	R2, Offset(_stateOldRotate+0)(GP)
ORI	R2, R2, BitMask(_stateOldRotate+0)
SB	R2, Offset(_stateOldRotate+0)(GP)
;Click_KnobG_PIC32.c,108 :: 		if ( startStatus == ENA )
LBU	R2, Offset(PORTB+1)(GP)
EXT	R3, R2, 0, 1
LBU	R2, Offset(_startStatus+0)(GP)
EXT	R2, R2, BitPos(_startStatus+0), 1
BEQ	R2, R3, L__main34
NOP	
J	L_main12
NOP	
L__main34:
;Click_KnobG_PIC32.c,110 :: 		dir = 1;
ORI	R2, R0, 1
SB	R2, Offset(_dir+0)(GP)
;Click_KnobG_PIC32.c,111 :: 		prevpos = pos;
LB	R2, Offset(_pos+0)(GP)
SB	R2, Offset(_prevpos+0)(GP)
;Click_KnobG_PIC32.c,112 :: 		pos++;
LB	R2, Offset(_pos+0)(GP)
ADDIU	R2, R2, 1
SB	R2, Offset(_pos+0)(GP)
;Click_KnobG_PIC32.c,113 :: 		if (pos > 24)
SEB	R2, R2
SLTI	R2, R2, 25
BEQ	R2, R0, L__main35
NOP	
J	L_main13
NOP	
L__main35:
;Click_KnobG_PIC32.c,115 :: 		pos = 1;
ORI	R2, R0, 1
SB	R2, Offset(_pos+0)(GP)
;Click_KnobG_PIC32.c,116 :: 		}
L_main13:
;Click_KnobG_PIC32.c,117 :: 		}
J	L_main14
NOP	
L_main12:
;Click_KnobG_PIC32.c,120 :: 		dir = -1;
ORI	R2, R0, 255
SB	R2, Offset(_dir+0)(GP)
;Click_KnobG_PIC32.c,121 :: 		prevpos = pos;
LB	R2, Offset(_pos+0)(GP)
SB	R2, Offset(_prevpos+0)(GP)
;Click_KnobG_PIC32.c,122 :: 		pos--;
LB	R2, Offset(_pos+0)(GP)
ADDIU	R2, R2, -1
SB	R2, Offset(_pos+0)(GP)
;Click_KnobG_PIC32.c,123 :: 		if (pos < 1)
SEB	R2, R2
SLTI	R2, R2, 1
BNE	R2, R0, L__main36
NOP	
J	L_main15
NOP	
L__main36:
;Click_KnobG_PIC32.c,125 :: 		pos = 24;
ORI	R2, R0, 24
SB	R2, Offset(_pos+0)(GP)
;Click_KnobG_PIC32.c,126 :: 		}
L_main15:
;Click_KnobG_PIC32.c,127 :: 		}
L_main14:
;Click_KnobG_PIC32.c,128 :: 		}
L_main11:
;Click_KnobG_PIC32.c,129 :: 		}
L_main10:
;Click_KnobG_PIC32.c,131 :: 		if (dir == 0)
LB	R2, Offset(_dir+0)(GP)
BEQ	R2, R0, L__main37
NOP	
J	L_main16
NOP	
L__main37:
;Click_KnobG_PIC32.c,133 :: 		pos = 1;
ORI	R2, R0, 1
SB	R2, Offset(_pos+0)(GP)
;Click_KnobG_PIC32.c,134 :: 		TW_Wr(0x09 + pos, 0xFF);
ORI	R26, R0, 255
ORI	R25, R0, 10
JAL	_TW_Wr+0
NOP	
;Click_KnobG_PIC32.c,135 :: 		}
J	L_main17
NOP	
L_main16:
;Click_KnobG_PIC32.c,136 :: 		else if (dir > 0)
LB	R2, Offset(_dir+0)(GP)
SLTI	R2, R2, 1
BEQ	R2, R0, L__main38
NOP	
J	L_main18
NOP	
L__main38:
;Click_KnobG_PIC32.c,138 :: 		TW_Wr(0x09 + pos, 0xFF);
LB	R2, Offset(_pos+0)(GP)
ADDIU	R2, R2, 9
ORI	R26, R0, 255
ANDI	R25, R2, 255
JAL	_TW_Wr+0
NOP	
;Click_KnobG_PIC32.c,139 :: 		TW_Wr(0x09 + prevpos, 0x00);
LB	R2, Offset(_prevpos+0)(GP)
ADDIU	R2, R2, 9
MOVZ	R26, R0, R0
ANDI	R25, R2, 255
JAL	_TW_Wr+0
NOP	
;Click_KnobG_PIC32.c,140 :: 		}
J	L_main19
NOP	
L_main18:
;Click_KnobG_PIC32.c,141 :: 		else if (dir < 0)
LB	R2, Offset(_dir+0)(GP)
SLTI	R2, R2, 0
BNE	R2, R0, L__main39
NOP	
J	L_main20
NOP	
L__main39:
;Click_KnobG_PIC32.c,143 :: 		TW_Wr(0x09 + pos, 0xFF);
LB	R2, Offset(_pos+0)(GP)
ADDIU	R2, R2, 9
ORI	R26, R0, 255
ANDI	R25, R2, 255
JAL	_TW_Wr+0
NOP	
;Click_KnobG_PIC32.c,144 :: 		TW_Wr(0x09 + prevpos, 0x00);
LB	R2, Offset(_prevpos+0)(GP)
ADDIU	R2, R2, 9
MOVZ	R26, R0, R0
ANDI	R25, R2, 255
JAL	_TW_Wr+0
NOP	
;Click_KnobG_PIC32.c,145 :: 		}
L_main20:
L_main19:
L_main17:
;Click_KnobG_PIC32.c,146 :: 		}
J	L_main4
NOP	
;Click_KnobG_PIC32.c,147 :: 		}
L_end_main:
L__main_end_loop:
J	L__main_end_loop
NOP	
; end of _main
