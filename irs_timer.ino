
//ham xu ly loc ANALOG cac kenh ppm rx va ly nhieu khi tat bat TX
void TimerHandler2ms(void)
{
  //======================loc ADC, lay 10 mau trung binh cong 1 lan=============//
  if(Count< SamplingTime ) //2ms in 1 cycle
  {
    Analog_ELEV_Temp=Analog_ELEV_Temp+analogRead(ELEV);
    Analog_ALIE_Temp=Analog_ALIE_Temp+analogRead(AILE);
    Analog_GEAR_Temp=Analog_GEAR_Temp+analogRead(GEAR);
    Analog_RUDD_Temp=Analog_RUDD_Temp+analogRead(RUDD);
    Count++; 
  }
  else
  {
    Analog_ELEV_TB=Analog_ELEV_Temp/SamplingTime;
    Analog_ALIE_TB=Analog_ALIE_Temp/SamplingTime;
    Analog_GEAR_TB=Analog_GEAR_Temp/SamplingTime;
    Analog_RUDD_TB=Analog_RUDD_Temp/SamplingTime;
    Count=0;
    Analog_ELEV_Temp=0;
    Analog_ALIE_Temp=0;
    Analog_GEAR_Temp=0;
    Analog_RUDD_Temp=0;
  }
  
  //======================phat hien TX ON/ OFF vaf chong nhieu=============//
  //==============Khi TX on 0.5-1s thi moi cho phep dieu khien robot======//
  if(flag.phat_hien_nhieu==TRUE)
  {
    if(Count_dectect_noise++>=2000)
    {
      flag.enable_control=TRUE;  // cho phep dieu khien sau 1s
      flag.phat_hien_nhieu=FALSE; 
      Serial.println("DANG dax cho xong ngat");
      Serial.println(Count_dectect_noise);
      Count_dectect_noise=0;
    }
  }
  
}
