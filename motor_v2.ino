
void ChayTien(){
    // Kiem tra xem robot co dang chay theo chieu nguoc lai khong, neu vay, phai dung roi moi cho phep dao chieu
    if( dangChayLui == 1 ) {     
      while(Accelerate_TRAI > 0 || Accelerate_PHAI > 0){
        Accelerate_TRAI = Accelerate_TRAI - Accelerate_TRAI_Decrease_Level ;
        Accelerate_PHAI = Accelerate_PHAI - Accelerate_PHAI_Decrease_Level ;
        if(Accelerate_TRAI < 0 ) Accelerate_TRAI = 0 ; 
        if(Accelerate_PHAI < 0 ) Accelerate_PHAI = 0 ;
        analogWrite(PWM1_TRAI, Accelerate_TRAI) ; 
        analogWrite(PWM2_PHAI, Accelerate_PHAI) ; 
        delay(5) ;
      }
    }
    // Bat dau tang toc dan dan ====> on dinh toc do khi chay tien
    if( Accelerate_TRAI < Motor_TRAI_MAX_SPEED ){ Accelerate_TRAI = Accelerate_TRAI + Accelerate_TRAI_Increase_Level ; }
    if( Accelerate_TRAI >= Motor_TRAI_MAX_SPEED ){ Accelerate_TRAI = Motor_TRAI_MAX_SPEED ; }
    
    if( Accelerate_PHAI < Motor_PHAI_MAX_SPEED ){ Accelerate_PHAI = Accelerate_PHAI + Accelerate_PHAI_Increase_Level ; } 
    if( Accelerate_PHAI >= Motor_PHAI_MAX_SPEED ){ Accelerate_PHAI = Motor_PHAI_MAX_SPEED ; } 
    
    digitalWrite(DIR1_TRAI, 0) ; 
    digitalWrite(DIR2_PHAI, 0) ;
    analogWrite(PWM1_TRAI, Accelerate_TRAI) ; 
    analogWrite(PWM2_PHAI, Accelerate_PHAI) ;
    delay(5) ;
    dangChayTien = 1 ; 
    dangChayLui = 0 ; 
}


void ChayLui(){
    // Kiem tra xem robot co dang chay theo chieu nguoc lai khong, neu vay, phai dung roi moi cho phep dao chieu
    if( dangChayTien == 1 ) {     
      while(Accelerate_TRAI > 0 || Accelerate_PHAI > 0){
        Accelerate_TRAI = Accelerate_TRAI - Accelerate_TRAI_Decrease_Level ;
        Accelerate_PHAI = Accelerate_PHAI - Accelerate_PHAI_Decrease_Level ;
        if(Accelerate_TRAI < 0 ) Accelerate_TRAI = 0 ; 
        if(Accelerate_PHAI < 0 ) Accelerate_PHAI = 0 ;
        analogWrite(PWM1_TRAI, Accelerate_TRAI) ; 
        analogWrite(PWM2_PHAI, Accelerate_PHAI) ; 
        delay(5) ;
      }
    }
    // Bat dau tang toc dan dan ====> on dinh toc do khi chay lui
    if( Accelerate_TRAI < Motor_TRAI_MAX_SPEED_Lui ){ Accelerate_TRAI = Accelerate_TRAI + Accelerate_TRAI_Increase_Level ; }
    if( Accelerate_TRAI >= Motor_TRAI_MAX_SPEED_Lui ){ Accelerate_TRAI = Motor_TRAI_MAX_SPEED_Lui ; }
    
    if( Accelerate_PHAI < Motor_PHAI_MAX_SPEED_Lui ){ Accelerate_PHAI = Accelerate_PHAI + Accelerate_PHAI_Increase_Level ; } 
    if( Accelerate_PHAI >= Motor_PHAI_MAX_SPEED_Lui ){ Accelerate_PHAI = Motor_PHAI_MAX_SPEED_Lui ; } 
    
    digitalWrite(DIR1_TRAI, 1) ; 
    digitalWrite(DIR2_PHAI, 1) ;
    analogWrite(PWM1_TRAI, Accelerate_TRAI) ; 
    analogWrite(PWM2_PHAI, Accelerate_PHAI) ;
    delay(5) ;
    dangChayLui = 1 ; 
    dangChayTien = 0 ; 
}


