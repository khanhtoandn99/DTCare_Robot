
///////////////////////////////////////////////////////////////////
#define TIMER_INTERRUPT_DEBUG      0
#define USE_TIMER_1     false
#define USE_TIMER_2     false
#define USE_TIMER_3     true
#define USE_TIMER_4     false
#define USE_TIMER_5     false

#define TIMER1_INTERVAL_MS    2 
#define TIMER1_FREQUENCY      (float) (1000.0f / TIMER1_INTERVAL_MS)
#define TIMER1_DURATION_MS    0 //(10 * TIMER1_INTERVAL_MS)

#include "TimerInterrupt.h"

////////////////////////////////////////////////////////////////////
#define ON  1
#define OFF 0

#define TRUE  1
#define FALSE 0

#define ELEV A0
#define AILE A1
#define RUDD A2
#define GEAR A3

extern volatile int Analog_ELEV_TB ;
extern volatile int Analog_ALIE_TB ;
extern volatile int Analog_GEAR_TB ;
extern volatile int Analog_RUDD_TB ;

extern volatile int Analog_ELEV_Temp;
extern volatile int Analog_ALIE_Temp;
extern volatile int Analog_GEAR_Temp;
extern volatile int Analog_RUDD_Temp;

extern volatile int Count;
extern volatile int Count_dectect_noise;
extern volatile int Count_check_state_TX;
 


#define PWM1_TRAI     4    // Dong co TRAI : DO-xanh duong, den-xanh la cay , DO ben trai, nhin tu driver nhin ra motor 
#define DIR1_TRAI     5

#define PWM2_PHAI     8
#define DIR2_PHAI     9
 
#define PWM3_ARM      6    // 255 la chay
#define DIR3_ARM      7     // 0 : Nguoc chieu kim dong ho 

#define PWM4_XOAY     2
#define DIR4_XOAY     3

#define RELAY_CH1_BOM 14
#define RELAY_CH2     15
#define RELAY_CH3     16
#define RELAY_CH4     17

#define LIMIT_LEN     47
#define LIMIT_XUONG   49

// Lay gia tri cho ADC
unsigned int SamplingTime  = 20 ;  // so lan lay mau 


 volatile int Analog_ELEV_TB=0 ;
 volatile int Analog_ALIE_TB=0;
 volatile int Analog_GEAR_TB=0;
 volatile int Analog_RUDD_TB=0 ;
 
 volatile int Analog_ELEV_Temp=0;
 volatile int Analog_ALIE_Temp=0;
 volatile int Analog_GEAR_Temp=0;
 volatile int Analog_RUDD_Temp=0;
 
 volatile int Count=0 ;
 volatile int Count_dectect_noise=0;
 volatile int Count_check_state_TX=0;

 void TimerHandler2ms(void) ;

//--------------------------------------------------- 
#define ReceiverPermittedValue_MIN  34
#define ReceiverPermittedValue_MAX  73

//==================MOTOR============================// 
struct FLAG {
  bool DangChayTien = 0 ; 
  bool DangChayLui = 0 ;
  bool DangDungY = 0 ;
  
  bool DangQuayTrai = 0 ;
  bool DangQuayPhai = 0 ;
  bool DangDungX = 0 ;

  bool DangNangBom = 0 ;
  bool DangHaBom = 0 ;
  bool DangDungNangHaBom = 0 ;

  bool DangBatBom = 0 ;

  bool MatSong = 0 ;
  bool last_mat_song;
  bool phat_hien_nhieu;
  bool enable_control;  
} ;

int Accelerate = 0 ;
bool dangChayTien = 0 ; 
bool dangChayLui = 0 ;
bool dangQuayTrai = 0 ; 
bool dangQuayPhai = 0 ;

//=======================DIEU CHINH CAC THONG SO KHI DIEU KHIEN DONG CO NGAY TAI DAY ============================//
//========================== Toc do dong co TRAI nhanh hon toc do dong co PHAI ===========================//
int Accelerate_TRAI = 0 ;                          // Toc do hien tai cua dong co TRAI
int Accelerate_PHAI = 0 ;                          // Toc do hien tai cua dong co PHAI
int Motor_TRAI_MAX_SPEED = 190 ;                   // Toc do toi da cua dong co PHAI  0->255
int Motor_PHAI_MAX_SPEED = 190 ;                   // Toc do toi da cua dong co TRAI  0->255
int Motor_TRAI_MAX_SPEED_Lui = 140 ;               // Toc do toi da cua dong co PHAI  0->255
int Motor_PHAI_MAX_SPEED_Lui = 140 ;               // Toc do toi da cua dong co TRAI  0->255

//==== Luu Y, muc tang toc do phai > hon muc giam toc do, neu khong robot se khong chay
int Accelerate_TRAI_Increase_Level = 20 ;          // Muc tang toc do cua dong co TRAI  ( STEP )       
int Accelerate_PHAI_Increase_Level = 20 ;          // Muc tang toc do cua dong co PHAI  ( STEP )

int Accelerate_TRAI_Decrease_Level = 15 ;          // Muc giam toc do cua dong co TRAI  ( STEP )
int Accelerate_PHAI_Decrease_Level = 15 ;          // Muc giam toc do cua dong co PHAI  ( STEP )

int Motor_TRAI_MAX_SPEED_When_turn_left = 125 ;    // toc do cua dong co TRAI khi dang chay thang re trai 0->255
int Motor_PHAI_MAX_SPEED_When_turn_right = 125 ;   // toc do cua dong co PHAI khi dang chay thang re phai 0->255
//===============================================================================================================//

//===================Control Motor Function=======================//
void KiemTraLenhDieuKhien() ; 
void ThucThiLenhDieuKhien(void) ; 
void TimerHandler2ms(void) ;

void ChayTien() ; 
void ChayLui() ; 
void QuayTrai() ; 
void QuayPhai() ; 
void ChayLui_RePhai() ; 
void ChayLui_ReTrai() ; 
void ChayTien_RePhai() ; 
void ChayTien_ReTrai() ; 
void RobotStop() ;  
void NangBom() ;  
void HaBom() ; 
void DungNangHaBom() ; 
void BatBom() ; 
void TatBom() ; 

bool CheckNhieu() ; 
void DEBUG() ; 
