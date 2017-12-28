/* ************************************************************************
 *
 *   global functions
 *
 *   (c) 2012-2017 by Markus Reschke
 *   based on code from Markus Frejek and Karl-Heinz K�bbeler
 *
 * ************************************************************************ */


/*
 *  In each source file we create a local ID definition. If the ID definition
 *  is unset we may import functions of that specific source file.
 */

/* ************************************************************************
 *   functions from main.c
 * ************************************************************************ */

#ifndef MAIN_C

  extern void Show_SemiPinout(uint8_t A, uint8_t B, uint8_t C);
  extern void Show_SimplePinout(uint8_t ID_1, uint8_t ID_2, uint8_t ID_3);

#endif


/* ************************************************************************
 *   functions from LCD module specific driver
 * ************************************************************************ */

#ifndef LCD_DRIVER_C

  extern void LCD_BusSetup(void);
  extern void LCD_Init(void);
  extern void LCD_ClearLine(uint8_t Line);
  extern void LCD_Clear(void);
  extern void LCD_CharPos(uint8_t x, uint8_t y);
  extern void LCD_Cursor(uint8_t Mode);
  extern void LCD_Char(unsigned char Char);

  #ifdef SW_CONTRAST
    extern void LCD_Contrast(uint8_t Contrast);
  #endif

  #ifdef SW_SYMBOLS
    extern void LCD_FancySemiPinout(void);
  #endif

#endif


/* ************************************************************************
 *   functions from SPI.c
 * ************************************************************************ */

#ifndef SPI_C

  #ifdef HW_SPI
    #ifdef SPI_HARDWARE
      extern void SPI_Clock(void);
    #endif
    extern void SPI_Setup(void);
    extern void SPI_Write_Byte(uint8_t Byte);
    #ifdef SPI_MISO
      extern uint8_t SPI_WriteRead_Byte(uint8_t Byte);
    #endif
  #endif

#endif


/* ************************************************************************
 *   functions from I2C.c
 * ************************************************************************ */

#ifndef I2C_C

  #ifdef HW_I2C
    extern uint8_t I2C_Setup(void);
    extern uint8_t I2C_Start(uint8_t Type);
    extern uint8_t I2C_WriteByte(uint8_t Type);
    extern void I2C_Stop(void);
  #endif

#endif


/* ************************************************************************
 *   functions from touchscreen specific driver
 * ************************************************************************ */

#ifndef TOUCH_DRIVER_C

  #ifdef HW_TOUCH
    extern void Touch_BusSetup(void);
    extern void Touch_Init(void);
    extern uint8_t Touch_Check(void);
    extern uint8_t Touch_Adjust(void);
  #endif

#endif


/* ************************************************************************
 *   functions from display.c
 * ************************************************************************ */

#ifndef DISPLAY_C

  extern void LCD_EEString(const unsigned char *String);
  extern void LCD_EEString_Space(const unsigned char *String);
  extern void LCD_ProbeNumber(uint8_t Probe);

  extern void LCD_ClearLine2(void);
  extern void LCD_Space(void);

  extern void LCD_NextLine(void);
  extern void LCD_NextLine_Mode(uint8_t Mode);
  extern void LCD_NextLine_EEString(const unsigned char *String);
  extern void LCD_NextLine_EEString_Space(const unsigned char *String);

#endif


/* ************************************************************************
 *   functions from pause.c
 * ************************************************************************ */

#ifndef PAUSE_C

  extern void MilliSleep(uint16_t Time);

#endif


/* ************************************************************************
 *   functions from adjust.c
 * ************************************************************************ */

#ifndef ADJUST_C

  extern void SetAdjustmentDefaults(void);
  extern void ManageAdjustmentStorage(uint8_t Mode, uint8_t ID);

  extern void ShowAdjustmentValues(void);
  extern uint8_t SelfAdjustment(void);

  extern uint8_t SelfTest(void);

#endif


/* ************************************************************************
 *   functions from user.c
 * ************************************************************************ */

#ifndef USER_C

  extern int8_t CmpValue(uint32_t Value1, int8_t Scale1,
    uint32_t Value2, int8_t Scale2);
  extern uint32_t RescaleValue(uint32_t Value, int8_t Scale, int8_t NewScale);

  #if defined (SW_SQUAREWAVE) || defined (SW_PWM_PLUS) || defined (HW_FREQ_COUNTER_EXT) || defined (SW_SERVO)
    extern void DisplayFullValue(uint32_t Value, uint8_t DecPlaces, unsigned char Unit);
  #endif

  extern void DisplayValue(uint32_t Value, int8_t Exponent, unsigned char Unit);
  extern void DisplaySignedValue(int32_t Value, int8_t Exponent, unsigned char Unit);

  extern uint8_t TestKey(uint16_t Timeout, uint8_t Mode);
  extern void WaitKey(void);
  extern int8_t ShortCircuit(uint8_t Mode);
  extern void MainMenu(void);

#endif


/* ************************************************************************
 *   functions from IR.c
 * ************************************************************************ */

#ifndef IR_C

  #ifdef SW_IR_RECEIVER
    extern void IR_Detector(void);
  #endif

#endif


/* ************************************************************************
 *   functions from extras.c
 * ************************************************************************ */