void RobotStop(){
    if( Accelerate_TRAI > 0 ) Accelerate_TRAI = Accelerate_TRAI - Accelerate_TRAI_Decrease_Level ;
    if( Accelerate_TRAI < 0 ) Accelerate_TRAI = 0 ;
     
    if( Accelerate_PHAI > 0 ) Accelerate_PHAI = Accelerate_PHAI - Accelerate_PHAI_Decrease_Level ; 
    if( Accelerate_PHAI < 0 ) Accelerate_PHAI = 0 ; 
    
    analogWrite(PWM1_TRAI, Accelerate_TRAI) ;
    analogWrite(PWM2_PHAI, Accelerate_PHAI) ;
    dangChayLui = 0 ; 
    dangChayTien = 0 ;  
    delay(5) ;
}

// Phai check dem la no dang tien hay dang lui 

void QuayPhai(){
    // Kiem tra xem robot co dang chay khong, neu vay, phai dung roi moi cho phep chuyen huong
    if( dangChayLui == 1 || dangChayTien == 1 ) {     
      while(Accelerate_TRAI > 0 || Accelerate_PHAI > 0){
        Accelerate_TRAI = Accelerate_TRAI - Accelerate_TRAI_Decrease_Level ;
        Accelerate_PHAI = Accelerate_PHAI - Accelerate_PHAI_Decrease_Level ;
        if(Accelerate_TRAI < 0 ) Accelerate_TRAI = 0 ; 
        if(Accelerate_PHAI < 0 ) Accelerate_PHAI = 0 ;
        analogWrite(PWM1_TRAI, Accelerate_TRAI) ; 
        analogWrite(PWM2_PHAI, Accelerate_PHAI) ; 
        delay(5) ;
      }
    }  
    digitalWrite(DIR1_TRAI, 0) ;
    digitalWrite(DIR2_PHAI, 1) ;
    analogWrite(PWM1_TRAI, Motor_TRAI_MAX_SPEED_When_turn_left) ;  
    analogWrite(PWM2_PHAI, Motor_PHAI_MAX_SPEED_When_turn_right) ;
    delay(5) ;
    dangChayTien = 0 ; 
    dangChayLui = 0 ; 
}

void QuayTrai(){
    // Kiem tra xem robot co dang chay khong, neu vay, phai dung roi moi cho phep chuyen huong
    if( dangChayLui == 1 || dangChayTien == 1 ) {     // Giam toc do ve 0 khi nghe dao chieu
      while(Accelerate_TRAI > 0 || Accelerate_PHAI > 0){
        Accelerate_TRAI = Accelerate_TRAI - Accelerate_TRAI_Decrease_Level ;
        Accelerate_PHAI = Accelerate_PHAI - Accelerate_PHAI_Decrease_Level ;
        if(Accelerate_TRAI < 0 ) Accelerate_TRAI = 0 ; 
        if(Accelerate_PHAI < 0 ) Accelerate_PHAI = 0 ;
        analogWrite(PWM1_TRAI, Accelerate_TRAI) ; 
        analogWrite(PWM2_PHAI, Accelerate_PHAI) ; 
        delay(5) ;
      }
    }  
    digitalWrite(DIR1_TRAI, 1) ;
    digitalWrite(DIR2_PHAI, 0) ;
    analogWrite(PWM1_TRAI, Motor_TRAI_MAX_SPEED_When_turn_left) ;  
    analogWrite(PWM2_PHAI, Motor_PHAI_MAX_SPEED_When_turn_right) ;
    delay(5) ;
    dangChayTien = 0 ; 
    dangChayLui = 0 ;  
}


