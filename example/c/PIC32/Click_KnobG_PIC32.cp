#line 1 "D:/Clicks_git/K/Knob_G_Click/SW/example/c/PIC32/Click_KnobG_PIC32.c"
#line 19 "D:/Clicks_git/K/Knob_G_Click/SW/example/c/PIC32/Click_KnobG_PIC32.c"
signed short dir, pos, prevpos;
unsigned short _data, _cmdreg, mode, bkg;

bit stateOldRotate, stateNewRotate, startStatus;

sbit OE at LATD.B0;
sbit RST at LATC.B1;

sbit SW_pin at PORTE.B8;
sbit ENA at PORTB.B8;
sbit ENB at PORTC.B2;

unsigned short i, val;

void MCU_Init()
{
 CHECON = 0x32;
 AD1PCFG = 0xFFFFFFFF;
 JTAGEN_bit = 0;


 TRISD0_bit = 0;
 TRISC1_bit = 0;
 TRISE8_bit = 1;
 TRISB8_bit = 1;
 TRISC2_bit = 1;

 TRISD0_bit = 0;
 TRISE3_bit = 0;
 TRISB2_bit = 0;
 TRISA10_bit = 0;

 LATA10_bit = 0;
 TRISD4_bit = 0;
 LATE3_bit = 0;

 I2C2_Init(400000);
}

void TW_Wr(unsigned short _cmdreg, unsigned short _data)
{
 I2C2_Start();
 I2C2_Write( 0xE0 );
 I2C2_Write(_cmdreg);
 I2C2_Write(_data);
 I2C2_Stop();
}

void Rst_Chip()
{
 RST = 0;
 Delay_ms(10);
 RST = 1;
 i=0, pos = 0, prevpos, dir = 0, bkg = 0;
 stateOldRotate = 1;
 I2C2_Write(0x00);
 I2C2_Write(0x06);
 Delay_ms(10);
 TW_Wr(0x40, 0xFF);
}

void main()
{
 MCU_Init();
 Rst_Chip();

 OE = 0;
 val = 0x00;
 mode = 10;

 while (1)
 {
 if (SW_pin != 0)
 {

 }


 if ( ENA == ENB )
 {
 stateOldRotate = 0;
 startStatus = ENA && ENB;
 }
 else
 {
 stateNewRotate = 1;
 if ( stateNewRotate != stateOldRotate )
 {
 stateOldRotate = 1;
 if ( startStatus == ENA )
 {
 dir = 1;
 prevpos = pos;
 pos++;
 if (pos > 24)
 {
 pos = 1;
 }
 }
 else
 {
 dir = -1;
 prevpos = pos;
 pos--;
 if (pos < 1)
 {
 pos = 24;
 }
 }
 }
 }

 if (dir == 0)
 {
 pos = 1;
 TW_Wr(0x09 + pos, 0xFF);
 }
 else if (dir > 0)
 {
 TW_Wr(0x09 + pos, 0xFF);
 TW_Wr(0x09 + prevpos, 0x00);
 }
 else if (dir < 0)
 {
 TW_Wr(0x09 + pos, 0xFF);
 TW_Wr(0x09 + prevpos, 0x00);
 }
 }
}
