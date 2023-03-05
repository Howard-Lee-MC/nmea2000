#include <Time.h>
#include <WiFi.h>
//#include <SoftwareSerial.h>
//SoftwareSerial gpsSerial(17,16);
//SoftwareSerial gpsSerial_out(6,5);


String str = "";
String str1 = "";
String targetStr1 = "GPRMC"; // GPS 좌표
String targetStr2 = "ERRPM"; // 엔진 RPM
String targetStr3 = "WIVWR"; // WIND 
String targetStr31 = "WIMWD"; // WIND ture
String targetStr4 = "HDT"; // compass
String targetStr_HDG = "HDG"; // compass
String targetStr5 = "HCHDM"; // compass
String targetStr6 = "TIROT"; // rate of turn
String targetStr_PFEC = "PFEC"; // pitch roll

String tx_date = "211206";
String tx_time = "000000";
String tx_time_old = "000000";
String tx_valid = "";
String tx_lat = "0";
String tx_lat_1 = "0";
String tx_lon = "0";
String tx_lon_1 = "0";
String tx_cog = "0";
String tx_sog = "0";
String tx_pitch ="0";
String tx_roll = "0";
String tx_heave = "0";
String tx_rpm_1 = "0";
String tx_rpm_2 = "0";
String tx_wind_hdg = "0";
String tx_wind_LR = "0";
String tx_wind_speed_knot ="0";
String tx_wind_ture = "0";
String tx_hdt = "0";
String tx_hdm = "0";
String tx_rot = "0";

String tx_rpm_no = "0";
String chk_eng_no_zero = "0";

const char* ssid       = "YOUR_SSID";
const char* password   = "YOUR_PASS";

const char* ntpServer = "pool.ntp.org";
uint8_t timeZone = 9;
uint8_t summerTime = 0; // 3600