void ChayTien_RePhai(){  // => Dong co PHAI phai chay cham hon dong co TRAI
    // Kiem tra xem robot co dang chay theo chieu nguoc lai khong, neu vay, phai dung roi moi cho phep dao chieu
    if( dangChayLui == 1 ) {     // Giam toc do ve 0 khi nghe dao chieu
      while(Accelerate_TRAI > 0 || Accelerate_PHAI > 0){
        Accelerate_TRAI = Accelerate_TRAI - Accelerate_TRAI_Decrease_Level ;
        Accelerate_PHAI = Accelerate_PHAI - Accelerate_PHAI_Decrease_Level ;
        if(Accelerate_TRAI < 0 ) Accelerate_TRAI = 0 ; 
        if(Accelerate_PHAI < 0 ) Accelerate_PHAI = 0 ;
        analogWrite(PWM1_TRAI, Accelerate_TRAI) ; 
        analogWrite(PWM2_PHAI, Accelerate_PHAI) ; 
        delay(5) ;
      }
    } 
    // Toc do cua dong co PHAI khi chay thang re phai la "Motor_PHAI_MAX_SPEED_When_turn_right"
    if( Accelerate_TRAI < Motor_TRAI_MAX_SPEED ){ Accelerate_TRAI = Accelerate_TRAI + Accelerate_TRAI_Increase_Level ; }
    if( Accelerate_TRAI >= Motor_TRAI_MAX_SPEED ){ Accelerate_TRAI = Motor_TRAI_MAX_SPEED ; }
    
    if( Accelerate_PHAI > Motor_PHAI_MAX_SPEED_When_turn_right ){ Accelerate_PHAI = Accelerate_PHAI - Accelerate_PHAI_Decrease_Level ; } 
    if( Accelerate_PHAI <= Motor_PHAI_MAX_SPEED_When_turn_right ){ Accelerate_PHAI = Motor_PHAI_MAX_SPEED_When_turn_right ; } 
    
    digitalWrite(DIR1_TRAI, 0) ; 
    digitalWrite(DIR2_PHAI, 0) ;
    analogWrite(PWM1_TRAI, Accelerate_TRAI) ; 
    analogWrite(PWM2_PHAI, Accelerate_PHAI) ;
    delay(5) ;
    dangChayTien = 1 ; 
    dangChayLui = 0 ;   
}


void ChayTien_ReTrai(){  // => Dong co TRAI phai chay cham hon dong co PHAI
    // Kiem tra xem robot co dang chay theo chieu nguoc lai khong, neu vay, phai dung roi moi cho phep dao chieu
    if( dangChayLui == 1 ) {     // Giam toc do ve 0 khi nghe dao chieu
      while(Accelerate_TRAI > 0 || Accelerate_PHAI > 0){
        Accelerate_TRAI = Accelerate_TRAI - Accelerate_TRAI_Decrease_Level ;
        Accelerate_PHAI = Accelerate_PHAI - Accelerate_PHAI_Decrease_Level ;
        if(Accelerate_TRAI < 0 ) Accelerate_TRAI = 0 ; 
        if(Accelerate_PHAI < 0 ) Accelerate_PHAI = 0 ;
        analogWrite(PWM1_TRAI, Accelerate_TRAI) ; 
        analogWrite(PWM2_PHAI, Accelerate_PHAI) ; 
        delay(5) ;
      }
    } 
    // Toc do cua dong co TRAI khi chay thang re trai la "Motor_PHAI_MAX_SPEED_When_turn_left"
    if( Accelerate_TRAI > Motor_TRAI_MAX_SPEED_When_turn_left ){ Accelerate_TRAI = Accelerate_TRAI - Accelerate_TRAI_Decrease_Level ; } 
    if( Accelerate_TRAI <= Motor_TRAI_MAX_SPEED_When_turn_left ){ Accelerate_TRAI = Motor_TRAI_MAX_SPEED_When_turn_left ; }              
    
    if( Accelerate_PHAI < Motor_PHAI_MAX_SPEED ){ Accelerate_PHAI = Accelerate_PHAI + Accelerate_PHAI_Increase_Level ; }
    if( Accelerate_PHAI >= Motor_PHAI_MAX_SPEED ){ Accelerate_PHAI = Motor_PHAI_MAX_SPEED ; } 
    digitalWrite(DIR1_TRAI, 0) ; 
    digitalWrite(DIR2_PHAI, 0) ;
    analogWrite(PWM1_TRAI, Accelerate_TRAI) ; 
    analogWrite(PWM2_PHAI, Accelerate_PHAI) ;
    delay(5) ;
    dangChayTien = 1 ; 
    dangChayLui = 0 ;   
}


