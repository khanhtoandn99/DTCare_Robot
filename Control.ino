

void KiemTraLenhDieuKhien(){     // Check Analog 
    //===================DIEU KHIEN TIEN LUI=======================///
  if( Analog_ELEV_TB > 65 && Analog_ELEV_TB <80) //tien
  { 
    flag.DangChayTien = 1 ;  
    flag.DangChayLui = 0 ;  
    flag.DangDungY = 0 ;  
    flag.MatSong = 0 ;  
  }
  else if ( Analog_ELEV_TB > 20 && Analog_ELEV_TB < 40 ) //LUI ( lag khi bat TX 39
  {
    flag.DangChayLui = 1 ;
    flag.DangChayTien = 0 ;
    flag.DangDungY =  0 ;
    flag.MatSong = 0; 
  }
  else if (Analog_ELEV_TB >= 40 && Analog_ELEV_TB <= 65) //DUNG
  {
    flag.DangDungY = 1 ; 
    flag.DangChayTien = 0 ;
    flag.DangChayLui = 0 ;
    flag.MatSong = 0; 
  }
  else
  {
     flag.MatSong = 1 ;
     flag.DangDungY = 0 ; 
     flag.DangChayLui = 0 ;
     flag.DangChayTien = 0 ;

     //dung ca ngoai vi ngay khi mat song
    RobotStop();
    DungNangHaBom(); 
    //stop bom
    TatBom() ;
  }

  //===================DIEU KHIEN TRAI PHAI========================///
  if( Analog_ALIE_TB > 65 && Analog_ALIE_TB < 80 ) //TRAI
  {
    flag.DangQuayTrai = 1 ;
    flag.DangQuayPhai = 0 ;
    flag.DangDungX = 0 ;
    flag.MatSong = 0 ; 
  }
  else if ((Analog_ALIE_TB>20)&&(Analog_ALIE_TB<40)) //PHAI( lag khi bat TX 39)
  {
     flag.DangQuayPhai = 1;
     flag.DangQuayTrai = 0 ;
     flag.DangDungX = 0 ;
     flag.MatSong = 0 ;
  }
  else if ((Analog_ALIE_TB>=40)&&(Analog_ALIE_TB<=65)) //dungY
  {
     flag.DangDungX = 1;
     flag.DangQuayPhai = 0 ;
     flag.DangQuayTrai = 0 ;
     flag.MatSong = 0 ;
  }
  else
  {
    flag.MatSong = 1 ;
    flag.DangDungX = 0 ;
    flag.DangQuayPhai = 0 ;
    flag.DangQuayTrai = 0 ;

    //dung ca ngoai vi ngay khi mat song
    RobotStop();
    DungNangHaBom(); 
    //stop bom
    TatBom() ;
    
  }


  //====================DIEU KHIEN CANH TAY NANG BOM==================//
  if(Analog_RUDD_TB > 65 && Analog_RUDD_TB <80) //len
  {
    flag.DangNangBom = 1 ;
    flag.DangHaBom = 0 ;
    flag.DangDungNangHaBom = 0 ;
    flag.MatSong = 0 ; 
  }
  else if (Analog_RUDD_TB > 20 && Analog_RUDD_TB < 40) //xuong( lag khi bat TX 39)
  {
     flag.DangHaBom = 1  ;
     flag.DangNangBom = 0 ;
     flag.DangDungNangHaBom = 0 ;
     flag.MatSong = 0 ;
  }
  else if ((Analog_RUDD_TB>=40)&&(Analog_RUDD_TB<=65)) //dungY
  {
     flag.DangDungNangHaBom = 1;
     flag.DangNangBom = 0 ;
     flag.DangHaBom = 0 ;
     flag.MatSong = 0 ;
  }
  else
  {
    flag.MatSong = 1 ; 
    flag.DangDungNangHaBom = 0 ;
    flag.DangNangBom = 0 ;
    flag.DangHaBom = 0 ;

    //dung ca ngoai vi ngay khi mat song
    RobotStop();
    DungNangHaBom(); 
    //stop bom
    TatBom() ;
  }

  //===================DIEU KHIEN BOM================================///
  if(Analog_GEAR_TB > 55 && Analog_GEAR_TB < 75 ) //BAT BOM
  {
    flag.DangBatBom = 1; 
  }
  //else((Analog_ALIE_TB >= 35)&&(Analog_ALIE_TB <= 55)) //TAT BOM O MOI TRUONG HOP
  else
  {
    flag.DangBatBom = 0 ; 
  }
}


//========================HAM KIEM TRA TX ON OR OFF DE CHONG NHIEU===============================//
//================================================================================================//
void task_check_tx_on_off(void) 
{
  if(flag.MatSong!=flag.last_mat_song)
  {
    flag.last_mat_song=flag.MatSong; //update trang thai on off cua tx
    flag.enable_control=FALSE;       // chua cho phep nguoi dung dieu khieu
    flag.phat_hien_nhieu=TRUE;      //dung ngat timer sau 0,5s-1s moi cho phep nguoi dung dieu khien
    Serial.println("tx change state");
  }
}