void printLocalTime() {
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

//----------------------------------------------------------------

void setup() {
  Serial.begin(115200);     // debug display
  Serial1.begin(38400);     // input actisense output  Combined RPM data
  Serial2.begin(4800);      // furuno n2k-if
  //Serial3.begin(115200);    // Not used
  // while (!Serial) {    ;  }
  //setTime(00,00,00,01,01,23);   //setTime(hr, min, sec, day, month, year);
}

//----------------------------------------------------------------
void loop() {
            if (tx_time = "000000") { 
            tx_time = tx_time_old;
            tx_time_old = tx_time_old + 1;
            delay (1000); 
            }

            if (tx_time_old != tx_time ) {
          /*
              Serial2.print(tx_valid);
          Serial2.print(",");
          Serial2.print(tx_date);
          Serial2.print(",");
          Serial2.print(tx_time);
          Serial2.print(",");
          Serial2.print(tx_lat);
          Serial2.print(",");
          Serial2.print(tx_lat_1);
          Serial2.print(",");
          Serial2.print(tx_lon);
          Serial2.print(",");
          Serial2.print(tx_lon_1);
          Serial2.print(",");
          Serial2.print(tx_sog);
          Serial2.print(",");
          Serial2.print(tx_cog);
          Serial2.print(",");
          Serial2.print(tx_rpm_1);
          Serial2.print(",");
          Serial2.print(tx_rpm_2);
          Serial2.print(",");
          Serial2.print(tx_wind_hdg);
          Serial2.print(",");
          Serial2.print(tx_wind_LR);
          Serial2.print(",");
          Serial2.print(tx_wind_speed_knot);
          Serial2.print(",");
          Serial2.print(tx_wind_ture);          
          Serial2.print(",");
          Serial2.print(tx_hdt);
          Serial2.print(",");
          Serial2.print(tx_hdm);
          Serial2.print(",");
          Serial2.print(tx_rot);
          Serial2.print(",");
          Serial2.print(tx_heave);
          Serial2.print(","); 
          Serial2.print(tx_pitch);
          Serial2.print(","); 
          Serial2.print(tx_roll); 
          Serial2.println(","); 
          */
          
          Serial1.print(tx_valid);
          Serial1.print(",");
          Serial1.print(tx_date);
          Serial1.print(",");
          Serial1.print(tx_time);
          Serial1.print(",");
          Serial1.print(tx_lat);
          Serial1.print(",");
          Serial1.print(tx_lat_1);
          Serial1.print(",");
          Serial1.print(tx_lon);
          Serial1.print(",");
          Serial1.print(tx_lon_1);
          Serial1.print(",SOG,");
          Serial1.print(tx_sog);
          Serial1.print(",COG,");
          Serial1.print(tx_cog);
          Serial1.print(",RPM_1,");
          Serial1.print(tx_rpm_1);
          Serial1.print(",RPM_2,");
          Serial1.print(tx_rpm_2);
          Serial1.print(",W_HDG,");
          Serial1.print(tx_wind_hdg);
          Serial1.print(",LR,");
          Serial1.print(tx_wind_LR);
          Serial1.print(",W_Knot,");
          Serial1.print(tx_wind_speed_knot);
          Serial1.print(",W_Ture,");
          Serial1.print(tx_wind_ture);          
          Serial1.print(",HDT,");
          Serial1.print(tx_hdt);
          Serial1.print(",HDM,");
          Serial1.print(tx_hdm);
          Serial1.print(",ROT,");
          Serial1.print(tx_rot);
          //Serial1.print(",");
          //Serial1.print(tx_heave);
          Serial1.print(",Pitch,"); 
          Serial1.print(tx_pitch);
          Serial1.print(",Roll,"); 
          Serial1.print(tx_roll); 
          Serial1.println(",");
          
          
          Serial.print(tx_valid);
          Serial.print(",");
          Serial.print(tx_date);
          Serial.print(",");
          Serial.print(tx_time);
          Serial.print(",");
          Serial.print(tx_lat);
          Serial.print(",");
          Serial.print(tx_lat_1);
          Serial.print(",");
          Serial.print(tx_lon);
          Serial.print(",");
          Serial.print(tx_lon_1);
          Serial.print(",SOG,");
          Serial.print(tx_sog);
          Serial.print(",COG,");
          Serial.print(tx_cog);
          Serial.print(",RPM_1,");
          Serial.print(tx_rpm_1);
          Serial.print(",RPM_2,");
          Serial.print(tx_rpm_2);
          Serial.print(",W_HDG,");
          Serial.print(tx_wind_hdg);
          Serial.print(",LR,");
          Serial.print(tx_wind_LR);
          Serial.print(",W_Knot,");
          Serial.print(tx_wind_speed_knot);
          Serial.print(",W_Ture,");
          Serial.print(tx_wind_ture);          
          Serial.print(",HDT,");
          Serial.print(tx_hdt);
          Serial.print(",HDM,");
          Serial.print(tx_hdm);
          Serial.print(",ROT,");
          Serial.print(tx_rot);
          //Serial1.print(",");
          //Serial1.print(tx_heave);
          Serial.print(",Pitch,"); 
          Serial.print(tx_pitch);
          Serial.print(",Roll,"); 
          Serial.print(tx_roll); 
          Serial.print(",");
          Serial.println("end");
          
          tx_time_old = tx_time;
          }
          
          /*    
          tx_date = "211206";
          tx_time = "000000";
          tx_valid = "0";
          tx_lat = "0";
          tx_lat_1 = "0";
          tx_lon = "0";
          tx_lon_1 = "0";
          tx_cog = "0";
          tx_sog = "0";
          tx_rpm_1 = "0";
          tx_rpm_2 = "0";
          tx_wind_hdg = "0";
          tx_wind_LR = "0";
          tx_wind_speed_knot ="0";
          tx_wind_ture = "0";
          tx_hdt = "0";
          tx_hdm = "0";
          tx_rot = "0";
          */
          
}

//----------------------------------------------------------------
void serialEvent1() {

  if(Serial1.available())
    {
      char c = Serial1.read();
    
      if(c == '\n'){
          //
          Serial2.println(str); // 수신원본 출력 serial 2
          Serial.println(str);
//-----------------------------------------------------------------------------   
//       GPS GPRMC
//-----------------------------------------------------------------------------   
        if(targetStr1.equals(str.substring(1, 6))){
          //Serial3.println(str); 
          int first = str.indexOf(",");
          int two = str.indexOf(",", first+1);
          int three = str.indexOf(",", two+1);
          int four = str.indexOf(",", three+1);
          int five = str.indexOf(",", four+1);
          int six = str.indexOf(",", five+1);
          int seven = str.indexOf(",", six+1);
          int eight = str.indexOf(",", seven+1);
          int nine = str.indexOf(",", eight+1);
          int ten = str.indexOf(",", nine+1);
          tx_time = str.substring(first+1, two);
          tx_valid = str.substring(two+1, three);
          tx_lat = str.substring(three+1, four);
          tx_lat_1 = str.substring(four+1, five);
          tx_lon = str.substring(five+1, six);
          tx_lon_1 = str.substring(six+1, seven);
          tx_sog = str.substring(seven+1, eight);
          tx_cog = str.substring(eight+1, nine);
          tx_date = str.substring(nine+1, ten);


          
          }

//-----------------------------------------------------------------------------    
//        wind WIMWD ture
//-----------------------------------------------------------------------------   
          else if (targetStr31.equals(str.substring(1, 6))){
          //Serial.println(str);
          
          int first = str.indexOf(",");
          int two = str.indexOf(",", first+1);
          //int three = str.indexOf(",", two+1);
          //int four = str.indexOf(",", three+1);
          //int five = str.indexOf(",", four+1);
          //int six = str.indexOf(",", five+1);
          //int seven = str.indexOf(",", six+1);
          //int eight = str.indexOf(",", seven+1);
          //int nine = str.indexOf(",", eight+1);
          tx_wind_ture = str.substring(first+1, two);
        }
        
//-----------------------------------------------------------------------------    
//        wind WIVWR
//-----------------------------------------------------------------------------   
          else if(targetStr3.equals(str.substring(1, 6))){
          //Serial.println(str);
          
          int first = str.indexOf(",");
          int two = str.indexOf(",", first+1);
          int three = str.indexOf(",", two+1);
          int four = str.indexOf(",", three+1);
          //int five = str.indexOf(",", four+1);
          //int six = str.indexOf(",", five+1);
          //int seven = str.indexOf(",", six+1);
          //int eight = str.indexOf(",", seven+1);
          //int nine = str.indexOf(",", eight+1);
          tx_wind_hdg = str.substring(first+1, two);
          tx_wind_LR = str.substring(two+1, three);
          tx_wind_speed_knot = str.substring(three+1, four);
        }
             

        
//----------------------------------------------------------------------------- 
//        engine rpm
//-----------------------------------------------------------------------------      
          else if(targetStr2.equals(str.substring(1, 6))){
          //Serial.println(str);
          
          int first = str.indexOf(",");
          int two = str.indexOf(",", first+1);
          int three = str.indexOf(",", two+1);
          int four = str.indexOf(",", three+1);
          //int five = str.indexOf(",", four+1);
          //int six = str.indexOf(",", five+1);
          //int seven = str.indexOf(",", six+1);
          //int eight = str.indexOf(",", seven+1);
          //int nine = str.indexOf(",", eight+1);
          tx_rpm_no = str.substring(two+1, three);
          
          if ( tx_rpm_no == chk_eng_no_zero ) { tx_rpm_1 = str.substring(three+1, four); }
          else { tx_rpm_2 = str.substring(three+1, four); }
        }
        
//-----------------------------------------------------------------------------   
//        HDM
//-----------------------------------------------------------------------------     
          else if(targetStr5.equals(str.substring(1, 6))){
          //Serial.println(str);
          
          int first = str.indexOf(",");
          int two = str.indexOf(",", first+1);
          //int three = str.indexOf(",", two+1);
          //int four = str.indexOf(",", three+1);
          //int five = str.indexOf(",", four+1);
          //int six = str.indexOf(",", five+1);
          //int seven = str.indexOf(",", six+1);
          //int eight = str.indexOf(",", seven+1);
          //int nine = str.indexOf(",", eight+1);
          tx_hdm = str.substring(first+1, two);          
        }
//-----------------------------------------------------------------------------   
//       ROT
//-----------------------------------------------------------------------------     
          else if(targetStr6.equals(str.substring(1, 6))){
          //Serial.println(str);
          
          int first = str.indexOf(",");
          int two = str.indexOf(",", first+1);
          //int three = str.indexOf(",", two+1);
          //int four = str.indexOf(",", three+1);
          //int five = str.indexOf(",", four+1);
          //int six = str.indexOf(",", five+1);
          //int seven = str.indexOf(",", six+1);
          //int eight = str.indexOf(",", seven+1);
          //int nine = str.indexOf(",", eight+1);
          tx_rot = str.substring(first+1, two); 

/*
          Serial.print(tx_valid);
          Serial.print(",");
          Serial.print(tx_date);
          Serial.print(",");
          Serial.print(tx_time);
          Serial.print(",");
          Serial.print(tx_lat);
          Serial.print(",");
          Serial.print(tx_lat_1);
          Serial.print(",");
          Serial.print(tx_lon);
          Serial.print(",");
          Serial.print(tx_lon_1);
          Serial.print(",");
          Serial.print(tx_sog);
          Serial.print(",");
          Serial.print(tx_cog);
          Serial.print(",RPM1,");
          Serial.print(tx_rpm_1);
          Serial.print(",RPM2,");
          Serial.print(tx_rpm_2);
          Serial.print(",");
          Serial.print(tx_wind_hdg);
          Serial.print(",");
          Serial.print(tx_wind_LR);
          Serial.print(",");
          Serial.print(tx_wind_speed_knot);
          Serial.print(",");
          Serial.print(tx_wind_ture);          
          Serial.print(",");
          Serial.print(tx_hdt);
          Serial.print(",");
          Serial.print(tx_hdm);
          Serial.print(",");
          Serial.print(tx_rot);
          Serial.print(",");
          Serial.print(tx_heave);
          Serial.print(","); 
          Serial.print(tx_pitch);
          Serial.print(","); 
          Serial.print(tx_roll); 
          Serial.println(",");
*/          

          
        }



//-----------------------------------------------------------------------------     
        str = "";
        
      } else{
        str += c;
      }
   }
}

//----------------------------------------------------------------
void serialEvent2() {

  if(Serial2.available())
    {
      char c1=Serial2.read();
      if(c1 == '\n'){

         Serial2.println(str1);   // 수신원본 출력 serial 2
         Serial.println(str);
//-----------------------------------------------------------------------------   
//        PFEC 
//-----------------------------------------------------------------------------   
         if(targetStr_PFEC.equals(str1.substring(1, 5))){
          int first = str1.indexOf(",");
          int two = str1.indexOf(",", first+1);
          int three = str1.indexOf(",", two+1);
          int four = str1.indexOf(",", three+1);
          int five = str1.indexOf("*", four+1);
          //int six = str1.indexOf(",", five+1);
          //int seven = str.indexOf(",", six+1);
          //int eight = str.indexOf(",", seven+1);
          //int nine = str.indexOf(",", eight+1);
          //int ten = str.indexOf(",", nine+1);
          tx_heave = str1.substring(two+1, three);
          tx_pitch = str1.substring(three+1, four);
          tx_roll = str1.substring(four+1, five);  
      }
      
//-----------------------------------------------------------------------------   
//        HDG 로 HDT 계산 = HDM - variation
//-----------------------------------------------------------------------------     
          else if (targetStr_HDG.equals(str1.substring(3, 6))){
          //Serial.println(str1);
          
          int first = str1.indexOf(",");
          int two = str1.indexOf(",", first+1);
          int three = str1.indexOf(",", two+1);
          int four = str1.indexOf(",", three+1);
          int five = str1.indexOf(",", four+1);
          int six = str1.indexOf(",", five+1);
          //int seven = str.indexOf(",", six+1);
          //int eight = str.indexOf(",", seven+1);
          //int nine = str.indexOf(",", eight+1);

          String tx_temp_hdg_s = str1.substring(first+1, two);  
          float tx_temp_hdg = tx_temp_hdg_s.toFloat();
          String tx_temp_var_s = str1.substring(four+1, five);  
          float tx_temp_var = tx_temp_var_s.toFloat();
          tx_hdt = tx_temp_hdg - tx_temp_var;          
        }
        str1 = "";
        
      } else{
        str1 += c1;
      }
   }
}
