//================These source code run on Arduino Mega or Mega2560
#include "main.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x26, 16, 2);
unsigned long TimerDebug ;
FLAG flag ;


bool CheckNhieu(){  // Toan Viet
    if( 
      Analog_ELEV_TB < ReceiverPermittedValue_MIN || Analog_ELEV_TB > ReceiverPermittedValue_MAX
      || Analog_ALIE_TB < ReceiverPermittedValue_MIN || Analog_ALIE_TB > ReceiverPermittedValue_MAX
      || RUDD < ReceiverPermittedValue_MIN || RUDD > ReceiverPermittedValue_MAX
      || GEAR < ReceiverPermittedValue_MIN || GEAR > ReceiverPermittedValue_MAX ){
      return 0 ;
    }else{
      return 1 ;
    }
}

void DEBUG(){
    lcd.clear() ;
    lcd.setCursor(0,0) ;
    lcd.print("ELEV");
    lcd.setCursor(5,0) ;
    lcd.print(Analog_ELEV_TB);
    
    lcd.setCursor(8,0) ;
    lcd.print("AILE");
    lcd.setCursor(13,0) ;
    lcd.print(Analog_ALIE_TB);
    
    lcd.setCursor(0,1) ;
    lcd.print("GEAR");
    lcd.setCursor(5,1) ;
    lcd.print(Analog_GEAR_TB);

    lcd.setCursor(8,1) ;
    lcd.print("RUDD");
    lcd.setCursor(13,1) ;
    lcd.print(Analog_RUDD_TB);
    
    Serial.print("ELEV: ") ;
    Serial.print(Analog_ELEV_TB) ;
    Serial.print("  ALIE: ") ;
    Serial.print(Analog_ALIE_TB) ;
    Serial.print("  GEAR: ") ;
    Serial.print(Analog_GEAR_TB) ;
    Serial.print("  RUDD: ") ;
    Serial.println(Analog_RUDD_TB) ;
}

void setup() 
{
  Serial.begin(9600);
  lcd.begin();
  // Using ATmega328 used in UNO => 16MHz CPU clock ,
  ITimer3.init();
  if (ITimer3.attachInterruptInterval(TIMER1_INTERVAL_MS, TimerHandler2ms, TIMER1_DURATION_MS))
    Serial.println("Starting  ITimer3 OK, millis() = " + String(millis()));
  else
    Serial.println("Can't set ITimer3. Select another freq., duration or timer"); 
 
  // khai bao IO PIN
  
     pinMode(LIMIT_LEN ,INPUT_PULLUP) ;
     pinMode(LIMIT_XUONG ,INPUT_PULLUP) ;
     
     pinMode(PWM1_TRAI, OUTPUT) ; 
     pinMode(PWM2_PHAI, OUTPUT) ; 
     pinMode(PWM3_ARM, OUTPUT) ; 
     pinMode(PWM4_XOAY, OUTPUT) ;
     
     pinMode(DIR1_TRAI, OUTPUT) ; 
     pinMode(DIR2_PHAI, OUTPUT) ; 
     pinMode(DIR3_ARM, OUTPUT) ; 
     pinMode(DIR4_XOAY, OUTPUT) ;
     
     analogWrite(PWM1_TRAI, 0) ;
     analogWrite(PWM2_PHAI, 0) ;
     analogWrite(PWM3_ARM,  0) ;  // Stop dong co nang ha 
     analogWrite(PWM4_XOAY, 0) ; 

     digitalWrite(DIR1_TRAI, 1) ;
     digitalWrite(DIR2_PHAI, 1) ;
     digitalWrite(DIR3_ARM, 1) ;
     digitalWrite(DIR4_XOAY, 1) ;
  
     pinMode(RELAY_CH1_BOM, OUTPUT) ;
     pinMode(RELAY_CH2, OUTPUT) ;
     pinMode(RELAY_CH3, OUTPUT) ;
     pinMode(RELAY_CH4, OUTPUT) ;
     
     digitalWrite(RELAY_CH1_BOM, 1);
     digitalWrite(RELAY_CH2, 1) ;
     digitalWrite(RELAY_CH3, 1) ;
     digitalWrite(RELAY_CH4, 1) ;

//     // Luc khoi dong robot, mac dinh la chua ket noi voi TX
     flag.MatSong = 1;
     flag.last_mat_song = flag.MatSong; 

     TimerDebug = millis() ; 
}


void loop() // Lui va re phai ve bi delay
{
  KiemTraLenhDieuKhien() ; 
  ThucThiLenhDieuKhien() ;
  task_check_tx_on_off() ;

  
  if ( (unsigned long) (millis() - TimerDebug) > 150 )
      {
        DEBUG() ;
        TimerDebug = millis() ;
      }
  
}