void ThucThiLenhDieuKhien(void)
{
 if(flag.enable_control==TRUE) // cho 1s sau khi tx on or off moi cho phep dieu khien
 {
  //============cac truong hop chay tien===============================// 
  //1.1 chay tien bang 2 banh.
  if((flag.DangChayTien == 1 )&&(flag.DangDungX == 1))
  {
    flag.DangChayTien = 0 ;
    flag.DangDungX = 0 ;
    //chay tien 2 dong co
    ChayTien();   // ToanCheck
    Serial.println("dang chay tien");
  }
  //1.2 chay tien dong thoi re phai.
  if((flag.DangChayTien == 1)&&(flag.DangQuayPhai == 1)){
    flag.DangChayTien = 0 ;
    flag.DangQuayPhai = 0 ;
    ChayTien_RePhai() ;
    Serial.println("Chay tien re phai");
  }
  //1.2 chay tien dong thoi re trai.
  if((flag.DangChayTien == 1)&&(flag.DangQuayTrai == 1)){
    flag.DangChayTien = 0 ;
    flag.DangQuayTrai = 0 ;
    ChayTien_ReTrai() ;
    Serial.println("Chay tien re trai");
  }
  //============cac truong hop chay lui===============================//
  //2.1 dong co chay lui bang 2 banh deu nhau
  if((flag.DangChayLui == 1 )&&(flag.DangDungX == 1))
  {
    flag.DangChayLui = 0;
    flag.DangDungX = 0;
    //chay lui ca 2 dong co
    ChayLui() ;
    Serial.println("lui");
  }
  //2.2 dong co chay lui dong thoi re phai
  if((flag.DangChayLui == 1 )&&(flag.DangQuayPhai == 1))
  {
    flag.DangChayLui = 0;
    flag.DangQuayPhai = 0;
    //chay lui ca 2 dong co
    ChayLui_RePhai() ;
    Serial.println("Chay lui re phai");
  }
  //2.3 dong co chay lui dong thoi re trai
  if((flag.DangChayLui == 1 )&&(flag.DangQuayTrai == 1))
  {
    flag.DangChayLui = 0;
    flag.DangQuayTrai = 0;
    //chay lui ca 2 dong co
    ChayLui_ReTrai() ;
    Serial.println("Chay lui re trai");
  }

  //============cac truong hop re trai===============================// 
  if((flag.DangQuayTrai == 1 )&&(flag.DangDungY == 1))
  {
    flag.DangQuayTrai =0 ;
    flag.DangDungY = 0 ;
    //stop motror
    // banh phai tien, banh trai lui
    QuayTrai() ;
    Serial.println("quay trai");
  }

 //============cac truong hop re phai===============================// 
  if((flag.DangQuayPhai == 1 )&&(flag.DangDungY == 1 ))
  {
    flag.DangQuayPhai = 0 ;
    flag.DangDungY = 0 ;
    //stop motror
    //banh trai tien, banh phai lui
    QuayPhai() ;
    Serial.println("quay phai");
  }

  //============truong hop can dung dong co===============================//
  if((flag.DangDungX == 1)&&(flag.DangDungY == 1))
  {
    flag.DangDungX = 0;
    flag.DangDungY = 0;
    RobotStop();
    //stop 2 dong co
    Serial.println("stop");
  }
  
  //============truong hop tay cam mat song hoac duoc tat dong co=========================//
  if(flag.MatSong == 1 )
  {
    flag.MatSong= 0 ;
    Serial.println("mat song or tat TX");
    //stop dong co
     RobotStop();
     DungNangHaBom(); 
    //stop bom
     TatBom() ;
  }

  //==================================DIEU KHIEN ARM CHO BOM===============================//
  if(flag.DangNangBom == 1 )  /// dieu khien tay len
  { 
    flag.DangNangBom = 0 ;
       NangBom() ;
  }
  
  if(flag.DangHaBom == 1 ) /// dieu khien tay xuong
  { 
    flag.DangHaBom = 0 ;
      HaBom();
  }

  if(flag.DangDungNangHaBom == 1)
  { 
    flag.DangDungNangHaBom = 0 ;
    //stop
    DungNangHaBom(); 
    Serial.println("Dung nang ha Bom");
  }
  //======================================================================================//
  //thieu mat song

  //==================================DIEU KHIEN ON OFF BOM===============================//
   if(flag.DangBatBom == 1 )
   {
     flag.DangBatBom = 0;
     // bat bom
     BatBom() ;
   }
   else
   {
     // tat bom
     TatBom() ;
   } 
  }
}