void ChayLui_RePhai(){  // => Dong co PHAI phai chay cham hon dong co TRAI
    // Kiem tra xem robot co dang chay theo chieu nguoc lai khong, neu vay, phai dung roi moi cho phep dao chieu
    if( dangChayTien == 1 ) {     
      while(Accelerate_TRAI > 0 || Accelerate_PHAI > 0){
        Accelerate_TRAI = Accelerate_TRAI - Accelerate_TRAI_Decrease_Level ;
        Accelerate_PHAI = Accelerate_PHAI - Accelerate_PHAI_Decrease_Level ;
        if(Accelerate_TRAI < 0 ) Accelerate_TRAI = 0 ; 
        if(Accelerate_PHAI < 0 ) Accelerate_PHAI = 0 ;
        analogWrite(PWM1_TRAI, Accelerate_TRAI) ; 
        analogWrite(PWM2_PHAI, Accelerate_PHAI) ; 
        delay(5) ;
      }
    } 
    // Toc do cua dong co PHAI khi chay thang re phai la "Motor_PHAI_MAX_SPEED_When_turn_right"
    if( Accelerate_TRAI < Motor_TRAI_MAX_SPEED ){ Accelerate_TRAI = Accelerate_TRAI + Accelerate_TRAI_Increase_Level ; }
    if( Accelerate_TRAI >= Motor_TRAI_MAX_SPEED ){ Accelerate_TRAI = Motor_TRAI_MAX_SPEED ; }
    
    if( Accelerate_PHAI > Motor_PHAI_MAX_SPEED_When_turn_right ){ Accelerate_PHAI = Accelerate_PHAI - Accelerate_PHAI_Decrease_Level ; } 
    if( Accelerate_PHAI <= Motor_PHAI_MAX_SPEED_When_turn_right ){ Accelerate_PHAI = Motor_PHAI_MAX_SPEED_When_turn_right ; } 
    
    digitalWrite(DIR1_TRAI, 1) ; 
    digitalWrite(DIR2_PHAI, 1) ;
    analogWrite(PWM1_TRAI, Accelerate_TRAI) ; 
    analogWrite(PWM2_PHAI, Accelerate_PHAI) ;
    delay(5) ;
    dangChayLui = 1 ; 
    dangChayTien = 0 ;   
}


void ChayLui_ReTrai(){  // => Dong co TRAI phai chay cham hon dong co PHAI
    // Kiem tra xem robot co dang chay theo chieu nguoc lai khong, neu vay, phai dung roi moi cho phep dao chieu
    if( dangChayTien == 1 ) {     
      while(Accelerate_TRAI > 0 || Accelerate_PHAI > 0){
        Accelerate_TRAI = Accelerate_TRAI - Accelerate_TRAI_Decrease_Level ;
        Accelerate_PHAI = Accelerate_PHAI - Accelerate_PHAI_Decrease_Level ;
        if(Accelerate_TRAI < 0 ) Accelerate_TRAI = 0 ; 
        if(Accelerate_PHAI < 0 ) Accelerate_PHAI = 0 ;
        analogWrite(PWM1_TRAI, Accelerate_TRAI) ; 
        analogWrite(PWM2_PHAI, Accelerate_PHAI) ; 
        delay(5) ;
      }
    } 
    // Toc do cua dong co TRAI khi chay thang re trai la "Motor_PHAI_MAX_SPEED_When_turn_left"
    if( Accelerate_TRAI > Motor_TRAI_MAX_SPEED_When_turn_left ){ Accelerate_TRAI = Accelerate_TRAI - Accelerate_TRAI_Decrease_Level ; } 
    if( Accelerate_TRAI <= Motor_TRAI_MAX_SPEED_When_turn_left ){ Accelerate_TRAI = Motor_TRAI_MAX_SPEED_When_turn_left ; }              
    
    if( Accelerate_PHAI < Motor_PHAI_MAX_SPEED ){ Accelerate_PHAI = Accelerate_PHAI + Accelerate_PHAI_Increase_Level ; }
    if( Accelerate_PHAI >= Motor_PHAI_MAX_SPEED ){ Accelerate_PHAI = Motor_PHAI_MAX_SPEED ; } 
    digitalWrite(DIR1_TRAI, 1) ; 
    digitalWrite(DIR2_PHAI, 1) ;
    analogWrite(PWM1_TRAI, Accelerate_TRAI) ; 
    analogWrite(PWM2_PHAI, Accelerate_PHAI) ;
    delay(5) ;
    dangChayLui = 1 ; 
    dangChayTien = 0 ; 
}

void  NangBom() {
    digitalWrite(DIR3_ARM, 0) ; 
    analogWrite(PWM3_ARM, 255) ; 

}

void  HaBom() {
    digitalWrite(DIR3_ARM, 1) ; 
    analogWrite(PWM3_ARM, 255) ; 
}

void DungNangHaBom(){
    analogWrite(PWM3_ARM, 0) ; 
}

void BatBom() {
     digitalWrite(RELAY_CH1_BOM, 0);
     digitalWrite(RELAY_CH2, 0);
     digitalWrite(RELAY_CH3, 0);
     digitalWrite(RELAY_CH4, 0);
}

void TatBom() {
     digitalWrite(RELAY_CH1_BOM, 1);
     digitalWrite(RELAY_CH2, 1);
     digitalWrite(RELAY_CH3, 1);
     digitalWrite(RELAY_CH4, 1);
}