#ifndef EXTRAS_C

  #ifdef SW_PWM_SIMPLE
    extern void PWM_Tool(uint16_t Frequency);
  #endif
  #ifdef SW_PWM_PLUS
    extern void PWM_Tool(void);
  #endif
  #ifdef SW_SERVO
    extern void Servo_Check(void);
  #endif
  #ifdef SW_SQUAREWAVE
    extern void SquareWave_SignalGenerator(void);
  #endif
  #if defined (SW_ESR) || defined (SW_OLD_ESR)
    extern void ESR_Tool(void);
  #endif
  #ifdef HW_ZENER
    extern void Zener_Tool(void);
  #endif
  #ifdef HW_FREQ_COUNTER
    extern void FrequencyCounter(void);
  #endif
  #ifdef SW_ENCODER
    extern void Encoder_Tool(void);
  #endif
  #ifdef SW_OPTO_COUPLER
    extern void OptoCoupler_Tool(void);
  #endif

#endif


/* ************************************************************************
 *   functions from semi.c
 * ************************************************************************ */

#ifndef SEMI_C

  extern void GetGateThreshold(uint8_t Type);
  extern uint32_t Get_hfe_c(uint8_t Type);
  extern void GetLeakageCurrent(uint8_t Mode);

  extern Diode_Type *SearchDiode(uint8_t A, uint8_t C);
  extern void CheckDiode(void);

  extern void VerifyMOSFET(void);
  extern void CheckTransistor(uint8_t BJT_Type, uint16_t U_Rl);
  extern void CheckDepletionModeFET(uint16_t U_Rl);

  extern uint8_t CheckThyristorTriac(void);
  extern void CheckPUT(void);

  #ifdef SW_UJT
    extern void CheckUJT(void);
  #endif

#endif


/* ************************************************************************
 *   functions from resistor.c
 * ************************************************************************ */

#ifndef RESISTOR_C

  extern uint16_t SmallResistor(uint8_t ZeroFlag);
  extern void CheckResistor(void);
  extern uint8_t CheckSingleResistor(uint8_t HighPin, uint8_t LowPin, uint8_t Max);

#endif


/* ************************************************************************
 *   functions from inductor.c
 * ************************************************************************ */

#ifndef INDUCTOR_C

  #ifdef SW_INDUCTOR
    extern uint8_t MeasureInductor(Resistor_Type *Resistor);
  #endif

#endif


/* ************************************************************************
 *   functions from cap.c
 * ************************************************************************ */

#ifndef CAP_C

  #if defined (SW_ESR) || defined (SW_OLD_ESR)
    extern uint16_t MeasureESR(Capacitor_Type *Cap);
  #endif

  extern void MeasureCap(uint8_t Probe1, uint8_t Probe2, uint8_t ID);

  #ifdef HW_ADJUST_CAP
    extern uint8_t RefCap(void);
  #endif

#endif


/* ************************************************************************
 *   functions from probes.c
 * ************************************************************************ */

#ifndef PROBES_C

  extern void UpdateProbes(uint8_t Probe1, uint8_t Probe2, uint8_t Probe3);
  extern void RestoreProbes(void);
  extern void BackupProbes(void);
  extern uint8_t GetThirdProbe(uint8_t Probe1, uint8_t Probe2);
  extern uint8_t ShortedProbes(uint8_t Probe1, uint8_t Probe2);
  extern uint8_t AllProbesShorted(void);
  extern void DischargeProbes(void);
  extern void PullProbe(uint8_t Probe, uint8_t Mode);
  extern uint16_t GetFactor(uint16_t U_in, uint8_t ID);

  extern void CheckProbes(uint8_t Probe1, uint8_t Probe2, uint8_t Probe3);
  extern void CheckAlternatives(void);

#endif


/* ************************************************************************
 *   functions from ADC.c
 * ************************************************************************ */

#ifndef ADC_C

  extern uint16_t ReadU(uint8_t Probe);

  extern uint16_t ReadU_5ms(uint8_t Probe);
  extern uint16_t ReadU_20ms(uint8_t Probe);

#endif


/* ************************************************************************
 *   functions from wait.S
 * ************************************************************************ */

#ifndef WAIT_S

  /* clock frequency >= 1 MHz */
  extern void wait5s(void);
  extern void wait4s(void);
  extern void wait3s(void);
  extern void wait2s(void);
  extern void wait1s(void);
  extern void wait1000ms(void);
  extern void wait500ms(void);
  extern void wait400ms(void);
  extern void wait300ms(void);
  extern void wait200ms(void);
  extern void wait100ms(void);
  extern void wait50ms(void);
  extern void wait40ms(void);
  extern void wait30ms(void);
  extern void wait20ms(void);
  extern void wait10ms(void);
  extern void wait5ms(void);
  extern void wait4ms(void);
  extern void wait3ms(void);
  extern void wait2ms(void);
  extern void wait1ms(void);
  extern void wait500us(void);
  extern void wait400us(void);
  extern void wait300us(void);
  extern void wait200us(void);
  extern void wait100us(void);
  extern void wait50us(void);
  extern void wait40us(void);
  extern void wait30us(void);
  extern void wait20us(void);
  extern void wait10us(void);

  /* clock frequency >= 2 MHz */
  extern void wait5us(void);

  /* clock frequency >= 4 MHz */
  extern void wait4us(void);
  extern void wait3us(void);
  extern void wait2us(void);

  /* clock frequency >= 8 MHz */
  extern void wait1us(void);

#endif


/* ************************************************************************
 *   EOF
 * ************************************************************************ */